#ifndef PROCCES_H
#define PROCCES_H
#include <QString>
#include <QVariant>
#include "Class/timer.h"
#include "Class/customer.h"
#include "Class/employee.h"
class procces:public timer
{
    private:
        employee Employee;
        customer Customer;
        bool active;
    public:
        int returnempID();
        bool canceled;
        bool checkCustomer(customer cus);
        void setCusEmp(customer Customer ,employee Employee);
        void endProcces();
        QString Status();
        bool checkEmployee(employee emp);
        bool done();
        int proccesTime;

};

#endif // PROCCES_H
