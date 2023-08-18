#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include <QScrollBar>
#include <QDoubleSpinBox>
#include <QFrame>
#include <QModbusTcpClient>
#include <QModbusRtuSerialMaster>
#include <QStatusBar>
#include <QUrl>
#include <QtWidgets>
#include <QtSql>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QTableView>
#include <QSplitter>

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
    model_params(new QStandardItemModel),
    model_process(new QStandardItemModel)
{
    // ---------------------------------------
    // INIT ELEMENTI GUI
    // ---------------------------------------
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

    // ---------------------------------------------------------- //
    // IMPORTAZIONE DATABASE E COSTRUZIONE TABELLA PARAMETRI
    // ---------------------------------------------------------- //
    QFile file_params(":/db/params_data.csv");
    if (file_params.open(QFile::ReadOnly)) {
        QTextStream stream(&file_params);

        char separator_file = ',';
        QString line = stream.readLine();
        list_columns_params = line.simplified().split(separator_file);
        model_params->setHorizontalHeaderLabels(list_columns_params);

        int row = 0;
        QStandardItem* newItem = nullptr;
        while (!stream.atEnd()) {
            line = stream.readLine();
            if (!line.startsWith('#') && line.contains(separator_file)) {
                list_row_params = line.simplified().split(separator_file);
                for (int col = 0; col < list_row_params.length(); ++col) {
                    newItem = new QStandardItem(list_row_params.at(col));
                    model_params->setItem(row, col, newItem);

                    if (col != list_columns_params.indexOf("val_actual"))
                    {
                        auto currentFlags = model_params->item(row, col)->flags();
                        model_params->item(row, col)->setFlags(currentFlags & (~Qt::ItemIsEditable));

                        if (col < list_columns_params.indexOf("val_actual"))
                            model_params->item(row, col)->setData(QColor(230, 255, 200), Qt::BackgroundColorRole);
                        else if (col > list_columns_params.indexOf("val_actual"))
                            model_params->item(row, col)->setData(QColor(215, 235, 255), Qt::BackgroundColorRole);
                    }
                    else
                        model_params->item(row, col)->setData(QColor(255, 255, 128), Qt::BackgroundColorRole);
                }
                ++row;
            }
        }
    }
    file_params.close();

    FreezeTableWidget* tableView_params = new FreezeTableWidget(model_params);
    QStringList headers_params;
    startAddress_params = model_params->data(model_params->index(0, list_columns_params.indexOf("id_address"))).toInt();
    address_cmd_wd_1 = startAddress_params; // CMD_WD_1 � il primo parametro
    
    for (int i = 0; i < model_params->columnCount(); i++)
        headers_params.append(tableView_params->model()->headerData(i, Qt::Horizontal).toString());

    SpinBoxDelegate* delegate_doubleSpinBox_params = new SpinBoxDelegate;
    delegate_doubleSpinBox_params->headers_params = headers_params;
    delegate_doubleSpinBox_params->model = model_params;
    tableView_params->setItemDelegateForColumn(list_columns_params.indexOf("val_actual"), delegate_doubleSpinBox_params);
    tableView_params->setColumnHidden(list_columns_params.indexOf("type"), 1);
    tableView_params->setColumnHidden(list_columns_params.indexOf("decimal"), 1);
    tableView_params->setColumnHidden(list_columns_params.indexOf("single_steps"), 1);
    tableView_params->setColumnHidden(list_columns_params.indexOf("dsp_name"), 1);
    tableView_params->setColumnHidden(list_columns_params.indexOf("kp_to_modbus"), 1);
    tableView_params->setColumnHidden(list_columns_params.indexOf("precision"), 1);
    tableView_params->setColumnHidden(list_columns_params.indexOf("val_modbus"), 1);
    tableView_params->horizontalHeader()->setStretchLastSection(true);

    // ---------------------------------------------------------- //
    // IMPORTAZIONE DATABASE E COSTRUZIONE TABELLA DATI DI PROCESSO
    // ---------------------------------------------------------- //
    QFile file_process(":/db/process_data.csv");
    if (file_process.open(QFile::ReadOnly)) {
        QTextStream stream(&file_process);

        char separator_file = ',';
        QString line = stream.readLine();
        list_columns_process = line.simplified().split(separator_file);
        model_process->setHorizontalHeaderLabels(list_columns_process);

        int row = 0;
        QStandardItem* newItem = nullptr;
        while (!stream.atEnd()) {
            line = stream.readLine();
            if (!line.startsWith('#') && line.contains(separator_file)) {
                list_row_process = line.simplified().split(separator_file);
                for (int col = 0; col < list_row_process.length(); ++col) {
                    newItem = new QStandardItem(list_row_process.at(col));
                    model_process->setItem(row, col, newItem);
                    auto currentFlags = model_process->item(row, col)->flags();
                    model_process->item(row, col)->setFlags(currentFlags & (~Qt::ItemIsEditable));

                    if (col == list_columns_process.indexOf("val_actual"))
                        model_process->item(row, col)->setData(QColor(255, 255, 128), Qt::BackgroundColorRole);
                    else if (col < list_columns_process.indexOf("val_actual"))
                        model_process->item(row, col)->setData(QColor(230, 255, 200), Qt::BackgroundColorRole);
                    else
                        model_process->item(row, col)->setData(QColor(215, 235, 255), Qt::BackgroundColorRole);
                }
                ++row;
            }
        }
    }
    file_process.close();

    FreezeTableWidget* tableView_process = new FreezeTableWidget(model_process);
    startAddress_process = model_process->data(model_process->index(0, list_columns_process.indexOf("id_address"))).toInt();
    address_sts_wd_1 = startAddress_process;        // STS_WD_1 � il primo dato di processo
    address_alm_wd_1 = startAddress_process + 1;    // ALM_WD_1 � il secondo dato di processo
    QStringList headers_process;

    for (int i = 0; i < model_process->columnCount(); i++)
        headers_process.append(tableView_process->model()->headerData(i, Qt::Horizontal).toString());

    tableView_process->setColumnHidden(list_columns_process.indexOf("type"), 1);
    tableView_process->setColumnHidden(list_columns_process.indexOf("decimal"), 1);
    tableView_process->setColumnHidden(list_columns_process.indexOf("dsp_name"), 1);
    tableView_process->setColumnHidden(list_columns_process.indexOf("kp_to_modbus"), 1);
    tableView_process->setColumnHidden(list_columns_process.indexOf("precision"), 1);
    tableView_process->setColumnHidden(list_columns_process.indexOf("val_modbus"), 1);
    tableView_process->setSelectionMode(QAbstractItemView::NoSelection);
    tableView_process->horizontalHeader()->setStretchLastSection(true);

    // ---------------------------------------
    // GUI TIMERS
    // ---------------------------------------
    timer_serialReadParamsData = new QTimer(this);
    timer_serialReadParamsData->setInterval(5000);
    timer_serialReadProcessData = new QTimer(this);
    timer_serialReadProcessData->setInterval(m_settings->settings().readInterval_ms);

    // ---------------------------------------
    // MAINWINDOW SETUP
    // ---------------------------------------
    createDockWindows();
    QHBoxLayout* tableLowerLayout = new QHBoxLayout;
    QHBoxLayout* tableUpperLayout = new QHBoxLayout;
    tableView_params->setLayout(tableLowerLayout);
    tableView_process->setLayout(tableUpperLayout);
    QSplitter* poSplitter = new QSplitter(Qt::Vertical, this);
    poSplitter->addWidget(tableView_params);
    poSplitter->addWidget(tableView_process);
    setCentralWidget(poSplitter);

    // ---------------------------------------
    // CONNESSIONI
    // ---------------------------------------
    initActionsConnections();
    timer_serialReadParamsData->start();
}

