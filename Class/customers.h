#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QtCore>
#include "Class/timer.h"
class Customers
{
public:
    Customers(int service);
    ~Customers();
    int service;
    static int count[4];
    static int turn;
    int place;
    QString timeStatus();
private:
    timer *timerOb;
};

#endif // CUSTOMERS_H
