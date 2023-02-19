#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include "globals.h"

#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <QScrollBar>
#include <QDoubleSpinBox>
#include <QFrame>

static uint8_t chksum_error_rx = 0;
static uint8_t chksum_error_tx = 0;
static uint16_t id = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_status_label_1(new QLabel),
    m_status_label_2(new QLabel),
    m_status_label_3(new QLabel),
    m_status_label_4(new QLabel),
    m_status_label_5(new QLabel),
    m_settings(new SettingsDialog),
    m_serial(new QSerialPort(this))
{
    m_ui->setupUi(this);

    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionQuit->setEnabled(true);
    m_ui->actionConfigure->setEnabled(true);

    QLabel* label_tx = new QLabel("Tx: ", this);
    QLabel* label_rx = new QLabel("Rx: ", this);
    QLabel* label_tx_chksm = new QLabel("TxChksmErr: ", this);
    QLabel* label_rx_chksm = new QLabel("RxChksmErr: ", this);
    m_status_label_1->setText(" ");
    m_status_label_1->setFrameShape(QFrame::StyledPanel);
    m_status_label_1->setAutoFillBackground(true);
    m_status_label_1->setStyleSheet("QLabel { background-color: rgb(255,255,255) }");
    m_status_label_2->setText(" ");
    m_status_label_2->setFrameShape(QFrame::StyledPanel);
    m_status_label_2->setAutoFillBackground(true);
    m_status_label_2->setStyleSheet("QLabel { background-color: rgb(255,255,255) }");
    label_tx->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label_rx->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label_tx_chksm->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label_rx_chksm->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_status_label_3->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_status_label_4->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_status_label_5->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_ui->bottomStatusBar->addPermanentWidget(label_tx, 1);
    m_ui->bottomStatusBar->addPermanentWidget(m_status_label_1, 2);
    m_ui->bottomStatusBar->addPermanentWidget(label_tx_chksm, 5);
    m_ui->bottomStatusBar->addPermanentWidget(m_status_label_4, 5);
    m_ui->bottomStatusBar->addPermanentWidget(label_rx, 1);
    m_ui->bottomStatusBar->addPermanentWidget(m_status_label_2, 2);
    m_ui->bottomStatusBar->addPermanentWidget(label_rx_chksm, 5);
    m_ui->bottomStatusBar->addPermanentWidget(m_status_label_3, 5);
    m_ui->bottomStatusBar->addPermanentWidget(m_status_label_5, 40);

    m_ui->label_init->setAutoFillBackground(true);
    m_ui->label_freqEst->setAutoFillBackground(true);
    m_ui->label_readyToOp->setAutoFillBackground(true);
    m_ui->label_opEnabled->setAutoFillBackground(true);
    m_ui->label_fault->setAutoFillBackground(true);
    m_ui->label_impulsiAttivi->setAutoFillBackground(true);
    m_ui->label_ImpulsiSpenti->setAutoFillBackground(true);

    m_serialScanTimer = new QTimer(this);
    m_serialScanTimer->setInterval(5000);
    m_serialReadParams = new QTimer(this);
    m_serialReadParams->setInterval(300);

    initActionsConnections();

    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    connect(m_serialReadParams, SIGNAL(timeout()), this, SLOT(askToReadParam()));

    m_serialScanTimer->start();
}

MainWindow::~MainWindow()
{
    delete m_settings;
    delete m_ui;
}

void MainWindow::openSerialPort()
{
    const SettingsDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        m_ui->actionConnect->setEnabled(false);
        m_ui->actionDisconnect->setEnabled(true);
        m_ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}

void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    m_ui->actionConnect->setEnabled(true);
    m_ui->actionDisconnect->setEnabled(false);
    m_ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

void MainWindow::synchronizeParams()
{
    m_serialReadParams->start();
}

void MainWindow::askToReadParam()
{
    MainWindow::sendDataThroughSerial(CMD_READ, QByteArrayLiteral("\x00\x00\x00\x00"), param_data[id].id);
    id++;
    if (id == SDO_LENGTH)
    {
        id = 0;
        m_serialReadParams->stop();
    }
}

