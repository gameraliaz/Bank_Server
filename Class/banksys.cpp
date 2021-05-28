#include "banksys.h"
#include <QDebug>
int* banksys::Turn=new int[0];
banksys::banksys()
{
    for(int i=0;i<4;i++)
        max_min_sum_avg[i]=0;
    Services=new QString[0];
    Sercount=0;
    Employees=new employee[0];
    Empcount=0;
    Customers=new customer[0];
    Cuscount=0;
    Procces=new procces[0];
    Procount=0;
    ProcountSer=new int[0];
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
    //Add ProcountSer size
    int tempps[Sercount-1];
    for(int i=0;i<Sercount-1;i++)
    {
        tempps[i]=ProcountSer[i];
    }
    delete [] ProcountSer;
    ProcountSer=new int[Sercount];
    for(int i=0;i<Sercount-1;i++)
    {
        ProcountSer[i]=tempps[i];
    }
    //Initialization new index of ProcountSer
    ProcountSer[Sercount-1]=0;
    //Add customersCanceledCount size
    int tempccc[Sercount-1];
    for(int i=0;i<Sercount-1;i++)
    {
        tempccc[i]=customersCanceledCount[i];
    }
    delete [] customersCanceledCount;
    customersCanceledCount=new int[Sercount];
    for(int i=0;i<Sercount-1;i++)
    {
        customersCanceledCount[i]=tempccc[i];
    }
    //Initialization new index of ProcountSer
    customersCanceledCount[Sercount-1]=0;
    //Add max_min_sum_avg_ser size
    int tempmmsa[Sercount-1][4];
    for(int i=0;i<Sercount-1;i++)
    {
        for(int j=0;j<4;j++)
        {
            tempmmsa[i][j]=max_min_sum_avg_ser[i][j];
        }
    }
    for(int i=0;i<Sercount-1;i++)
    {
        delete [] max_min_sum_avg_ser[i];
    }
    delete [] max_min_sum_avg_ser;
    max_min_sum_avg_ser=new int*[Sercount];
    for(int i=0;i<Sercount;i++)
    {
        max_min_sum_avg_ser[i]=new int[4];
    }
    for(int i=0;i<Sercount-1;i++)
    {
        for(int j=0;j<4;j++)
        {
            max_min_sum_avg_ser[i][j]=tempmmsa[i][j];
        }
    }
    //Initialization new index of ProcountSer
    customersCanceledCount[Sercount-1]=0;
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

    result+="Customers served : \n";
    int countCusServed=0;
    for(int i=0;i<Sercount;i++)
    {
        countCusServed+=ProcountSer[i]-customersCanceledCount[i];
        result+=Services[i]+" : \t"+(QVariant(ProcountSer[i]-customersCanceledCount[i])).toString()+'\n';
    }

    result+="All customers served count : \t"+(QVariant(countCusServed)).toString()+'\n';

    result+="Max response time : "+(QVariant(max_min_sum_avg[0]).toString())+'\n';

    result+="Min response time : "+(QVariant(max_min_sum_avg[1]).toString())+'\n';

    result+="Sum responses time : "+(QVariant(max_min_sum_avg[2]).toString())+'\n';

    result+="Avrage response time : "+(QVariant(max_min_sum_avg[3]).toString())+'\n';

    for(int i=0;i<Sercount;i++)
    {
        result+=Services[i]+'\n';

        result+="Max response time : "+(QVariant(max_min_sum_avg_ser[i][0]).toString())+'\n';

        result+="Min response time : "+(QVariant(max_min_sum_avg_ser[i][1]).toString())+'\n';

        result+="Sum responses time : "+(QVariant(max_min_sum_avg_ser[i][2]).toString())+'\n';

        result+="Avrage response time : "+(QVariant(max_min_sum_avg_ser[i][3]).toString())+'\n';
    }

    return result;
}
bool banksys::Empgetjob(employee Employee,int Service)
{
    customer Customer;
    if(!Customer.SignIn(Turn[Service],Service,Customers))
        return false;
    //seting max  , min , sum and avrage procces time
    max_min_sum_avg[2]+=Customer.waittime;
    max_min_sum_avg_ser[Service][2]+=Customer.waittime;
    max_min_sum_avg[3]=max_min_sum_avg[2]/Procount;
    max_min_sum_avg_ser[Service][3]=max_min_sum_avg_ser[Service][2]/ProcountSer[Service];
    if(Customer.waittime>max_min_sum_avg[0])
        max_min_sum_avg[0]=Customer.waittime;
    else if(Customer.waittime<max_min_sum_avg[0])
        max_min_sum_avg[1]=Customer.waittime;
    else
    {
        max_min_sum_avg[1]=Customer.waittime;
        max_min_sum_avg[0]=Customer.waittime;
    }
    if(Customer.waittime>max_min_sum_avg_ser[Service][0])
        max_min_sum_avg_ser[Service][0]=Customer.waittime;
    else if(Customer.waittime<max_min_sum_avg_ser[Service][0])
        max_min_sum_avg_ser[Service][1]=Customer.waittime;
    else
    {
        max_min_sum_avg_ser[Service][1]=Customer.waittime;
        max_min_sum_avg_ser[Service][0]=Customer.waittime;
    }
    Customer.end();
    //add Procces size
    procces temp[Procount];
    for(int i=0;i<Procount;i++)
    {
        temp[i]=Procces[i];
    }
    delete [] Procces;
    Procount++;
    ProcountSer[Service]++;
    Procces=new procces[Procount];
    for(int i=0;i<Procount-1;i++)
    {
        Procces[i]=temp[i];
    }
    //Initialization new index of Procces
    Procces[Procount-1].setCusEmp(Customer,Employee);
    Turn[Service]++;
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
QString banksys::Turn_Queue (int queueNum)
{
    return QVariant(Turn[queueNum]).toString()+"/"+QVariant(customer::Queue[queueNum]).toString();
}
void banksys::customerServiceCancel(int service)
{
    customersCanceledCount[service]++;
}
