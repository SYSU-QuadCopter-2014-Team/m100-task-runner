#ifndef SAMPLETASK_H
#define SAMPLETASK_H

#include <QString>
#include "abstracttask.h"

class SampleTask : public AbstractTask {
public:
    SampleTask();
    ~SampleTask();
    QString getName() const override;
};

#endif // SAMPLETASK_H
