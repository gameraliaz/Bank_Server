#include "banksys.h"

banksys::banksys()
{
    Turn=new int[0];
    Services=new QString[0];
    Sercount=0;
    Employees=new employee[0];
    Empcount=0;
    Customers=new customer[0];
    Cuscount=0;
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
    Turn[Sercount-1]=0;
}
QString banksys::Status()
{
    QString result="";
    result+="Employees count : "+((QString)Empcount) +'\t'+"Ids: "+((QString)employee::Ids)+'\n';
    for(int i=0;i<Empcount;i++)
    {
        result+=Employees[i].Status();
    }
    result+="Customers count : "+((QString)Cuscount)+'\n';
    for(int i=0;i<Cuscount;i++)
    {
        result+=Customers[i].Status();
    }
    result+="Services count : "+((QString)Sercount)+'\n';
    for(int i=0;i<Sercount;i++)
    {
        result+=((QString)i)+" : "+Services[i]+'\t';
        result+="Queue : "+((QString)customer::Queue[i])+'\n';
    }
    return result;
}
