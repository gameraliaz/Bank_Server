#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QString>
#include <QVariant>
#include "Class/timer.h"
#include "Class/person.h"



class customer:public person,timer
{
    private:
        int service;
        int place;
    public:
        static int allQueue;
        static int *Queue;
        customer();
        void setCustomer(int service,int place);
        void returnInfo(int &Service,int &Place,QString &Firstname,QString &Lastname,QString &Birthdate,QString &Identitycode);
        int returnPlace();
        int returnService();
        bool trueInfo(int Place,int Service);
        bool SignIn(int Place,int Service,customer *Customers);
        customer& operator = (customer ob);
        void verifiedIdentity(QString Firstname,QString Lastname,QString Birthdate,QString Identitycode);
        QString Status();
        void end();
        int waittime;
        int empid;
};

#endif // CUSTOMERS_H
