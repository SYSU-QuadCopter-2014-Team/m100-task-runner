#include "taskmanager.h"
#include "sampletask.h"

TaskManager::TaskManager(QObject * parent) : mTaskListModel(parent) {
    // Init tasks
    initTasks();
}

TaskListModel * TaskManager::getTaskListModel() {
    return &mTaskListModel;
}

void TaskManager::initTasks() {
    QList<QSharedPointer<AbstractTask> > taskList;
    QSharedPointer<AbstractTask> sampleTask(new SampleTask());
    taskList.append(sampleTask);
    mTaskListModel.setTaskList(taskList);
}
