#include "employee.h"
#include <ctime>
int employee::Ids =1000;
employee::employee()
{
    worktime=0;
    Workcount=0;
    id=-1;
    active=false;
}
void employee::SignUp(QString Password,QString Firstname,QString Lastname,QString Birthdate,QString Identitycode)
{
    if(id==-1)
    {
        setPerson( Firstname, Lastname, Birthdate, Identitycode);
        Ids++;
        id=Ids;
        password=Password;
    }else
    {
        //you already have an account
        return;
    }
}
void employee::SignIn(int Id,QString Password,employee *Employees)
{
    if(Id>1000&&Id<=Ids&&id==-1)
    {
        int n=Ids-1000;
        for(int i=0;i<n;i++)
        {
            if(Employees[i].trueInfo(Id,Password))
            {
                Employees[i].returnInfo(id,password,firstName,lastName,birthDate,identityCode);
            }
        }
    }
}
bool employee::trueInfo(int Id,QString Password)
{
    if(Id==id&&Password==password)
        return true;
    return false;
}
bool employee::trueInfo(int Id)
{
    if(Id==id)
        return true;
    return false;
}
void employee::returnInfo(int &Id,QString &Password,QString &Firstname,QString &Lastname,QString &Birthdate,QString &Identitycode)
{
    Id=id;
    Password=password;
    Firstname=firstName;
    Lastname=lastName;
    Birthdate=birthDate;
    Identitycode=identityCode;
}
void employee::returnInfo(int &Id)
{
    Id=id;
}
QString employee::Name()
{
    return firstName+" "+lastName;
}
employee& employee::operator = (employee ob)
{
    id=ob.id;
    firstName=ob.firstName;
    lastName=ob.lastName;
    birthDate=ob.birthDate;
    identityCode=ob.identityCode;
    password=ob.password;
    return *this;
}
QString employee::Status()
{
    QString result="";
    result="ID : "+QVariant(id).toString()+"\t Work time: "+QVariant(worktime).toString()+"\t Work count: "+QVariant(Workcount).toString()+'\n'+person::Status()+'\n';
    return result;
}
void employee::stop_start_working()
{
    if(active)
    {
        //stop
        worktime+=time(NULL)-timecare;
        active=false;
    }
    else
    {
        //start
        timecare=time(NULL);
        active=true;
    }
}
