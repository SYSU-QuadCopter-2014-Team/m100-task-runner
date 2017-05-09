#include <QStringListModel>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasks/tasklistmodel.h"
#include "tasks/taskmanager.h"
#include "tasks/abstracttask.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringListModel * model = new QStringListModel(this);
    QStringList list;
    list << "Hello" << "World";
    model->setStringList(list);
    TaskManager taskManager(this);
    TaskListModel * taskListModel = taskManager.getTaskListModel();
    ui->tasksListView->setModel(taskListModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshPorts() {
    ui->portComboBox->clear();
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    QStringList list;
    for (int i = 0; i < ports.length(); ++i) {
        list.append(ports[i].portName());
    }
    ui->portComboBox->addItems(list);
}

bool MainWindow::openPort(QString portName, QString baudRate) {
    if (port == Q_NULLPTR) return false;
    port->setPortName(portName);
    driver->setBaudrate(baudRate.toInt());
    driver->init();
    return port->isOpen();
}

bool MainWindow::closePort() {
    if (port == Q_NULLPTR) return true;
    port->close();
    return !port->isOpen();
}

void MainWindow::on_refreshPortButton_clicked() {
    refreshPorts();
}

void MainWindow::on_openPortButton_clicked()
{
//    driver->init();
//    if (port->isOpen())
//        ui->btn_portOpen->setText(port->portName().append(" is open"));
//    else
//        ui->btn_portOpen->setText(port->portName().append(" not exit"));
    if (port == Q_NULLPTR) return;
    if (port->isOpen()) {
        // Close it
        closePort();
        ui->openPortButton->setText("Open");
        ui->portComboBox->setEnabled(true);
    } else {
        // Open selected port
        if (openPort(ui->portComboBox->currentText(), ui->baudrateEdit->text())) {
            ui->openPortButton->setText("Close");
            ui->portComboBox->setEnabled(false);
        }
    }
}
