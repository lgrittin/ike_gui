#define __MAIN__

#include "mainwindow.h"
#include "globals.h"
#include <iostream>
#include <cstdlib>

#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(IKE_gui);
    QApplication a(argc, argv);
    try
    {
        MainWindow w;
        w.setWindowTitle("IKE GUI");
        w.setWindowIcon(QIcon(":/images/icons8-microchip-64.png"));
        w.show();
        return a.exec();
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << endl;
        return -1;
    }
}
