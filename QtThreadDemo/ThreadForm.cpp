
/* Copyright 2013 EDWARD.HUNG */

#include "ThreadForm.h"

QtThreadDemo::QtThreadDemo(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);
    connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(event_a()));
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(event_b()));
    connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(event_c()));

    // create the qobject and qthread
    worker_ = new QWorker();
    dummy_ = new QDummy();
    work_thread_1 = new QThread();
    work_thread_2 = new QThread();
    // move the qobject to qthread
    worker_->moveToThread(work_thread_1);
    dummy_->moveToThread(work_thread_2);

    // connect the signal and slot
    connect(this, SIGNAL(send_event_a()), worker_, SLOT(receive_event_a()));
    connect(this, SIGNAL(send_event_b()), dummy_, SLOT(receive_event_b()));
    connect(this, SIGNAL(send_event_c()), dummy_, SLOT(receive_event_c()));
    connect(dummy_, SIGNAL(send_event_to_worker()),
        worker_, SLOT(receive_event_from_dummy()));
//  // or
//     connect(this, SIGNAL(send_event_c()),
//         dummy_, SLOT(send_event_to_worker()));

    // start the thread
    work_thread_1->start();
    work_thread_2->start();
}

QtThreadDemo::~QtThreadDemo(void)
{
    // disconnect the signal and slot
    disconnect(this, SIGNAL(send_event_a()), worker_, SLOT(receive_event_a()));
    disconnect(this, SIGNAL(send_event_b()), dummy_, SLOT(receive_event_b()));
    disconnect(dummy_, SIGNAL(send_event_to_worker()),
        worker_, SLOT(receive_event_from_dummy()));

    // stop the qthread
    if (work_thread_1 != NULL)
    {
        work_thread_1->terminate();
        work_thread_1->wait();
    }
    if (work_thread_2 != NULL)
    {
        work_thread_2->terminate();
        work_thread_2->wait();
    }

    // delete the data
    delete worker_;
    delete dummy_;
    worker_ = NULL;
    dummy_ = NULL;

    delete work_thread_1;
    delete work_thread_2;
    work_thread_1 = NULL;
    work_thread_2 = NULL;
}

void QtThreadDemo::event_a(void)
{
    qDebug() << QThread::currentThreadId();

    emit send_event_a();
}

void QtThreadDemo::event_b(void)
{
    qDebug() << QThread::currentThreadId();

    emit send_event_b();
}
void QtThreadDemo::event_c(void)
{
    qDebug() << QThread::currentThreadId();

    emit send_event_c();
}