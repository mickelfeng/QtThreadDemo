QtThreadDemo by Edward
============

About Use Qt Thread Test Demo

最近工作需要，接触了一下Qt，最大的感觉是Qt编译起来很慢，有点受不了。  
Qt的用起来，语法有点像Java，写界面程序真的很方便，控件添加，布局，信号槽等，都很容易实现。
这里写了一个QThread的使用Demo，Qt的多线程，涉及到线程的创建，线程间信号槽关系的建立等问题（锁，同步的这里没有考虑）。  
关于很怎么使用QThread，这篇文章有详细的说明，官方的Wiki：http://qt-project.org/wiki/Threads_Events_QObjects。大概意思是2种方法：plan1.从QThread派生一个类QMyThread，重载run方法。plan2.定义一个可重入的QDummy（从QObject派生一个QDummy类）和QThread，把QObject的。对象moveToThread到QThread的对象里。  
这2种方法，方法1好像是并不太推崇的。而且2种方法的区别在于：
plan1：类QMyThread中，只有在run方法作用域是属于子线程，类QMyThread中的其他成员变量，成员函数，信号，槽，都属于主线程。类QMyThread只是用来管理线程的，通过接收信号，在槽函数里修改flag，这个flag用于控制run函数里的循环。

class QMyThread: public QThread {
...
 public: 
    void run(void) {}; // 子线程
 slots:
    void slot1(void); // 属于主线程
 signals:
    void signal1(void); // 属于主线程
...
}

...
QMyThread thread1 = new QMyThread();
connect(this, ..., thread1, SLOT(slots1()));
thread1.start();
...

plan2：区别于plan1中的类QMyThread，QDummy类里的数据，信号，槽函数等都属于子线程。

class QDummy: public QObject {
...
 slots:
    void slot1(void);
 signals:
    void signal1(void);
...
}

...
QDummy *_dummy = new QDummy();
QThread *_thread = new QThread();
_dummy.moveToThread(_thread);
connect(this, ..., _dummy, SLOT(slot1()));
_thread.start();
..

记录