void MainWindow::sendDataThroughSerial(unsigned int cmd, QByteArray data_tx, unsigned int data_id)
{
    if (m_serial->isOpen()) {

        m_status_label_1->setStyleSheet("background-color: green");

        /**
         * USART Msg Structure:
         *
         * idx:	[0]   [1]   [2]     [3]     [4]     [5]     [6]   [7]        [8]	 [9]
         *  	---------------------------------------------------------------------------
         *  	| ID1 | ID0 | DATA3 | DATA2 | DATA1 | DATA0 | STS | ARTIFACT | CHKSM | LF |
         *  	---------------------------------------------------------------------------
         */
        QByteArray array;
        uint8_t data_cod[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        uint16_t en_artifact = 0;
        data_cod[0] = ((data_id & 0xFF00) >> 8);
        data_cod[1] = (data_id & 0x00FF);
        data_cod[2] = data_tx.at(0);
        data_cod[3] = data_tx.at(1);
        data_cod[4] = data_tx.at(2);
        data_cod[5] = data_tx.at(3);
        data_cod[6] = (chksum_error_rx & 0xFE) + (cmd & 0x01);

        for (int i = 0; i < 7; i++)
        {
            if (data_cod[6] == '\n')
            {
                data_cod[6] = 0x1A;
                en_artifact |= (uint8_t)(0x0001 << (7 - i));
            }
        }
        if (en_artifact == '\n')
            en_artifact = 0x01;
        data_cod[7] = (uint8_t)en_artifact;
        data_cod[8] = 0xA5 ^ \
            data_cod[0] ^ \
            data_cod[1] ^ \
            data_cod[2] ^ \
            data_cod[3] ^ \
            data_cod[4] ^ \
            data_cod[5] ^ \
            data_cod[6] ^ \
            data_cod[7];
        if (data_cod[8] == '\n')
            data_cod[8] = 0x1A;
        data_cod[9] = '\n';

        array = QByteArray::fromRawData(reinterpret_cast<const char*>(&data_cod[0]), 10);

        // send data through serial
        m_serial->write(array);

        m_status_label_1->setStyleSheet("background-color: white");
    }
    else {
        // notify serial port closed
        qDebug() << "Serial port not connected!";
        m_status_label_5->setText("serial port closed");
    }
}

void MainWindow::writeData(const QByteArray &data)
{
    m_serial->write(data);
}

void MainWindow::readData()
{
    uint8_t artifact = 0;
    uint16_t data_id = 0;
    uint8_t data_idx = 0;
    uint8_t data_dec[7] = { 0, 0, 0, 0, 0, 0, 0 };
    uint8_t computed_chksm = 0x00;
    uint8_t data_chksm = 0x00;


    while (m_serial->canReadLine())
    {
        QByteArray data = m_serial->readLine();

        if (data.size() == 10)
        {
            computed_chksm = 0xA5 ^ data.at(0) ^ data.at(1) ^ data.at(2) ^ data.at(3) ^ data.at(4) ^ data.at(5) ^ data.at(6) ^ data.at(7);
            data_chksm = ((data.at(8) == 0x1A) ? (0x0A) : (data.at(8)));
            if (computed_chksm == data_chksm)
            {
                artifact = ((data.at(7) == 0x01) ? (0x0A) : (data.at(7)));
                data_dec[0] = ((((artifact & 0x80) >> 7) * 0x0A) + (data.at(0) * (1 - ((artifact & 0x80) >> 7))));
                data_dec[1] = ((((artifact & 0x40) >> 6) * 0x0A) + (data.at(1) * (1 - ((artifact & 0x40) >> 6))));
                data_dec[2] = ((((artifact & 0x20) >> 5) * 0x0A) + (data.at(2) * (1 - ((artifact & 0x20) >> 5))));
                data_dec[3] = ((((artifact & 0x10) >> 4) * 0x0A) + (data.at(3) * (1 - ((artifact & 0x10) >> 4))));
                data_dec[4] = ((((artifact & 0x08) >> 3) * 0x0A) + (data.at(4) * (1 - ((artifact & 0x08) >> 3))));
                data_dec[5] = ((((artifact & 0x04) >> 2) * 0x0A) + (data.at(5) * (1 - ((artifact & 0x04) >> 2))));
                data_dec[6] = ((((artifact & 0x02) >> 1) * 0x0A) + (data.at(6) * (1 - ((artifact & 0x02) >> 1))));
                chksum_error_tx = data_dec[6];
                data_id = (data_dec[0] << 8) + data_dec[1];
                data_idx = data_id - ID_PDO_00;

                if ((data_id & 0xFF00) == ID_PDO_00)
                    memcpy(process_data[data_idx].val, reinterpret_cast<void*>(&data_dec[2]), process_data[data_idx].num_byte);
                else if ((data_id & 0xFF00) == ID_SDO_00)
                    memcpy(param_data[data_idx].val, reinterpret_cast<void*>(&data_dec[2]), process_data[data_idx].num_byte);

                switch (data_id)
                {

                    /* ---- */
                    /* PDO  */
                    /* ---- */

                case ID_PDO_00:
                    // INITIALIZED
                    if (sts_wd_1.bit.INITIALIZED) m_ui->label_init->setStyleSheet("background-color: green");
                    else m_ui->label_init->setStyleSheet("background-color: white");
                    // FREQ_ESTIMATED
                    if (sts_wd_1.bit.FREQ_ESTIMATED) m_ui->label_freqEst->setStyleSheet("background-color: green");
                    else m_ui->label_freqEst->setStyleSheet("background-color: white");
                    // READY_TO_OPERATE
                    if (sts_wd_1.bit.READY_TO_OPERATE) m_ui->label_readyToOp->setStyleSheet("background-color: green");
                    else m_ui->label_readyToOp->setStyleSheet("background-color: white");
                    // OP_ENABLED
                    if (sts_wd_1.bit.OP_ENABLED) m_ui->label_opEnabled->setStyleSheet("background-color: green");
                    else m_ui->label_opEnabled->setStyleSheet("background-color: white");
                    // FAULT
                    if (sts_wd_1.bit.FAULT) m_ui->label_fault->setStyleSheet("background-color: red");
                    else m_ui->label_fault->setStyleSheet("background-color: white");
                    // PULSE_ENABLED
                    if (sts_wd_1.bit.PULSE_ENABLED)
                    {
                        m_ui->label_impulsiAttivi->setStyleSheet("background-color: red");
                        m_ui->label_ImpulsiSpenti->setStyleSheet("background-color: white");
                    }
                    else
                    {
                        m_ui->label_impulsiAttivi->setStyleSheet("background-color: white");
                        m_ui->label_ImpulsiSpenti->setStyleSheet("background-color: green");
                    }
                    break;
                case ID_PDO_01:
                    // SYNCH_SCR_LOST
                    if (alm_wd_1.bit.SYNCH_SCR_LOST) m_ui->label_SYNCH_SCR_LOST->setStyleSheet("background-color: red");
                    else m_ui->label_SYNCH_SCR_LOST->setStyleSheet("background-color: white");
                    // FREQ_SCR_UNDEF
                    if (alm_wd_1.bit.FREQ_SCR_UNDEF) m_ui->label_FREQ_SCR_UNDEF->setStyleSheet("background-color: red");
                    else m_ui->label_FREQ_SCR_UNDEF->setStyleSheet("background-color: white");
                    // DESAT
                    if (alm_wd_1.bit.DESAT) m_ui->label_DESAT->setStyleSheet("background-color: red");
                    else m_ui->label_DESAT->setStyleSheet("background-color: white");
                    // OVER_CURRENT
                    if (alm_wd_1.bit.OVER_CURRENT) m_ui->label_OVER_CURRENT->setStyleSheet("background-color: red");
                    else m_ui->label_OVER_CURRENT->setStyleSheet("background-color: white");
                    // UNDER_CURRENT
                    if (alm_wd_1.bit.UNDER_CURRENT) m_ui->label_UNDER_CURRENT->setStyleSheet("background-color: red");
                    else m_ui->label_UNDER_CURRENT->setStyleSheet("background-color: white");
                    // OVER_VOLTAGE
                    if (alm_wd_1.bit.OVER_VOLTAGE) m_ui->label_OVER_VOLTAGE->setStyleSheet("background-color: red");
                    else m_ui->label_OVER_VOLTAGE->setStyleSheet("background-color: white");
                    // UNDER_VOLTAGE
                    if (alm_wd_1.bit.UNDER_VOLTAGE) m_ui->label_UNDER_VOLTAGE->setStyleSheet("background-color: red");
                    else m_ui->label_UNDER_VOLTAGE->setStyleSheet("background-color: white");
                    // PSUPLLY
                    if (alm_wd_1.bit.PSUPLLY) m_ui->label_PSUPLLY->setStyleSheet("background-color: red");
                    else m_ui->label_PSUPLLY->setStyleSheet("background-color: white");
                    // EXTERNAL_FLT
                    if (alm_wd_1.bit.EXTERNAL_FLT) m_ui->label_EXTERNAL_FLT->setStyleSheet("background-color: red");
                    else m_ui->label_EXTERNAL_FLT->setStyleSheet("background-color: white");
                    // OH1
                    if (alm_wd_1.bit.OH1) m_ui->label_OH1->setStyleSheet("background-color: red");
                    else m_ui->label_OH1->setStyleSheet("background-color: white");
                    // OH2
                    if (alm_wd_1.bit.OH2) m_ui->label_OH2->setStyleSheet("background-color: red");
                    else m_ui->label_OH2->setStyleSheet("background-color: white");
                    break;
                case ID_PDO_02: m_ui->label_vInvVal->setText(QString::number(*(float*)process_data[data_idx].val)); break;
                case ID_PDO_03: m_ui->label_iInvVal->setText(QString::number(*(float*)process_data[data_idx].val)); break;
                case ID_PDO_04: m_ui->label_vInvRectVal->setText(QString::number(*(float*)process_data[data_idx].val)); break;
                case ID_PDO_05: m_ui->label_iInvRectVal->setText(QString::number(*(float*)process_data[data_idx].val)); break;
                case ID_PDO_06: m_ui->label_ntc1Val->setText(QString::number(*(float*)process_data[data_idx].val)); break;
                case ID_PDO_07: m_ui->label_ntc2Val->setText(QString::number(*(float*)process_data[data_idx].val)); break;
                case ID_PDO_08: m_ui->label_potVal->setText(QString::number(*(float*)process_data[data_idx].val)); break;
                case ID_PDO_09: m_ui->label_apScrVal->setText(QString::number(*(float*)process_data[data_idx].val)); break;
                case ID_PDO_10: m_ui->label_freqIgbtVal->setText(QString::number(*(float*)process_data[data_idx].val)); break;
                case ID_PDO_11: m_ui->label_timer0CntVal->setText(QString::number(*(uint32_t*)process_data[data_idx].val)); break;
                case ID_PDO_12: m_ui->label_freqInvalidCntVal->setText(QString::number(*(uint16_t*)process_data[data_idx].val)); break;
                case ID_PDO_13: m_ui->label_lineFreqVal->setText(QString::number(*(float*)process_data[data_idx].val)); break;

                    /* ---- */
                    /* SDO  */
                    /* ---- */
                   
                case ID_SDO_00: break;
                case ID_SDO_01: m_ui->doubleSpinBox_durataInit->setValue(*(uint16_t*)param_data[data_idx].val); break;
                case ID_SDO_02: m_ui->doubleSpinBox_durataFreqEst->setValue(*(uint16_t*)param_data[data_idx].val); break;
                case ID_SDO_03:
                    disconnect(m_ui->checkBox_aperturaMan, &QCheckBox::toggled, this, &MainWindow::pressed_aperturaMan);
                    m_ui->checkBox_aperturaMan->setChecked((*(uint16_t*)param_data[data_idx].val));
                    if (m_ui->checkBox_aperturaMan->isChecked())
                    {
                        m_ui->label_valApertura->setEnabled(1);
                        m_ui->doubleSpinBox_valApertura->setEnabled(1);
                        m_ui->label_valAperturaUM->setEnabled(1);
                        m_ui->doubleSpinBox_valApertura->setValue(scr_cmd_alfa_set);
                    }
                    else
                    {
                        m_ui->label_valApertura->setEnabled(0);
                        m_ui->doubleSpinBox_valApertura->setEnabled(0);
                        m_ui->label_valAperturaUM->setEnabled(0);
                    }
                    connect(m_ui->checkBox_aperturaMan, &QCheckBox::toggled, this, &MainWindow::pressed_aperturaMan);
                    break;
                case ID_SDO_04: m_ui->doubleSpinBox_valApertura->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_05: m_ui->doubleSpinBox_valAperturaRidotta50->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_06: m_ui->doubleSpinBox_valAperturaRidotta60->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_07: m_ui->doubleSpinBox_durataApRidottaCheck->setValue((*(uint16_t*)param_data[data_idx].val)); break;
                case ID_SDO_08: m_ui->doubleSpinBox_velRampa->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_09: m_ui->doubleSpinBox_freqPrincipale->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_10: m_ui->doubleSpinBox_ampModSweep->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_11: m_ui->doubleSpinBox_freqModSweep->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_12: m_ui->doubleSpinBox_vInvRectGain->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_13: m_ui->doubleSpinBox_vInvRectOffset->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_14: m_ui->doubleSpinBox_iInvRectGain->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_15: m_ui->doubleSpinBox_iInvRectOffset->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_16: m_ui->doubleSpinBox_ntc1Gain->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_17: m_ui->doubleSpinBox_ntc1Offset->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_18: m_ui->doubleSpinBox_ntc2Gain->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_19: m_ui->doubleSpinBox_ntc2Offset->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_20: m_ui->doubleSpinBox_potGain->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_21: m_ui->doubleSpinBox_potOffset->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_22: m_ui->doubleSpinBox_valOverCurr->setValue((*(float*)param_data[data_idx].val)); break;
                case ID_SDO_23:
                    disconnect(m_ui->checkBox_enSweep, &QCheckBox::toggled, this, &MainWindow::pressed_enSweep);
                    m_ui->checkBox_enSweep->setChecked((*(uint16_t*)param_data[data_idx].val));
                    if (m_ui->checkBox_enSweep->isChecked())
                    {
                        m_ui->label_ampModSweep->setEnabled(1);
                        m_ui->doubleSpinBox_ampModSweep->setEnabled(1);
                        m_ui->label_ampModSweep_2->setEnabled(1);
                        m_ui->doubleSpinBox_ampModSweep->setValue(sweep_amplitude);
                        
                        m_ui->label_freqModSweep->setEnabled(1);
                        m_ui->doubleSpinBox_freqModSweep->setEnabled(1);
                        m_ui->label_freqModSweepUM->setEnabled(1);
                        m_ui->doubleSpinBox_freqModSweep->setValue(sweep_freq);
                    }
                    else
                    {
                        m_ui->label_ampModSweep->setEnabled(0);
                        m_ui->doubleSpinBox_ampModSweep->setEnabled(0);
                        m_ui->label_ampModSweep_2->setEnabled(0);

                        m_ui->label_freqModSweep->setEnabled(0);
                        m_ui->doubleSpinBox_freqModSweep->setEnabled(0);
                        m_ui->label_freqModSweepUM->setEnabled(0);
                    }
                    connect(m_ui->checkBox_enSweep, &QCheckBox::toggled, this, &MainWindow::pressed_enSweep);
                    break;
                default: break;
                }
            }
            else
            {
                chksum_error_rx++;
            }
        }
        else
        {
            chksum_error_rx;
        }
        m_status_label_3->setText(QString::number(chksum_error_rx));
        m_status_label_4->setText(QString::number(chksum_error_tx));
    }
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::initActionsConnections()
{
    connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(m_ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(m_ui->actionSynchronizeParams, &QAction::triggered, this, &MainWindow::synchronizeParams);

    connect(m_ui->pushButton_ackFault, &QPushButton::pressed, this, &MainWindow::pressed_ackFault);
    connect(m_ui->pushButton_start, &QPushButton::pressed, this, &MainWindow::pressed_start);
    connect(m_ui->checkBox_aperturaMan, &QCheckBox::pressed, this, &MainWindow::pressed_aperturaMan);
    connect(m_ui->doubleSpinBox_valApertura, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::valueChanged_valApertura);
    connect(m_ui->doubleSpinBox_valAperturaRidotta50, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::valueChanged_valAperturaRidotta50);
    connect(m_ui->doubleSpinBox_valAperturaRidotta60, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::valueChanged_valAperturaRidotta60);
    connect(m_ui->doubleSpinBox_durataApRidottaCheck, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::valueChanged_durataApRidottaCheck);
    connect(m_ui->doubleSpinBox_velRampa, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::valueChanged_velRampa);
    connect(m_ui->checkBox_enSweep, &QCheckBox::pressed, this, &MainWindow::pressed_enSweep);

    
}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status_label_5->setText(message);
}

#pragma region callbacks_modifica_dati

void MainWindow::pressed_ackFault()
{
    uint32_t data_val;
    data_val = cmd_wd_1.all | 0x0080;
    uint16_t data_id = ID_SDO_00;
    QByteArray data_tx(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
    QThread::msleep(500);
    data_val = cmd_wd_1.all &~ 0x0080;
    data_tx = QByteArray(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
}

void MainWindow::pressed_start()
{
    uint32_t data_val = (m_ui->pushButton_start->isChecked() == 0) ? (cmd_wd_1.all | 0x0001) : (cmd_wd_1.all &~ 0x0001);
    uint16_t data_id = ID_SDO_00;
    QByteArray data_tx(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
}

void MainWindow::pressed_aperturaMan()
{
    uint32_t data_val;
    uint16_t data_id = ID_SDO_03;
    QByteArray data_tx;
    if (m_ui->checkBox_aperturaMan->isChecked())
        data_val = 0;
    else
        data_val = 1;
    data_tx = QByteArray(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
}

void MainWindow::valueChanged_valApertura()
{
    float data_val = m_ui->doubleSpinBox_valApertura->value();
    uint16_t data_id = ID_SDO_04;
    QByteArray data_tx(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
}

void MainWindow::valueChanged_valAperturaRidotta50()
{
    float data_val = m_ui->doubleSpinBox_valAperturaRidotta50->value();
    uint16_t data_id = ID_SDO_05;
    QByteArray data_tx(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
}

void MainWindow::valueChanged_valAperturaRidotta60()
{
    float data_val = m_ui->doubleSpinBox_valAperturaRidotta60->value();
    uint16_t data_id = ID_SDO_06;
    QByteArray data_tx(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
}

void MainWindow::valueChanged_durataApRidottaCheck()
{
    float data_val = m_ui->doubleSpinBox_durataApRidottaCheck->value();
    uint16_t data_id = ID_SDO_07;
    QByteArray data_tx(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
}

void MainWindow::valueChanged_velRampa()
{
    float data_val = m_ui->doubleSpinBox_velRampa->value();
    uint16_t data_id = ID_SDO_08;
    QByteArray data_tx(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
}

void MainWindow::pressed_enSweep()
{
    uint32_t data_val;
    uint16_t data_id = ID_SDO_23;
    QByteArray data_tx;
    if (m_ui->checkBox_enSweep->isChecked())
        data_val = 0;
    else
        data_val = 1;
    data_tx = QByteArray(reinterpret_cast<const char*>(&data_val), sizeof(data_val));
    MainWindow::sendDataThroughSerial(CMD_WRITE, data_tx, data_id);
}

#pragma endregion