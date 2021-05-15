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
int timer::time_sec()
{
    return timerob;
}
QString timer::Status()
{
    return (QString)((timerob<60)?time_sec():time_min());
}
