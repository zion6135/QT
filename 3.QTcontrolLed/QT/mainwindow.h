#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
using namespace std;
#ifndef nullptr
#define nullptr NULL
#endif
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MainWindow *ui;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
private slots:
    void pushButton1_Clicked();
    void pushButton2_Clicked();
};
#endif // MAINWINDOW_H
