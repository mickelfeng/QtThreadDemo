
/* Copyright 2013 EDWARD.HUNG */

#include <QThread>
#include <QDebug>

#include "qdummy.h"

void QDummy::receive_event_b(void)
{
    qDebug() << QThread::currentThreadId();
}

void QDummy::receive_event_c(void)
{
    qDebug() << QThread::currentThreadId();

    emit send_event_to_worker();
}