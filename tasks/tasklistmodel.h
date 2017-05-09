#ifndef TASKLISTMODEL_H
#define TASKLISTMODEL_H

#include <QAbstractListModel>
#include <QSharedPointer>
#include "abstracttask.h"

class TaskListModel : public QAbstractListModel {
public:
    TaskListModel(QObject * = Q_NULLPTR);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setTaskList(const QList<QSharedPointer<AbstractTask>> & taskList);
private:
    QList<QSharedPointer<AbstractTask> > mTasks;
};

#endif // TASKLISTMODEL_H
