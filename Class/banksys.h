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
        int *ProcountSer;
        int *Turn;
        int *customersCanceledCount;
        int max_min_sum_avg[4];
        int **max_min_sum_avg_ser;
    public:
        banksys();
        bool LoginEmloyeeCheck(int id,QString Password);
        void addEmployee(QString Password,QString Firstname,QString Lastname,QString Birthdate,QString Identitycode);
        void addCustommer(int Service);
        employee loginEmployee(int Id,QString Password);
        customer loginCustomer(int Place,int Service);
        void addService(QString Service);
        QString Status();
        bool Empgetjob(employee Employee,int Service);
        bool Empendjob(employee Employee);
        QString Turn_Queue (int queueNum);
        QString *Services;
        int Sercount;
        void customerServiceCancel(int service);
        employee & returnEmp(int id);
        customer & returnCus(int place,int service);
        void setMinMaxAvg();
        void setEmployeeWorktime(int empID);

};

#endif // BANKSYS_H
