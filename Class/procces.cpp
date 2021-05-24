#include "procces.h"
#include "Class/timer.h"

int procces::idProcces=1000000;
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
}
QString procces::Status()
{
    QString result="";
    result="Procces time : "+timer::Status();
}