MainWindow::~MainWindow()
{
    if (modbusDevice)
        modbusDevice->disconnectDevice();
    delete modbusDevice;
    delete m_settings;
    delete m_ui;
}

void MainWindow::initActionsConnections()
{
    connect(m_ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(m_ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(m_ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(m_ui->actionReadAll, &QAction::triggered, this, &MainWindow::readAll);
    connect(m_ui->actionAutoTrigger, &QAction::triggered, this, &MainWindow::autoChangePressParameter);
    connect(m_ui->pushButton_ackFault, &QPushButton::pressed, this, &MainWindow::pressed_ackFault);
    connect(m_ui->pushButton_start, &QPushButton::pressed, this, &MainWindow::pressed_start);
    connect(timer_serialReadProcessData, SIGNAL(timeout()), this, SLOT(readProcessParam()));
    connect(model_params, SIGNAL(dataChanged(QModelIndex, QModelIndex, QVector<int>)), this, SLOT(tableDataChanged_params(QModelIndex, QModelIndex, QVector<int>)));
    QPushButton* settings_applyButton = m_settings->get_applyPushButton();
    connect(settings_applyButton, &QPushButton::clicked, this, &MainWindow::onSettingsChanged);
}

void MainWindow::autoChangePressParameter()
{
    // Auto trigger enabled
    if (m_ui->actionAutoTrigger->isChecked())
        delegate_doubleSpinBox_params->en_auto_trigger = 1;
    // Auto trigger disabled
    else
        delegate_doubleSpinBox_params->en_auto_trigger = 0;
    delegate_doubleSpinBox_params->editDataChangedConnection();
}

void MainWindow::readParam()
{
    quint16 address_start = model_params->data(tableView_params->currentIndex()).toInt();
    if ((!m_serial) && (modbusDevice))
        sendRequest_Modbus(address_start, 1, CMD_READ);
    else if ((m_serial) && (!modbusDevice))
        sendRequest_CustomSerial10B(address_start, 1, CMD_READ);
}

void MainWindow::onSettingsChanged()
{
    // unlink modbusDevice
    if (modbusDevice) {
        modbusDevice->disconnectDevice();
        delete modbusDevice;
        modbusDevice = nullptr;
    }

    // unlink m_serial
    if (m_serial) {
        m_serial->disconnect();
        delete m_serial;
        m_serial = nullptr;
    }

    switch (m_settings->settings().protocol)
    {
    case CustomSerial10B:
        m_serial = new QSerialPort(this);
        connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError_CustomSerial10B);
        connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::receiveMessage_CustomSerial10B);
        break;
    case Modbus_RTU:
        modbusDevice = new QModbusRtuSerialMaster(this);
        connect(modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
            showStatusMessage(modbusDevice->errorString() + QStringLiteral(" - Could not create Modbus master.")); });
        break;
    case Modbus_TCP:
        modbusDevice = new QModbusTcpClient(this);
        connect(modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
            showStatusMessage(modbusDevice->errorString() + QStringLiteral(" - Could not create Modbus client.")); });
        break;
    default:
        break;
    }

    // Manage Modbus Object
    if (modbusDevice)
        connect(modbusDevice, &QModbusClient::stateChanged, this, &MainWindow::onModbusStateChanged);

    timer_serialReadProcessData->setInterval(m_settings->settings().readInterval_ms);
}

