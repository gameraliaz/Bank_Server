#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
class timer: public QObject
{
     Q_OBJECT
public:
    timer();
    QTimer *ttimer;
    int timerres;
    int time_min();
    ~timer();
public slots:
    void MyTimerSlot();

};

#endif // TIMER_H




