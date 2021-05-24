#ifndef BANKSYS_H
#define BANKSYS_H
#include <QString>
#include <QVariant>
#include "Class/person.h"
#include "Class/timer.h"
#include "Class/customer.h"
#include "Class/employee.h"
#include "Class/procces.h"

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
        static int *Turn;
    public:
        banksys();
        void addEmployee(QString Password,QString Firstname,QString Lastname,QString Birthdate,QString Identitycode);
        void addCustommer(int Service);
        employee loginEmployee(int Id,QString Password);
        customer loginCustomer(int Place,int Service);
        void addService(QString Service);
        QString Status();
        bool Empgetjob(employee Employee,int Service);
        bool Empendjob(employee Employee);
};

#endif // BANKSYS_H