void MainWindow::onModbusStateChanged(int state)
{
    bool connected = (state != QModbusDevice::UnconnectedState);
    if (modbusDevice)
    {
        m_ui->actionConnect->setEnabled(!connected);
        m_ui->actionDisconnect->setEnabled(connected);

        if (state == QModbusDevice::UnconnectedState)
            showStatusMessage("Modbus Disconnected");
        else if (state == QModbusDevice::ConnectedState)
            showStatusMessage("Modbus Connected");
    }
}

void MainWindow::tableDataChanged_params(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles)
{
    quint16 id_address = model_params->data(model_params->index(topLeft.row(), list_columns_params.indexOf("id_address"))).toInt();
    disconnect(model_params, SIGNAL(dataChanged(QModelIndex, QModelIndex, QVector<int>)), this, SLOT(tableDataChanged_params(QModelIndex, QModelIndex, QVector<int>)));
    computeValU16FromDouble(model_params, topLeft.row());
    connect(model_params, SIGNAL(dataChanged(QModelIndex, QModelIndex, QVector<int>)), this, SLOT(tableDataChanged_params(QModelIndex, QModelIndex, QVector<int>)));
    qDebug() << "SENT: "
        << "id_addr: " << QString::number(id_address)
        << " - val_actual: " << QString::number(model_params->data(model_params->index(topLeft.row(), list_columns_params.indexOf("val_actual"))).toDouble())
        << " - val_modbus: " << QString::number(model_params->data(model_params->index(topLeft.row(), list_columns_params.indexOf("val_modbus"))).toInt());
    if ((!m_serial) && (modbusDevice))
    {
        sendRequest_Modbus(id_address, 1, CMD_WRITE);
        QTimer::singleShot(1000, this, SLOT(sendRequest_Modbus(id_address, 1, CMD_READ)));
    }
    else if ((m_serial) && (!modbusDevice))
    {
        sendRequest_CustomSerial10B(id_address, 1, CMD_WRITE);
        QTimer::singleShot(1000, this, SLOT(sendRequest_CustomSerial10B(id_address, 1, CMD_READ)));
    }
}

