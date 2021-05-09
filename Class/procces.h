#ifndef PROCCES_H
#define PROCCES_H
#include <QtCore>
#include "Class/customers.h"
#include "Class/employees.h"
#include "Class/timer.h"

class Procces : public Customers , public Employees
{
public:
    Procces(int employeeId,int service);
    QString timeStatus();
private:
     timer *timerOb;
};

#endif // PROCCES_H
