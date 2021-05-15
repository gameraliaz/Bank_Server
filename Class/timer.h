#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <QString>
#include <ctime>
class timer
{
    private:
        time_t timerob;
    public:
        timer();
        void end();
        int time_min();
        int time_sec();
        QString Status();
};

#endif // TIMER_H




