#include "mainwindow.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int fd;
//1.button click change color
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 472, 300);
    pushButton1 = new QPushButton("open", this);
    pushButton2 = new QPushButton("close", this);

    pushButton1->setGeometry(50, 50, 100, 100);
    pushButton2->setGeometry(150, 50, 100, 100);

    connect(pushButton1, SIGNAL(clicked()), this, SLOT(pushButton1_Clicked()));
    connect(pushButton2, SIGNAL(clicked()), this, SLOT(pushButton2_Clicked()));

    fd = open("/dev/xyz", O_RDWR);
    if (fd < 0)
    {
        printf("can't open!\n");
        return;
    }
}

void MainWindow::pushButton1_Clicked()
{
 /* 设置主窗口的样式 1 */
    this->setStyleSheet("QMainWindow { background-color: rgba(255, 245,238, 100%); }");

    int val = 1;
    write(fd, &val, 4);
}

void MainWindow::pushButton2_Clicked()
{
 /* 设置主窗口的样式 2 */
    this->setStyleSheet("QMainWindow { background-color: rgba(238, 122,233, 100%); }");
    int val = 0;
    write(fd, &val, 4);
}

MainWindow::~MainWindow()
{
}
