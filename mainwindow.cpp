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
