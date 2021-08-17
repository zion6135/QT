#include "mainwindow.h"
#include <QList>
#include "Class/LedWindow.h"


bool LedWindow::openLedDrv() {
    fd = open("/dev/xyz", O_RDWR);
    if (fd < 0) {
        qDebug("open dev failed!!!");
        return false;
    }
    return true;
}

LedWindow::LedWindow(QWidget *parent)
    : QMainWindow(parent)
{
    if (true == openLedDrv()) {
        this->setGeometry(0, 0, 472, 300);

        pushButtonBack = new QPushButton("Back", this);
        pushButtonBack->setObjectName("btnBack");
        pushButtonBack ->setGeometry(10, 10, 60, 30);
        connect(pushButtonBack, SIGNAL(clicked()), this, SLOT(ButtonLedclicked()));

        pushButton[0] = new QPushButton("LED1 open", this);
        pushButton[0]->setObjectName("btn1");
        pushButton[0] ->setGeometry(50, 50, 100, 100);
        connect(pushButton[0], SIGNAL(clicked()), this, SLOT(ButtonLedclicked()));

        pushButton[1] = new QPushButton("LED2 open", this);
        pushButton[1]->setObjectName("btn2");
        pushButton[1] ->setGeometry(150, 50, 100, 100);
        connect(pushButton[1], SIGNAL(clicked()), this, SLOT(ButtonLedclicked()));

        pushButton[2] = new QPushButton("LED3 open", this);
        pushButton[2]->setObjectName("btn3");
        pushButton[2] ->setGeometry(250, 50, 100, 100);
        connect(pushButton[2], SIGNAL(clicked()), this, SLOT(ButtonLedclicked()));

        pushButton[3] = new QPushButton("LED4 close", this);
        pushButton[3]->setObjectName("btn4");
        pushButton[3] ->setGeometry(50, 150, 100, 100);
        connect(pushButton[3], SIGNAL(clicked()), this, SLOT(ButtonLedclicked()));

        pushButton[4] = new QPushButton("LED5 close", this);
        pushButton[4]->setObjectName("btn5");
        pushButton[4] ->setGeometry(150, 150, 100, 100);
        connect(pushButton[4], SIGNAL(clicked()), this, SLOT(ButtonLedclicked()));

        pushButton[5] = new QPushButton("LED6 close", this);
        pushButton[5]->setObjectName("btn6");
        pushButton[5] ->setGeometry(250, 150, 100, 100);
        connect(pushButton[5], SIGNAL(clicked()), this, SLOT(ButtonLedclicked()));
    } else {
        qDebug("open failed");
    }
}

void LedWindow::ButtonLedclicked() {

    QObject* obj = sender();
//    obj->dumpObjectInfo();
    int val = -1;
   if (obj->objectName() == "btn1") {
       qDebug("1");
       val = 1;
       ::write(fd, &val, 4);
   } else if (obj->objectName() == "btn2") {
       qDebug("2");
       val = 2;
       ::write(fd, &val, 4);
   } else if (obj->objectName() == "btn3") {
       qDebug("3");
       val = 3;
       ::write(fd, &val, 4);
   } else if (obj->objectName() == "btn4") {
       qDebug("4");
       val = 4;
       ::write(fd, &val, 4);
   } else if (obj->objectName() == "btn5") {
       qDebug("5");
       val = 5;
       ::write(fd, &val, 4);
   } else if (obj->objectName() == "btn6") {
       qDebug("6");
       val = 6;
       ::write(fd, &val, 4);
   } else if (obj->objectName() == "btnBack") {
       qDebug("7");
       emit signaltomain();
       this->close();
   }

}


