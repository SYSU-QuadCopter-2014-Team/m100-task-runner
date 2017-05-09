#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include "tasklistmodel.h"

class TaskManager : public QObject {
    Q_OBJECT
public:
    TaskManager(QObject * = Q_NULLPTR);
    TaskListModel * getTaskListModel();
private:
    void initTasks();
    TaskListModel mTaskListModel;
};

#endif // TASKMANAGER_H
