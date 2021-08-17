#include "mainwindow.h"
#include <QList>
#include "Class/LedWindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 472, 300);
    pushButtonLed = new QPushButton("LED", this);
    pushButtonLed->setGeometry(50, 50, 100, 100);
    connect(pushButtonLed, SIGNAL(clicked()), this, SLOT(ButtonToLed()));
}

void MainWindow::ButtonToLed() {
    LedWindow* mLed = new LedWindow();
    mLed->show();
    connect(mLed, SIGNAL(signaltomain()), this, SLOT(ButtonToMain()));

    this->hide();
    qDebug("To Led");
}

void MainWindow::ButtonToMain() {
    this->show();
    qDebug("To main");
}


MainWindow::~MainWindow()
{

}


