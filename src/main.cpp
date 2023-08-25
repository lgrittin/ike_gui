#define __MAIN__

#include "mainwindow.h"
#include "globals.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(IKE_gui);
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("IKE GUI");
    w.setWindowIcon(QIcon(":/images/icons8-microchip-64.png"));
    w.show();
    return a.exec();
}
