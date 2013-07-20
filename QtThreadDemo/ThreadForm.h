
/* Copyright 2013 EDWARD.HUNG */

#ifndef QTTHREADDEMO_THREADFORM_H
#define QTTHREADDEMO_THREADFORM_H

#include <QtGui/QMainWindow>
#include <QThread>
#include <QDebug>

#include "ui_ThreadForm.h"
#include "qworker.h"
#include "qdummy.h"

class QtThreadDemo : public QMainWindow
{
    Q_OBJECT

 public:
    QtThreadDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QtThreadDemo();

 private:
    Ui::ThreadDemo ui;
    QThread *work_thread_1;
    QThread *work_thread_2;
    QWorker *worker_;
    QDummy *dummy_;
 signals:
    void send_event_a(void);
    void send_event_b(void);
    void send_event_c(void);
 private slots:
    void event_a(void);
    void event_b(void);
    void event_c(void);
//     void EventD(void);
};

#endif  // QTTHREADDEMO_THREADFORM_H