void MainWindow::openSerialPort()
{    
    // Serial connection
    if ((m_serial)&&(!modbusDevice))
    {
        m_serial->setPortName(m_settings->settings().name);
        m_serial->setBaudRate(m_settings->settings().baudRate);
        m_serial->setDataBits(m_settings->settings().dataBits);
        m_serial->setParity(m_settings->settings().parity);
        m_serial->setStopBits(m_settings->settings().stopBits);
        m_serial->setFlowControl(m_settings->settings().flowControl);
        if (m_serial->open(QIODevice::ReadWrite)) {
            m_ui->actionConnect->setEnabled(false);
            m_ui->actionDisconnect->setEnabled(true);
            m_ui->actionConfigure->setEnabled(false);
            showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                .arg(m_settings->settings().name)
                .arg(m_settings->settings().stringBaudRate)
                .arg(m_settings->settings().stringDataBits)
                .arg(m_settings->settings().stringParity)
                .arg(m_settings->settings().stringStopBits)
                .arg(m_settings->settings().stringFlowControl));
            //readAll();
        }
        else {
            QMessageBox::critical(this, tr("Error"), m_serial->errorString());
            showStatusMessage(tr("Open error"));
        }
    }
    // Modbus connection
    else if ((!m_serial) && (modbusDevice))
    {
        showStatusMessage("");
        if (modbusDevice->state() != QModbusDevice::ConnectedState)
        {
            if (m_settings->settings().protocol == Modbus_RTU)
            {
                modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,
                    m_settings->settings().name);
                modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,
                    m_settings->settings().parity);
                modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,
                    m_settings->settings().baudRate);
                modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,
                    m_settings->settings().dataBits);
                modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,
                    m_settings->settings().stopBits);
            }
            else
            {
                const QUrl url = m_settings->settings().ipAddressAndPort;
                modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, url.port());
                modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, url.host());
            }
            modbusDevice->setTimeout(m_settings->settings().responseTime_ms);
            modbusDevice->setNumberOfRetries(m_settings->settings().numberOfRetries);

            if (!modbusDevice->connectDevice())
            {
                statusBar()->showMessage(tr("Connect failed: ") + modbusDevice->errorString(), 5000);
            }
            else
            {
                m_ui->actionConnect->setEnabled(false);
                m_ui->actionDisconnect->setEnabled(true);
            }
        }
        else
        {
            modbusDevice->disconnectDevice();
            m_ui->actionConnect->setEnabled(true);
            m_ui->actionDisconnect->setEnabled(false);
        }
    }
    // Unmanaged
    else
    { }
}

