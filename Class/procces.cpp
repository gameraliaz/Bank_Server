
#include "procces.h"

Procces::Procces(int employeeId,int service):Customers(service),Employees(employeeId)
{
    timerOb=new timer;
}

QString Procces::timeStatus()
{
    return "Procces Time : "+(QString)((timerOb->timerres>60)?timerOb->time_min():timerOb->timerres);
}
