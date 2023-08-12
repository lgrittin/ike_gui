#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE

class QLabel;

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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();
    void synchronizeParams();
    void askToReadParam();
    void calc_chksm(uint8_t* serial_tx, uint8_t* checksum);
    void decode_usart_rx(uint8_t* serial_rx, uint8_t artifact_bitwise);
    void handleError(QSerialPort::SerialPortError error);
    void tableDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles);


    //void valueChanged_valApertura();
    void pressed_ackFault();
    void pressed_start();
    void pressed_aperturaMan();
    void valueChanged_valApertura();
    void valueChanged_valAperturaFinale();
    void valueChanged_valAperturaRidotta50();
    void valueChanged_valAperturaRidotta60();
    void valueChanged_durataApRidottaCheck();
    void valueChanged_velRampa();
    void pressed_enSweep();
    void valueChanged_freqPrincipale();
    void valueChanged_ampModSweep();
    void valueChanged_freqModSweep();
    void valueChanged_vInvRectGain();
    void valueChanged_vInvRectOffset();
    void valueChanged_iInvRectGain();
    void valueChanged_iInvRectOffset();
    void valueChanged_ntc1Gain();
    void valueChanged_ntc1Offset();
    void valueChanged_ntc2Gain();
    void valueChanged_ntc2Offset();
    void valueChanged_potGain();
    void valueChanged_potOffset();
    void pressed_enProtOvercurr();
    void valueChanged_valOvercurr();

private:
    void initActionsConnections();
    void sendDataThroughSerial(unsigned int cmd, QByteArray data_tx, unsigned int data_id);
    void showStatusMessage(const QString &message);
    void refreshData(unsigned int data_id, unsigned int data_idx);
    //void setBlink(void);
    //void data(void);
    //void resetBlink(void);

    Ui::MainWindow *m_ui = nullptr;
    QLabel* m_status_label_1 = nullptr;
    QLabel* m_status_label_2 = nullptr;
    QLabel* m_status_label_3 = nullptr;
    QLabel* m_status_label_4 = nullptr;
    QLabel* m_status_label_5 = nullptr;
    QStandardItemModel* model = nullptr;
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;
    QTimer* m_serialScanTimer;
    QTimer* m_serialReadParams;
    QStringList list_columns;
    QStringList list_row;
};

#endif // MAINWINDOW_H
