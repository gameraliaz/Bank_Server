#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <QString>
#include <ctime>
class timer
{
    private:
        time_t timerob;
    protected:

        void end();
        int time_min();
        long time_sec();
    public:
        timer();
        QString Status();
};

#endif // TIMER_H




