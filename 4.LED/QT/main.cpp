#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
     char val[100] = "excuseme";
     printf("xxxx%s\n", val);
    return a.exec();
}
