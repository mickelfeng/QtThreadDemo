
/* Copyright 2013 EDWARD.HUNG */

#include <QtGui/QApplication>

#include "ThreadForm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtThreadDemo w;
    w.show();
    return a.exec();
}