void MainWindow::closeSerialPort()
{
    timer_serialReadProcessData->stop();

    if (m_serial)
    {
        if (m_serial->isOpen())
            m_serial->close();
        m_ui->actionConnect->setEnabled(true);
        m_ui->actionDisconnect->setEnabled(false);
        m_ui->actionConfigure->setEnabled(true);
        showStatusMessage(tr("Disconnected"));
    }
    else if (modbusDevice)
        modbusDevice->disconnectDevice();
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

void MainWindow::readAll()
{
    if (m_ui->actionReadAll->isChecked())
    {
        timer_serialReadProcessData->start();
    }
    else
    {
        timer_serialReadProcessData->stop();
    }
}

void MainWindow::readProcessParam()
{
    static bool read_params = 1;
    // Read Params on first call
    if (read_params)
    {
        if ((!m_serial) && (modbusDevice))
            sendRequest_Modbus(startAddress_params, model_params->rowCount(), CMD_READ);
        else if ((m_serial) && (!modbusDevice))
            sendRequest_CustomSerial10B(startAddress_params, model_params->rowCount(), CMD_WRITE);
        read_params = 0;
    }
    // Read Process on all other calls
    else
    {
        if ((!m_serial) && (modbusDevice))
            sendRequest_Modbus(startAddress_process, model_process->rowCount(), CMD_READ);
        else if ((m_serial) && (!modbusDevice))
            sendRequest_CustomSerial10B(startAddress_params, model_params->rowCount(), CMD_WRITE);
    }
}

void MainWindow::sendRequest_Modbus(quint16 start_address, quint16 address_length, int cmd)
{
    if (!modbusDevice)
        return;

    blinkTxLabel();

    Q_ASSERT((start_address >= 0) && (address_length >= 0));
    QModbusDataUnit modbus_data_unit = QModbusDataUnit(QModbusDataUnit::RegisterType::HoldingRegisters, start_address, address_length);

    // Write Params
    if (cmd == CMD_WRITE)
    {
        quint16 col = list_columns_params.indexOf("val_modbus");
        for (quint16 i = 0, total = quint16(modbus_data_unit.valueCount()); i < total; ++i)
        {
            quint16 data_write = model_params->data(model_params->index((start_address - startAddress_params) + i, col)).toInt();
            modbus_data_unit.setValue(i, data_write);
        }
        if (auto* reply = modbusDevice->sendWriteRequest(modbus_data_unit, m_settings->settings().modbusServerAddress))
        {
            if (!reply->isFinished())
            {
                connect(reply, &QModbusReply::finished, this, [this, reply]() {
                    if (reply->error() == QModbusDevice::ProtocolError)
                    {
                        showStatusMessage(tr("Write response error: %1 (Mobus exception: 0x%2)")
                            .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16));
                    }
                    else if (reply->error() != QModbusDevice::NoError)
                    {
                        showStatusMessage(tr("Write response error: %1 (code: 0x%2)").
                            arg(reply->errorString()).arg(reply->error(), -1, 16));
                    }
                    reply->deleteLater();
                    });
            }
            else {
                // broadcast replies return immediately
                reply->deleteLater();
            }
        }
        else {
            showStatusMessage(tr("Write error: ") + modbusDevice->errorString());
        }
    }
    // Read Params/Process
    else if (cmd == CMD_READ)
    {
        if (auto* reply = modbusDevice->sendReadRequest(modbus_data_unit, m_settings->settings().modbusServerAddress)) {
            if (!reply->isFinished())
                connect(reply, &QModbusReply::finished, this, &MainWindow::receiveMessage_Modbus);
            else
                delete reply; // broadcast replies return immediately
        }
        else {
            showStatusMessage(tr("Read error: ") + modbusDevice->errorString());
        }
    }
}

void MainWindow::receiveMessage_Modbus()
{
    auto reply = qobject_cast<QModbusReply*>(sender());
    if (!reply)
        return;

    blinkRxLabel();

    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();

        quint16 start_address = unit.startAddress();
        quint16 address_length = unit.valueCount();
        QVector<quint16> val_u16_list = unit.values();

        refreshData(start_address, address_length, val_u16_list);
    }
    else if (reply->error() == QModbusDevice::ProtocolError)
    {
        showStatusMessage(tr("Read response error: %1 (Mobus exception: 0x%2)").
            arg(reply->errorString()).
            arg(reply->rawResult().exceptionCode(), -1, 16));
    }
    else
    {
        showStatusMessage(tr("Read response error: %1 (code: 0x%2)").
            arg(reply->errorString()).
            arg(reply->error(), -1, 16));
    }

    reply->deleteLater();
}

