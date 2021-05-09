#include "timer.h"

timer::timer()
{
    timerres=0;
    // create a timer
    ttimer = new QTimer(this);

    // setup signal and slot
    connect(ttimer, SIGNAL(timeout()),
          this, SLOT(MyTimerSlot()));

    // msec
    ttimer->start(1000);
}

timer::~timer()
{
    killTimer(ttimer->timerId());
}
void timer::MyTimerSlot()
{
    timerres++;
}
int timer::time_min()//time to min (int)
{
    return timerres/60;
}
