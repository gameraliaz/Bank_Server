#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <QString>
#include "Class/timer.h"
#include "Class/person.h"
#include "Class/procces.h"
class employee:public person
{
    private:
        int id;
        QString password;
        bool active;
        procces *Pro;

    public:
        static int Ids;
        employee();
        void SignUp(QString Password,QString Firstname,QString Lastname,QString Birthdate,QString Identitycode);
        void SignIn(int Id,QString Password,employee *Employees);
        bool trueInfo(int Id,QString Password);
        void returnInfo(int &Id,QString &Password,QString &Firstname,QString &Lastname,QString &Birthdate,QString &Identitycode);
        employee& operator = (employee ob);
        virtual QString Status();
        void getJob(int Service);
        void endJob();
};

#endif // EMPLOYEES_H
