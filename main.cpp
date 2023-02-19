#define __MAIN__

#include "mainwindow.h"
#include <QApplication>
#include "globals.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("IKE GUI");
    w.show();
    return a.exec();
}
