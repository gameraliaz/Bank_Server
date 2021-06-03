#include "customer.h"

int* customer::Queue=new int[0];
int customer::allQueue=0;
customer::customer()
{
    empid=0;
    waittime=0;
    active=true;
}
void customer::setCustomer(int service,int place)
{
    customer::service=service;
    customer::place=place;
    empid=0;
    waittime=0;
}
void customer::returnInfo(int &Service,int &Place,QString &Firstname,QString &Lastname,QString &Birthdate,QString &Identitycode)
{
    Service=service;
    Place=place;
    Firstname=firstName;
    Lastname=lastName;
    Birthdate=birthDate;
    Identitycode=identityCode;
}
int customer::returnPlace()
{
    return place;
}
int customer::returnService()
{
    return service;
}
bool customer::trueInfo(int Place,int Service)
{
    if(Place==place&&Service==service)
        return true;
    return false;
}
bool customer::SignIn(int Place,int Service,customer *Customers)
{
    for(int i=0;i<allQueue;i++)
    {
        if(Customers[i].trueInfo(Place,Service))
        {
            Customers[i].returnInfo(service,place,firstName,lastName,birthDate,identityCode);
            return  true;
        }
    }
    return  false;
}
customer& customer::operator = (customer ob)
{
    service=ob.service;
    place=ob.place;
    waittime=ob.waittime;
    empid=ob.empid;
    active=ob.active;
    setPerson(ob.firstName,ob.lastName,ob.birthDate,ob.identityCode);
    return *this;
}
void customer::verifiedIdentity(QString Firstname,QString Lastname,QString Birthdate,QString Identitycode)
{
    setPerson( Firstname, Lastname, Birthdate, Identitycode);
}
QString customer::Status()
{
    QString result="";
    result+=person::Status();
    result="Service : "+(QVariant(service).toString())+"\tPlace : "+(QVariant(place).toString())+'\n';
    return result;
}
void customer::end()
{
    timer::end();
    waittime=time_sec();
}

