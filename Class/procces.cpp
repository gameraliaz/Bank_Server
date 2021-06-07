#include "procces.h"
#include "Class/timer.h"
#include <QDebug>

void procces::setCusEmp(customer Customer ,employee Employee)
{
    procces::Customer=Customer;
    procces::Employee=Employee;
    active=true;
    canceled=false;
}
void procces::endProcces()
{
    active=false;
    end();
    proccesTime=time_sec();
}
QString procces::Status()
{
    QString result="";
    result="Procces time : "+((active)?"is on procces":QString::number(proccesTime));
    return  result;
}
bool procces::checkCustomer(customer cus)
{
    return cus.trueInfo(Customer.returnPlace(),Customer.returnService());
}
bool procces::done()
{
    return !active&&!canceled;
}
int procces::returnempID()
{
    int id;
    Employee.returnInfo(id);
    return id;
}
