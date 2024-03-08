#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QIntValidator>
#include <QLineEdit>
#include <QSerialPortInfo>

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::SettingsDialog),
    m_intValidator(new QIntValidator(0, 4000000, this))
{
    m_ui->setupUi(this);
    m_ui->baudRateBox->setInsertPolicy(QComboBox::NoInsert);

    connect(m_ui->applyButton, &QPushButton::clicked, this, &SettingsDialog::apply);
    connect(m_ui->serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::showPortInfo);
    connect(m_ui->baudRateBox,  QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::checkCustomBaudRatePolicy);
    connect(m_ui->serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::checkCustomDevicePathPolicy);
    connect(m_ui->protocolListBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::onProtocolChanged);

    connect(m_ui->protocolListBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->parityBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->baudRateBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->baudRateBox, &QComboBox::currentTextChanged, this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->dataBitsBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->stopBitsBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->flowControlBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->ipPortLineEdit, &QLineEdit::textChanged, this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->localEchoCheckBox, QOverload<int>::of(&QCheckBox::stateChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->readIntervalSpinner, QOverload<int>::of(&QSpinBox::valueChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->retriesSpinner, QOverload<int>::of(&QSpinBox::valueChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->timeoutSpinner, QOverload<int>::of(&QSpinBox::valueChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->modbusServerAddressSpinner, QOverload<int>::of(&QSpinBox::valueChanged), this, &SettingsDialog::applyButton_setUnchecked);
    connect(m_ui->pushButton_rescanSerialPorts, &QPushButton::clicked, this, &SettingsDialog::fillPortsInfo);

    fillPortsParameters();
    fillPortsInfo();

    updateSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete m_ui;
}

SettingsDialog::Settings SettingsDialog::settings() const
{
    return m_currentSettings;
}

void SettingsDialog::showPortInfo(int idx)
{
    if (idx == -1)
        return;

    const QStringList list = m_ui->serialPortInfoListBox->itemData(idx).toStringList();
    m_ui->descriptionLabel->setText(tr("Description: %1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    m_ui->manufacturerLabel->setText(tr("Manufacturer: %1").arg(list.count() > 2 ? list.at(2) : tr(blankString)));
    m_ui->serialNumberLabel->setText(tr("Serial number: %1").arg(list.count() > 3 ? list.at(3) : tr(blankString)));
    m_ui->locationLabel->setText(tr("Location: %1").arg(list.count() > 4 ? list.at(4) : tr(blankString)));
    m_ui->vidLabel->setText(tr("Vendor Identifier: %1").arg(list.count() > 5 ? list.at(5) : tr(blankString)));
    m_ui->pidLabel->setText(tr("Product Identifier: %1").arg(list.count() > 6 ? list.at(6) : tr(blankString)));
}

void SettingsDialog::apply()
{
    updateSettings();
    m_ui->applyButton->setEnabled(0);
}

void SettingsDialog::applyButton_setUnchecked()
{
    m_ui->applyButton->setEnabled(1);
}

void SettingsDialog::checkCustomBaudRatePolicy(int idx)
{
    const bool isCustomBaudRate = !m_ui->baudRateBox->itemData(idx).isValid();
    m_ui->baudRateBox->setEditable(isCustomBaudRate);
    if (isCustomBaudRate) {
        m_ui->baudRateBox->clearEditText();
        QLineEdit *edit = m_ui->baudRateBox->lineEdit();
        edit->setValidator(m_intValidator);
    }
}

void SettingsDialog::checkCustomDevicePathPolicy(int idx)
{
    const bool isCustomPath = !m_ui->serialPortInfoListBox->itemData(idx).isValid();
    m_ui->serialPortInfoListBox->setEditable(isCustomPath);
    if (isCustomPath)
        m_ui->serialPortInfoListBox->clearEditText();
}

void SettingsDialog::fillPortsParameters()
{
    m_ui->protocolListBox->addItem(tr("Modbus_RTU"));
    m_ui->protocolListBox->addItem(tr("Modbus_TCP"));
    m_ui->protocolListBox->addItem(tr("CustomSerial10B"));

    m_ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    m_ui->baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    m_ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    m_ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    m_ui->baudRateBox->addItem(tr("Custom"));
    m_ui->baudRateBox->setCurrentIndex(4);
    m_ui->baudRateBox->setCurrentText("250000");

    m_ui->dataBitsBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    m_ui->dataBitsBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    m_ui->dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    m_ui->dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    m_ui->dataBitsBox->setCurrentIndex(3);

    m_ui->parityBox->addItem(tr("None"), QSerialPort::NoParity);
    m_ui->parityBox->addItem(tr("Even"), QSerialPort::EvenParity);
    m_ui->parityBox->addItem(tr("Odd"), QSerialPort::OddParity);
    m_ui->parityBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    m_ui->parityBox->addItem(tr("Space"), QSerialPort::SpaceParity);
    m_ui->parityBox->setCurrentIndex(1);

    m_ui->stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    m_ui->stopBitsBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    m_ui->stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    m_ui->flowControlBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    m_ui->flowControlBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    m_ui->flowControlBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);

    m_ui->ipPortLineEdit->setText(tr("127.0.0.1:502"));
    m_ui->readIntervalSpinner->setValue(1000);
    m_ui->retriesSpinner->setValue(3);
    m_ui->timeoutSpinner->setValue(1000);
    m_ui->modbusServerAddressSpinner->setValue(1);
}

QPushButton* SettingsDialog::get_applyPushButton()
{
    return m_ui->applyButton;
}

void SettingsDialog::onProtocolChanged(int idx)
{
    switch (idx)
    {
    case Modbus_RTU:
        m_ui->tcpGroupBox->setEnabled(0);
        m_ui->selectBox->setEnabled(1);
        m_ui->parametersBox->setEnabled(1);
        m_ui->flowControlBox->setEnabled(0);
        m_ui->timeoutSpinner->setEnabled(1);
        m_ui->retriesSpinner->setEnabled(1);
        m_ui->readIntervalSpinner->setEnabled(1);
        m_ui->modbusServerAddressSpinner->setEnabled(1);
        break;
    case Modbus_TCP:
        m_ui->tcpGroupBox->setEnabled(1);
        m_ui->selectBox->setEnabled(0);
        m_ui->parametersBox->setEnabled(0);
        m_ui->flowControlBox->setEnabled(0);
        m_ui->timeoutSpinner->setEnabled(1);
        m_ui->retriesSpinner->setEnabled(1);
        m_ui->readIntervalSpinner->setEnabled(1);
        m_ui->modbusServerAddressSpinner->setEnabled(1);
        break;
    case CustomSerial10B:
        m_ui->tcpGroupBox->setEnabled(0);
        m_ui->selectBox->setEnabled(1);
        m_ui->parametersBox->setEnabled(1);
        m_ui->flowControlBox->setEnabled(1);
        m_ui->timeoutSpinner->setEnabled(0);
        m_ui->retriesSpinner->setEnabled(0);
        m_ui->readIntervalSpinner->setEnabled(0);
        m_ui->modbusServerAddressSpinner->setEnabled(0);
        break;
    default:
        break;
    }
}

void SettingsDialog::fillPortsInfo()
{
    m_ui->serialPortInfoListBox->clear();
    QString description;
    QString manufacturer;
    QString serialNumber;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        m_ui->serialPortInfoListBox->addItem(list.first(), list);
    }

    m_ui->serialPortInfoListBox->addItem(tr("Custom"));
}

void SettingsDialog::updateSettings()
{
    m_currentSettings.name = m_ui->serialPortInfoListBox->currentText();

    if (m_ui->baudRateBox->currentIndex() == 4) {
        m_currentSettings.baudRate = m_ui->baudRateBox->currentText().toInt();
    } else {
        m_currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                    m_ui->baudRateBox->itemData(m_ui->baudRateBox->currentIndex()).toInt());
    }
    m_currentSettings.stringBaudRate = QString::number(m_currentSettings.baudRate);
    m_currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                m_ui->dataBitsBox->itemData(m_ui->dataBitsBox->currentIndex()).toInt());
    m_currentSettings.stringDataBits = m_ui->dataBitsBox->currentText();
    m_currentSettings.parity = static_cast<QSerialPort::Parity>(
                m_ui->parityBox->itemData(m_ui->parityBox->currentIndex()).toInt());
    m_currentSettings.stringParity = m_ui->parityBox->currentText();
    m_currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                m_ui->stopBitsBox->itemData(m_ui->stopBitsBox->currentIndex()).toInt());
    m_currentSettings.stringStopBits = m_ui->stopBitsBox->currentText();
    m_currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(
                m_ui->flowControlBox->itemData(m_ui->flowControlBox->currentIndex()).toInt());
    m_currentSettings.stringFlowControl = m_ui->flowControlBox->currentText();
    m_currentSettings.localEchoEnabled = m_ui->localEchoCheckBox->isChecked();
    m_currentSettings.protocol = (CommProtocol)m_ui->protocolListBox->currentIndex();
    m_currentSettings.ipAddressAndPort = m_ui->ipPortLineEdit->text();
    m_currentSettings.responseTime_ms = m_ui->timeoutSpinner->value();
    m_currentSettings.numberOfRetries = m_ui->retriesSpinner->value();
    m_currentSettings.readInterval_ms = m_ui->readIntervalSpinner->value();
    m_currentSettings.modbusServerAddress = m_ui->modbusServerAddressSpinner->value();
}