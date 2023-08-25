#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <qpushbutton.h>

enum CommProtocol
{
    Modbus_RTU = 0,
    Modbus_TCP = 1,
    CustomSerial10B = 2
};

QT_BEGIN_NAMESPACE

namespace Ui {
class SettingsDialog;
}

class QIntValidator;

QT_END_NAMESPACE

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        CommProtocol protocol;
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        QString ipAddressAndPort;
        unsigned int modbusServerAddress = 1;
        unsigned int readInterval_ms = 1000;
        unsigned int responseTime_ms = 1000;
        unsigned int numberOfRetries = 3;
        bool localEchoEnabled;
    };
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();
    Settings settings() const;
    QPushButton* get_applyPushButton();

public slots:
    void showPortInfo(int idx);
    void apply();
    void checkCustomBaudRatePolicy(int idx);
    void checkCustomDevicePathPolicy(int idx);
    void onProtocolChanged(int idx);
    void applyButton_setUnchecked();

private:
    void fillPortsParameters();
    void fillPortsInfo();
    void updateSettings();

private:
    Ui::SettingsDialog *m_ui = nullptr;
    Settings m_currentSettings;
    QIntValidator *m_intValidator = nullptr;
};

#endif // SETTINGSDIALOG_H
