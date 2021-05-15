#include "customer.h"

int* customer::Queue=new int[0];
int customer::allQueue=0;
void customer::setCustomer(int service,int place)
{
    customer::service=service;
    customer::place=place;
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
bool customer::trueInfo(int Place,int Service)
{
    if(Place==place&&Service==service)
        return true;
    return false;
}
void customer::SignIn(int Place,int Service,customer *Customers)
{
    for(int i=0;i<allQueue;i++)
    {
        if(Customers[i].trueInfo(Place,Service))
        {
            Customers[i].returnInfo(service,place,firstName,lastName,birthDate,identityCode);
        }
    }
}
customer& customer::operator = (customer ob)
{
    service=ob.service;
    place=ob.place;
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
    result="Service : "+((QString)service)+"\tPlace : "+((QString)place)+'\n';
    return result;

}

