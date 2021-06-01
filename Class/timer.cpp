#include "timer.h"
timer::timer()
{
    timerob=time(NULL);
}
void timer::end()
{
    timerob=time(NULL)-timerob;
}
int timer::time_min()
{
    return timerob/60;
}
long timer::time_sec()
{
    return timerob;
}
QString timer::Status()
{
    return QString::number(time_sec());
}
