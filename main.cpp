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
    w.show();
    return a.exec();
}