void MainWindow::sendRequest_CustomSerial10B(quint16 start_address, quint16 address_length, int cmd)
{
    QByteArray data_tx_serial = QByteArray::number(
        model_params->data(model_params->index((start_address - startAddress_params), list_columns_params.indexOf("val_modbus"))).toInt(), 
        16);

    if (m_serial)
    { 
        if (m_serial->isOpen()) {
            blinkTxLabel();

            /**
             * USART Msg Structure:
             *
             * idx:	[0]   [1]   [2]     [3]     [4]     [5]     [6]		 [7]        [8]	 	[9]
             *  	------------------------------------------------------------------------------
             *  	| ID1 | ID0 | DATA3 | DATA2 | DATA1 | DATA0 | CMDSTS | ARTIFACT | CHKSM | LF |
             *  	------------------------------------------------------------------------------
             */
            QByteArray array;
            uint8_t data_cod[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            uint16_t en_artifact = 0;
            data_cod[0] = ((start_address & 0xFF00) >> 8);
            data_cod[1] = (start_address & 0x00FF);
            data_cod[2] = data_tx_serial.at(0);
            data_cod[3] = data_tx_serial.at(1);
            data_cod[4] = data_tx_serial.at(2);
            data_cod[5] = data_tx_serial.at(3);
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
        }
        else
        {
            // notify serial port closed
            qDebug() << "Serial port not connected!";
            showStatusMessage("Serial port not connected!");
        }
    }
    else
    {
        // notify serial port closed
        qDebug() << "CustomSerial10B not exist!";
        showStatusMessage("CustomSerial10B not exist!");
    }
}

void MainWindow::receiveMessage_CustomSerial10B()
{
    uint8_t artifact = 0;
    quint16 start_address = 0;
    QVector<quint16> val_u16_list;
    uint8_t data_dec[7] = { 0, 0, 0, 0, 0, 0, 0 };
    uint8_t computed_chksm = 0xA5;
    uint8_t data_chksm = 0x00;
    //USART_RX_MSG usart_rx;

    if (m_serial)
    {
        while (m_serial->canReadLine())
        {
            QByteArray data = m_serial->readLine();

            blinkRxLabel();

            if (data.size() == 10)
            {
                /**
                 * USART Msg Structure:
                 *
                 * idx:	[0]   [1]   [2]     [3]     [4]     [5]     [6]		 [7]        [8]	 	[9]
                 *  	------------------------------------------------------------------------------
                 *  	| ID1 | ID0 | DATA3 | DATA2 | DATA1 | DATA0 | CMDSTS | ARTIFACT | CHKSM | LF |
                 *  	------------------------------------------------------------------------------
                 */

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
                    start_address = (data_dec[0] << 8) + data_dec[1];
                    quint16 val_u16 = (data_dec[2] << 8) + data_dec[3];
                    val_u16_list.append(val_u16);
                    refreshData(start_address, 1, val_u16_list);    // address_length future implementation for CustomSerial10B
                }
                else
                {
                    chksum_error_rx++;
                    qDebug() << hex << "errore chksum. parametro/dp. id: " << QString::number(data.at(0), 16) << QString::number(data.at(1), 16);
                }
            }
            else
            {
                chksum_error_rx;
                qDebug() << hex << "errore lunhgezza. parametro/dp. id: " << data.at(0) << data.at(1);
            }
            m_status_label_3->setText(QString::number(chksum_error_rx));
            m_status_label_4->setText(QString::number(chksum_error_tx));
        }
    }
}

