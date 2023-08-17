#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void writeData(const QByteArray& data);
    void readData();
    void synchronizeParams();
    void askToReadParam();
    void calc_chksm(uint8_t* serial_tx, uint8_t* checksum);
    void decode_usart_rx(uint8_t* serial_rx, uint8_t artifact_bitwise);
    void handleError(QSerialPort::SerialPortError error);
    void tableDataChanged_params(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles);
    void onSettingsChanged();
    void onModbusStateChanged(int state);
    void pressed_ackFault();
    void pressed_start();

private:
    void initActionsConnections();
    void sendDataThroughSerial(unsigned int cmd, unsigned int data_tx, unsigned int data_id);
    void showStatusMessage(const QString& message);
    void refreshData(unsigned int data_id, unsigned int data_idx);
    void MainWindow::sendModbusRequest(int start_address, int address_length, int cmd);
    void onReadReady();
    void MainWindow::computeValU16FromDouble(QAbstractItemModel* model_generic, int row);
    void MainWindow::computeValDoubleFromU16(QAbstractItemModel* model_generic, int row);

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
    SettingsDialog *m_settings = nullptr;
    QTimer* m_serialScanTimer;
    QTimer* m_serialReadParams;
    QStringList list_columns_params;
    QStringList list_row_params;
    QStringList list_columns_process;
    QStringList list_row_process;
    QSerialPort* m_serial = nullptr;
    QModbusReply* lastRequest = nullptr;
    QModbusClient* modbusDevice = nullptr;
    int process_startAddress = 0;
    int params_startAddress = 0;
};

#endif // MAINWINDOW_H
