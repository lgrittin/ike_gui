#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingsdialog.h"
#include "freezetablewidget.h"
#include "delegate.h"
#include "globals.h"

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <QStandardItemModel>
#include <QModbusDataUnit>

enum ParamProcess
{
    Param = 0,
    Process = 1
};

QT_BEGIN_NAMESPACE

class QLabel;
class QModbusClient;
class QModbusReply;

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

//class Console;
class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void receiveMessage_CustomSerial10B();
    void readAll();
    void readProcessParam();
    void calcChksm_CustomSerial10B(uint8_t* serial_tx, uint8_t* checksum);
    void decodeUsartRx_CustomSerial10B(uint8_t* serial_rx, uint8_t artifact_bitwise);
    void handleError_CustomSerial10B(QSerialPort::SerialPortError error);
    void tableDataChanged_params(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles);
    void sendRequest_Modbus(quint16 start_address, quint16 address_length, int cmd);
    void onSettingsChanged();
    void onModbusStateChanged(int state);
    void blinkEndRxLabel();
    void blinkEndTxLabel();
    void pressed_ackFault();
    void pressed_start();

private:
    void initActionsConnections();
    void sendRequest_CustomSerial10B(quint16 start_address, quint16 address_length, int cmd);
    void showStatusMessage(const QString& message);
    void autoChangePressParameter();
    void readParam();
    void blinkRxLabel();
    void blinkTxLabel();
    void refreshData(quint16 start_address, quint16 address_length, QVector<quint16> val_u16_list);
    void receiveMessage_Modbus();
    void computeValU16FromDouble(QAbstractItemModel* model_generic, quint16 row);
    void computeValDoubleFromU16(QAbstractItemModel* model_generic, quint16 row);
    void createDockWindows();

    Ui::MainWindow *m_ui = nullptr;
    QLabel* m_status_label_1 = nullptr;
    QLabel* m_status_label_2 = nullptr;
    QLabel* m_status_label_3 = nullptr;
    QLabel* m_status_label_4 = nullptr;
    QLabel* m_status_label_5 = nullptr;
    QStandardItemModel* model_params = nullptr;
    QStandardItemModel* model_process = nullptr;
    FreezeTableWidget* tableView_params = nullptr;
    FreezeTableWidget* tableView_process = nullptr;
    SpinBoxDelegate* delegate_doubleSpinBox_params;
    SettingsDialog *m_settings = nullptr;
    QTimer* timer_serialReadParamsData;
    QTimer* timer_serialReadProcessData;
    QStringList list_columns_params;
    QStringList list_row_params;
    QStringList list_columns_process;
    QStringList list_row_process;
    QSerialPort* m_serial = nullptr;
    QModbusReply* lastRequest = nullptr;
    QModbusClient* modbusDevice = nullptr;
    quint16 startAddress_process = 0;
    quint16 startAddress_params = 0;
    quint16 address_sts_wd_1 = 0;
    quint16 address_alm_wd_1 = 0;
    quint16 address_cmd_wd_1 = 0;
};

#endif // MAINWINDOW_H