void MainWindow::refreshData(quint16 start_address, quint16 address_length, QVector<quint16> val_u16_list)
{
    QStandardItemModel* model_generic;
    quint16 base_address = 0;
    QStringList* list_column_generic;
    bool disable_updateTableParams = 0;

    if (start_address >= startAddress_process)
    {
        model_generic = model_process;
        list_column_generic = &list_columns_process;
        base_address = startAddress_process;
        disable_updateTableParams = 0;
    }
    else
    {
        model_generic = model_params;
        list_column_generic = &list_columns_params;
        base_address = startAddress_params;
        disable_updateTableParams = 1;
    }

    quint16 baseIndex = start_address - base_address;

    // Update tables
    for (unsigned int i = 0, total = address_length; i < total; ++i)
    {
        // Disable tableView_params dataChanged connection
        if (disable_updateTableParams)
            disconnect(model_params, SIGNAL(dataChanged(QModelIndex, QModelIndex, QVector<int>)), this, SLOT(tableDataChanged_params(QModelIndex, QModelIndex, QVector<int>)));
        // Update model (params/process) - u16_val
        model_generic->setData(
            model_generic->index(baseIndex + i, list_column_generic->indexOf("val_modbus")),
            val_u16_list.at(i));
        // Re-enable tableView_params dataChanged connection
        if (disable_updateTableParams)
            connect(model_params, SIGNAL(dataChanged(QModelIndex, QModelIndex, QVector<int>)), this, SLOT(tableDataChanged_params(QModelIndex, QModelIndex, QVector<int>)));
        // Update model (params/process) - double_val
        computeValDoubleFromU16(model_generic, baseIndex + i);

        qDebug() << "RECEIVED: "
            << "id_addr: " << QString::number(model_params->data(model_params->index(baseIndex + i, list_columns_params.indexOf("id_address"))).toInt())
            << " - val_actual: " << QString::number(model_params->data(model_params->index(baseIndex + i, list_columns_params.indexOf("val_actual"))).toDouble())
            << " - val_modbus: " << QString::number(model_params->data(model_params->index(baseIndex + i, list_columns_params.indexOf("val_modbus"))).toInt());
    }

    // Update rest of GUI
    // STATUS WD 1
    if ((start_address <= address_sts_wd_1) && (start_address + address_length >= address_sts_wd_1))
    {
        STS_WD1 sts_wd_1; sts_wd_1.all = model_process->data(model_process->index(address_sts_wd_1, list_columns_process.indexOf("val_actual"))).toInt();
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
            m_ui->pushButton_start->setChecked(1);
            m_ui->label_impulsiAttivi->setStyleSheet("background-color: red");
            m_ui->label_ImpulsiSpenti->setStyleSheet("background-color: white");
        }
        else
        {
            m_ui->pushButton_start->setChecked(0);
            m_ui->label_impulsiAttivi->setStyleSheet("background-color: white");
            m_ui->label_ImpulsiSpenti->setStyleSheet("background-color: green");
        }
    }
    // ALARM WD 1
    if ((start_address <= address_alm_wd_1) && (start_address + address_length >= address_alm_wd_1))
    {
        ALM_WD1 alm_wd_1; alm_wd_1.all = model_process->data(model_process->index(address_alm_wd_1, list_columns_process.indexOf("val_actual"))).toInt();
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
    }
}

void MainWindow::calcChksm_CustomSerial10B(uint8_t* serial_tx, uint8_t* checksum)
{
    *checksum ^= *serial_tx;
}

void MainWindow::decodeUsartRx_CustomSerial10B(uint8_t* serial_rx, uint8_t artifact_bitwise)
{
    *serial_rx = (artifact_bitwise * 0x0A) + (*serial_rx * (1 - artifact_bitwise));
}

void MainWindow::handleError_CustomSerial10B(QSerialPort::SerialPortError error)
{
    if (m_serial)
    {
        if (error == QSerialPort::ResourceError)
        {
            QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
            closeSerialPort();
        }
    }
}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status_label_5->setText(message);
}

void MainWindow::blinkRxLabel()
{
    QTimer::singleShot(200, this, SLOT(blinkEndRxLabel()));
    m_status_label_1->setStyleSheet("background-color: green");
}

void MainWindow::blinkEndRxLabel()
{
    m_status_label_1->setStyleSheet("background-color: white");
}

void MainWindow::blinkTxLabel()
{
    QTimer::singleShot(200, this, SLOT(blinkEndTxLabelLabel()));
    m_status_label_2->setStyleSheet("background-color: green");
}

