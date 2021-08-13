#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    this->setStyleSheet("QMainWindow {background-color: rgba(200, 50, 100, 100%);}");

    radioButton1 = new QRadioButton(this);
    radioButton1->setGeometry(300, 200, 100, 50);
    radioButton1->setText("开关一");

    radioButton2 = new QRadioButton(this);
    radioButton2->setGeometry(400, 200, 100, 50);
    radioButton2->setText("开关二");

    //button mutex
    radioButton1->setChecked(false);
    radioButton1->setChecked(true);
}

MainWindow::~MainWindow()
{
}

