#include <QStringList>
#include <QDebug>
#include "tasklistmodel.h"

TaskListModel::TaskListModel(QObject * parent) : QAbstractListModel(parent), mTasks(QList<QSharedPointer<AbstractTask>>()) {
}

QVariant TaskListModel::data(const QModelIndex &index, int role) const {
    qDebug() << role;
    if (!index.isValid()) {
        return QVariant();
    }
    if (role == Qt::DisplayRole) {
        return mTasks.value(index.row())->getName();
    }

    return QVariant();
}

int TaskListModel::rowCount(const QModelIndex &parent) const {
//    return mTasks.size();
    return 1;
}

int TaskListModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

void TaskListModel::setTaskList(const QList<QSharedPointer<AbstractTask>> & taskList) {
    beginResetModel();
    mTasks = taskList;
    endResetModel();
}
