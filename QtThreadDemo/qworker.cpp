
/* Copyright 2013 EDWARD.HUNG */

#include <QThread>
#include <QDebug>

#include "qworker.h"

QWorker::~QWorker()
{
    if (proc_ls_ != NULL)
    {
        disconnect(proc_ls_, SIGNAL(readyRead()), this, SLOT(read_the_output()));
        if (proc_ls_->state() != QProcess::NotRunning)
        {
            proc_ls_->kill();
            proc_ls_->waitForFinished();
        }
        delete proc_ls_;
        proc_ls_ = NULL;
    }
}

void QWorker::receive_event_a(void)
{
    qDebug() << QThread::currentThreadId();

    if (proc_ls_ == NULL)
    {
        proc_ls_ = new QProcess;
        connect(proc_ls_, SIGNAL(readyRead()), this, SLOT(read_the_output()));
    }
    proc_ls_->start("dir");
}

void QWorker::read_the_output(void)
{
    qDebug() << QThread::currentThreadId();

    QByteArray _buffer = proc_ls_->readAll();
    if (!_buffer.isEmpty())
    {
        // do something
    }
    else
    {

    }
}

void QWorker::receive_event_from_dummy(void)
{
    qDebug() << QThread::currentThreadId();
}