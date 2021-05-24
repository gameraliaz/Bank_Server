#include "banksys.h"
#include <QDebug>
int* banksys::Turn=new int[0];
banksys::banksys()
{
    Services=new QString[0];
    Sercount=0;
    Employees=new employee[0];
    Empcount=0;
    Customers=new customer[0];
    Cuscount=0;
    Procces=new procces[0];
    Procount=0;
}
void banksys::addEmployee(QString Password,QString Firstname,QString Lastname,QString Birthdate,QString Identitycode)
{
    employee temp[Empcount];
    for(int i=0;i<Empcount;i++)
    {
        temp[i]=Employees[i];
    }
    delete [] Employees;
    Empcount++;
    Employees = new employee[Empcount];
    for(int i=0;i<Empcount-1;i++)
    {
        Employees[i]=temp[i];
    }
    Employees[Empcount-1].SignUp(Password,Firstname, Lastname, Birthdate, Identitycode);
}
void banksys::addCustommer(int Service)
{
    customer temp[Cuscount];
    for(int i=0;i<Cuscount;i++)
    {
        temp[i]=Customers[i];
    }
    delete [] Customers;
    Cuscount++;
    Customers = new customer[Cuscount];
    for(int i=0;i<Cuscount-1;i++)
    {
        Customers[i]=temp[i];
    }
    customer::Queue[Service]++;
    customer::allQueue++;
    Customers[Cuscount-1].setCustomer(Service,customer::Queue[Service]);
}
employee banksys::loginEmployee(int Id,QString Password)
{
    employee Emp;
    Emp.SignIn(Id,Password,Employees);
    return Emp;
}
customer banksys::loginCustomer(int Place,int Service)
{
    customer Cus;
    Cus.SignIn(Place,Service,Customers);
    return Cus;
}
void banksys::addService(QString Service)
{
    //add Service size
    QString temp[Sercount];
    for(int i=0;i<Sercount;i++)
    {
        temp[i]=Services[i];
    }
    delete [] Services;
    Sercount++;
    Services = new QString[Sercount];
    for(int i=0;i<Sercount-1;i++)
    {
        Services[i]=temp[i];
    }
    //add new Service
    Services[Sercount-1]=Service;
    //add Queue size
    int tempq[Sercount-1];
    for(int i=0;i<Sercount-1;i++)
    {
        tempq[i]=customer::Queue[i];
    }
    delete [] customer::Queue;
    customer::Queue=new int[Sercount];
    for(int i=0;i<Sercount-1;i++)
    {
        customer::Queue[i]=tempq[i];
    }
    //Initialization new index of Queue
    customer::Queue[Sercount-1]=0;
    //add Turn size
    int tempt[Sercount-1];
    for(int i=0;i<Sercount-1;i++)
    {
        tempt[i]=Turn[i];
    }
    delete [] Turn;
    Turn=new int[Sercount];
    for(int i=0;i<Sercount-1;i++)
    {
        Turn[i]=tempt[i];
    }
    //Initialization new index of Turn
    Turn[Sercount-1]=1;
}
QString banksys::Status()
{
    QString result="";
    result+="Employees count : "+(QVariant(Empcount).toString()) +'\t'+"Ids: "+(QVariant(employee::Ids).toString())+'\n';
    for(int i=0;i<Empcount;i++)
    {
        result+=Employees[i].Status();
    }
    result+="Customers count : "+(QVariant(Cuscount).toString())+'\n';
    for(int i=0;i<Cuscount;i++)
    {
        result+=Customers[i].Status();
    }
    result+="Services count : "+(QVariant(Sercount).toString())+'\n';
    for(int i=0;i<Sercount;i++)
    {
        result+=(QVariant(i).toString())+" : "+Services[i]+'\t';
        result+="Queue : "+(QVariant(customer::Queue[i]).toString())+'\n';
    }
    result+="Procces count : "+(QVariant(Procount).toString())+'\n';
    for(int i=0;i<Procount;i++)
    {
        result+=Procces[i].Status();
    }

    return result;
}
bool banksys::Empgetjob(employee Employee,int Service)
{
    customer Customer;
    qDebug() << Turn[Service];
    if(!Customer.SignIn(Turn[Service],Service,Customers))
        return false;
    //add Procces size
    qDebug() << "a";
    procces temp[Procount];
    for(int i=0;i<Procount;i++)
    {
        temp[i]=Procces[i];
    }
    qDebug() << "b";
    delete [] Procces;
    Procount++;
    qDebug() << "c";
    Procces=new procces[Procount];
    for(int i=0;i<Procount-1;i++)
    {
        Procces[i]=temp[i];
    }
    qDebug() << "d";
    //Initialization new index of Procces
    Procces[Procount-1].setCusEmp(Customer,Employee);
    qDebug() << "e";
    Turn[Service]++;
    qDebug() << "f";
    procces::idProcces++;
    qDebug() << "j";
    return true;
}
bool banksys::Empendjob(employee Emp)
{
    for(int i=0;i<Procount;i++)
    {
        if(Procces[i].checkEmployee(Emp))
        {
            Procces[i].endProcces();
            return true;
        }
    }
    return false;
}
