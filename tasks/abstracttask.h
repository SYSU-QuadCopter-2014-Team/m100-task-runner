#ifndef ABSTRACT_TASK_H
#define ABSTRACT_TASK_H

#include <QMetaType>

class AbstractTask {
public:
    AbstractTask() {}
    virtual ~AbstractTask() {}
    virtual QString getName() const = 0;
};

#endif // ABSTRACT_TASK_H
