#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingsdialog.h"
#include "freezetablewidget.h"
#include "delegate.h"
#include "globals.h"

#include <QMainWindow>
#include <QSerialPort>
#include <qmodbusdevice.h>
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

#define MIN_DB_SIZE 200  // Byte

enum error_db
{
    NO_ERRORS = 0,
    FILES_CSV_NOT_FOUND = 1,
    FILES_CSV_NOT_VALID = 2,
    PARAMS_PROCESS_VERSION_DIVERGENT = 3
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
    void handleError_Modbus(QModbusDevice::Error error);
    void onSettingsChanged();
    void resetData();
    void onModbusStateChanged(int state);
    void blinkEndRxLabel();
    void blinkEndTxLabel();
    void pressed_ackFault();
    void pressed_start();
    void pressed_stop();
    void reset_ackFault();
    void onLoadDatabase();

private:
    void initActionsConnections();
    void sendRequest_CustomSerial10B(quint16 start_address, quint16 address_length, int cmd);
    void showStatusMessage(const QString& message);
    void autoChangePressParameter();
    void readParam();
    void writeParam();
    void blinkRxLabel();
    void blinkTxLabel();
    void refreshData(quint16 start_address, quint16 address_length, QVector<quint16> val_u16_list);
    void receiveMessage_Modbus();
    void computeValU16FromDouble(QAbstractItemModel* model_generic, quint16 row);
    void computeValDoubleFromU16(QAbstractItemModel* model_generic, quint16 row);
    void createDockWindows();
    void createCentralWidget();
    error_db setupModelAndTables(bool default_db);

    Ui::MainWindow *m_ui = nullptr;
    QLabel* m_status_label_rx_blink = nullptr;
    QLabel* m_status_label_tx_blink = nullptr;
    QLabel* m_status_label_tx_chksm_num = nullptr;
    QLabel* m_status_label_rx_chksm_num = nullptr;
    QLabel* m_status_label_debug_msg = nullptr;
    QLabel* m_status_label_dbVersion = nullptr;
    QStandardItemModel* model_params = nullptr;
    QStandardItemModel* model_process = nullptr;
    FreezeTableWidget* tableView_params = nullptr;
    FreezeTableWidget* tableView_process = nullptr;
    SpinBoxDelegate* delegate_doubleSpinBox_params;
    SettingsDialog *m_settings = nullptr;
    //QTimer* timer_serialReadParamsData;
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
    quint16 address_datetime_sec = 0;
    quint16 address_datetime_min = 0;
    quint16 address_datetime_hour = 0;
    quint16 address_datetime_day = 0;
    quint16 address_datetime_dayOfWeek = 0;
    quint16 address_datetime_month = 0;
    quint16 address_datetime_year = 0;
    quint16 address_fmwVers = 0;
    quint16 address_dbVers = 0;
    quint16 address_cmd_wd_1 = 0;
    quint16 read_sequence = 0;
    unsigned int comm_error_rx_num = 0;
    unsigned int comm_error_tx_num = 0;
    FMW_VERSION device_fmwVersion;
    DB_VERSION gui_dbVersion;
    DB_VERSION device_dbVersion;
};

#endif // MAINWINDOW_H
