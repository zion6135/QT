#ifndef LEDWINDOW_H
#define LEDWINDOW_H

#include <QMainWindow>
#include <QPushButton>

/**********LED Drv*****************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef nullptr
#define nullptr NULL
#endif
class LedWindow : public QMainWindow
{
    Q_OBJECT

public:
    LedWindow(QWidget *parent = nullptr);
    ~LedWindow(){
        qDebug("Led close");
    };
signals:
    void signaltomain();
private:
    QPushButton *pushButton[6];
    QPushButton *pushButtonBack;

    bool openLedDrv();
    int fd;
private slots:
    void ButtonLedclicked();
};

#endif // LEDWINDOW_H
