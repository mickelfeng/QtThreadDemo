
/* Copyright 2013 EDWARD.HUNG */

#ifndef QTTHREADDEMO_QWORKER_H
#define QTTHREADDEMO_QWORKER_H

#include <QObject>
#include <QProcess>

class QWorker: public QObject
{
    Q_OBJECT

 public:
     QWorker(QObject *parent = NULL):
        QObject(parent), proc_ls_(NULL) {};
    ~QWorker(void);

    QProcess *proc_ls_;

 private slots:
    void receive_event_a(void);
    void read_the_output(void);
    void receive_event_from_dummy(void);
};

#endif  // QTTHREADDEMO_QWORKER_H