void MainWindow::blinkEndTxLabel()
{
    m_status_label_2->setStyleSheet("background-color: white");
}

void MainWindow::computeValU16FromDouble(QAbstractItemModel* model_generic, quint16 row)
{
    QStringList* list_column_generic = (model_generic == model_params) ? (&list_columns_params) : (&list_columns_process);
    double val_double = model_generic->data(model_generic->index(row, list_column_generic->indexOf("val_actual"))).toDouble();
    double kp_modbus = model_generic->data(model_generic->index(row, list_column_generic->indexOf("kp_to_modbus"))).toDouble();
    double val_min = model_generic->data(model_generic->index(row, list_column_generic->indexOf("val_min"))).toDouble();
    quint16 val_u16 = round((val_double - val_min) * kp_modbus);
    model_generic->setData(model_generic->index(row, list_column_generic->indexOf("val_modbus")), val_u16);
}

void MainWindow::computeValDoubleFromU16(QAbstractItemModel* model_generic, quint16 row)
{
    QStringList* list_column_generic = (model_generic == model_params) ? (&list_columns_params) : (&list_columns_process);
    quint16 val_u16 = model_generic->data(model_generic->index(row, list_column_generic->indexOf("val_modbus"))).toInt();
    double kp_modbus = model_generic->data(model_generic->index(row, list_column_generic->indexOf("kp_to_modbus"))).toDouble();
    double val_min = model_generic->data(model_generic->index(row, list_column_generic->indexOf("val_min"))).toDouble();
    double val_double = (val_u16 / kp_modbus) + val_min;
    model_generic->setData(model_generic->index(row, list_column_generic->indexOf("val_actual")), val_double);
}

void MainWindow::createDockWindows()
{
    m_ui->groupBox_controlloInverter->setMinimumWidth(180);
    m_ui->groupBox_controlloInverter->setMaximumHeight(120);
    QDockWidget* dock = new QDockWidget(tr("Controllo Inverter"), this);
    dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(m_ui->groupBox_controlloInverter);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock = new QDockWidget(tr("Stato Inverter"), this);
    dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable);
    dock->setWidget(m_ui->groupBox_statoInverter);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock = new QDockWidget(tr("Faults"), this);
    dock->setFeatures(dock->features() & ~QDockWidget::DockWidgetClosable);
    dock->setWidget(m_ui->groupBox_faults);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

#pragma region callbacks_modifica_dati

void MainWindow::pressed_ackFault()
{
    CMD_WD1 cmd_wd_1_temp; cmd_wd_1_temp.all = 0; cmd_wd_1_temp.bit.FAULT_ACK = 1;
    quint16 data_val = model_params->data(model_params->index((address_cmd_wd_1 - startAddress_params), list_columns_params.indexOf("val_actual"))).toInt();   // CMD_WD_1
    quint16 data_val_new = data_val | (cmd_wd_1_temp.all);
    model_params->setData(
        model_params->index((address_cmd_wd_1 - startAddress_params), list_columns_params.indexOf("val_actual")),
        data_val_new);
    QThread::msleep(500);
    data_val = data_val_new;
    data_val_new = data_val & ~(cmd_wd_1_temp.all);
    model_params->setData(
        model_params->index((address_cmd_wd_1 - startAddress_params), list_columns_params.indexOf("val_actual")),
        data_val_new);
}

void MainWindow::pressed_start()
{
    CMD_WD1 cmd_wd_1_temp; cmd_wd_1_temp.all = 0; cmd_wd_1_temp.bit.SWITCH_ON = 1;
    quint16 data_val = model_params->data(model_params->index((address_cmd_wd_1 - startAddress_params), list_columns_params.indexOf("val_actual"))).toInt();   // CMD_WD_1
    quint16 data_val_new = (m_ui->pushButton_start->isChecked() == 0) ? (data_val | (cmd_wd_1_temp.all)) : (data_val & ~(cmd_wd_1_temp.all));
    model_params->setData(
        model_params->index((address_cmd_wd_1 - startAddress_params), list_columns_params.indexOf("val_actual")),
        data_val_new);
}

#pragma endregion