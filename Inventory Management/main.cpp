#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Storage main;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
