#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QonboardSDK.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void refreshPorts();
    bool openPort(QString portName, QString baudRate);
    bool closePort();
    Ui::MainWindow *ui;
    CoreAPI *api;
    QtOnboardsdkPortDriver *driver;
    QSerialPort *port;

private slots:
    void on_refreshPortButton_clicked();
    void on_openPortButton_clicked();
};

#endif // MAINWINDOW_H
