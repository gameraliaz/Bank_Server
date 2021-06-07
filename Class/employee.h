#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <QString>
#include <QVariant>
#include "Class/person.h"
class employee:public person
{
    private:
        int id;
        QString password;
    public:
        int Workcount;
        int worktime;
        static int Ids;
        employee();
        void SignUp(QString Password,QString Firstname,QString Lastname,QString Birthdate,QString Identitycode);
        void SignIn(int Id,QString Password,employee *Employees);
        bool trueInfo(int Id,QString Password);
        bool trueInfo(int Id);
        void returnInfo(int &Id,QString &Password,QString &Firstname,QString &Lastname,QString &Birthdate,QString &Identitycode);
        QString Name();
        void returnInfo(int &Id);
        employee& operator = (employee ob);
        QString Status();
};

#endif // EMPLOYEES_H
