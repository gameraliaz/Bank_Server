#ifndef PROCCES_H
#define PROCCES_H
#include <QString>
#include "Class/timer.h"
#include "Class/customer.h"
class procces:public timer
{
    private:
        person Employee;
        customer Customer;
    public:
        void setCusEmp(customer Customer ,person Employee);
        QString Status();
};

#endif // PROCCES_H
