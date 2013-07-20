
/* Copyright 2013 EDWARD.HUNG */

#ifndef QTTHREADDEMO_QDUMMY_H
#define QTTHREADDEMO_QDUMMY_H

#include <QObject>

class QDummy: public QObject
{
    Q_OBJECT

 public:
    QDummy(QObject *parent = NULL): QObject(parent) {};
    ~QDummy(void) {};

 signals:
    void send_event_to_worker(void);
 private slots:
     void receive_event_b(void);
     void receive_event_c(void);
};

#endif  // QTTHREADDEMO_QDUMMY_H
