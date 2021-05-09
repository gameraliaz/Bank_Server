#include "customers.h"

Customers::Customers(int service)
{
    timerOb=new timer;
    Customers::service=service;
    count[service]++;
    place=count[service];
}
Customers::~Customers()
{
    turn++;
}
QString Customers::timeStatus()
{
    return "Wait Time : "+(QString)((timerOb->timerres>60)?timerOb->time_min():timerOb->timerres);
}
