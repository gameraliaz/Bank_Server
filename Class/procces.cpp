#include "procces.h"
#include "Class/timer.h"

void procces::setCusEmp(customer Customer ,employee Employee)
{
    procces::Customer=Customer;
    procces::Employee=Employee;
}
bool procces::checkEmployee(employee emp)
{
    int id;
    emp.returnInfo(id);
    return emp.trueInfo(id);
}
void procces::endProcces()
{
    end();
    proccesTime=time_sec();
}
QString procces::Status()
{
    QString result="";
    result="Procces time : "+timer::Status();
    return  result;
}
bool procces::checkCustomer(customer cus)
{
    return cus.trueInfo(Customer.returnPlace(),Customer.returnService());
}
