#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <Class/LedWindow.h>

#ifndef nullptr
#define nullptr NULL
#endif

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void ButtonToMain();

private:
    QPushButton *pushButtonLed;
private slots:
    void ButtonToLed();
};


#endif // MAINWINDOW_H
