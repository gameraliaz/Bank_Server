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
    public:
        static int idProcces;
        void setCusEmp(customer Customer ,employee Employee);
        void endProcces();
        QString Status();
        bool checkEmployee(employee emp);
};

#endif // PROCCES_H
