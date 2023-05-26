#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT

public slots:
    void doTask() {
        // Code for the task
    }
};

#endif // WORKER_H
