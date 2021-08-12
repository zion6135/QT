#include "mainwindow.h"

//1.button click change color
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 472, 300);
    pushButton1 = new QPushButton("Color A", this);
    pushButton2 = new QPushButton("Color B", this);

    pushButton1->setGeometry(50, 50, 100, 100);
    pushButton2->setGeometry(150, 50, 100, 100);

    connect(pushButton1, SIGNAL(clicked()), this, SLOT(pushButton1_Clicked()));
    connect(pushButton2, SIGNAL(clicked()), this, SLOT(pushButton2_Clicked()));
}

void MainWindow::pushButton1_Clicked()
{
 /* 设置主窗口的样式 1 */
    this->setStyleSheet("QMainWindow { background-color: rgba(255, 245,238, 100%); }");
}

void MainWindow::pushButton2_Clicked()
{
 /* 设置主窗口的样式 2 */
    this->setStyleSheet("QMainWindow { background-color: rgba(238, 122,233, 100%); }");
}

MainWindow::~MainWindow()
{
}
