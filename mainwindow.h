#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QDebug>
#include <QThread>

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
    void handleError(QSerialPort::SerialPortError error);

    //void valueChanged_valApertura();
    void pressed_ackFault();
    void pressed_start();
    void pressed_aperturaMan();
    void valueChanged_valApertura();
    void valueChanged_valAperturaRidotta50();
    void valueChanged_valAperturaRidotta60();
    void valueChanged_durataApRidottaCheck();
    void valueChanged_velRampa();
    void pressed_enSweep();

private:
    void initActionsConnections();
    void sendDataThroughSerial(unsigned int cmd, QByteArray data_tx, unsigned int data_id);

private:
    void showStatusMessage(const QString &message);

    Ui::MainWindow *m_ui = nullptr;
    QLabel* m_status_label_1 = nullptr;
    QLabel* m_status_label_2 = nullptr;
    QLabel* m_status_label_3 = nullptr;
    QLabel* m_status_label_4 = nullptr;
    QLabel* m_status_label_5 = nullptr;
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;
    QTimer* m_serialScanTimer;
    QTimer* m_serialReadParams;
};

#endif // MAINWINDOW_H
