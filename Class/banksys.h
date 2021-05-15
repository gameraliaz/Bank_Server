#ifndef BANKSYS_H
#define BANKSYS_H
#include <QString>
#include "Class/person.h"
#include "Class/timer.h"
#include "Class/customer.h"
#include "Class/employee.h"

class banksys
{
    private:
        employee *Employees;
        int Empcount;
        customer *Customers;
        int Cuscount;
        procces *Procces;
        int Procount;
        QString *Services;
        int Sercount;
        int *Turn;
    public:
        banksys();
        void addEmployee(QString Password,QString Firstname,QString Lastname,QString Birthdate,QString Identitycode);
        void addCustommer(int Service);
        employee loginEmployee(int Id,QString Password);
        customer loginCustomer(int Place,int Service);
        void addService(QString Service);
        QString Status();

};

#endif // BANKSYS_H
