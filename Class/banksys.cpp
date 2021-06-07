#include "banksys.h"
#include <QDebug>
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
    Turn =new int[0];
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
bool banksys::LoginEmloyeeCheck(int Id,QString Password)
{
    for(int i=0;i<Empcount;i++)
        if(Employees[i].trueInfo(Id,Password))
            return true;
    return false;

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
    if(Sercount!=0)
    {
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

        //Initialization new index of max_min_sum_avg_ser
        for(int j=0;j<4;j++)
        {
            max_min_sum_avg_ser[Sercount-1][j]=0;
        }
    }else
    {
        Sercount++;
        Services = new QString[Sercount];
        Services[Sercount-1]=Service;
        customer::Queue=new int[Sercount];
        customer::Queue[Sercount-1]=0;
        Turn=new int[Sercount];
        Turn[Sercount-1]=1;
        ProcountSer=new int[Sercount];
        ProcountSer[Sercount-1]=0;
        customersCanceledCount=new int[Sercount];
        customersCanceledCount[Sercount-1]=0;
        max_min_sum_avg_ser=new int*[Sercount];
        for(int i=0;i<Sercount;i++)
        {
            max_min_sum_avg_ser[i]=new int[4];
        }
        for(int j=0;j<4;j++)
        {
            max_min_sum_avg_ser[Sercount-1][j]=0;
        }
    }
}
QString banksys::Status()
{
    QString result="";

    result+="Employees count : "+(QVariant(Empcount).toString()) +'\n';
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
    timer ***t;
    t=new timer ** [Procount];
    result+="Procces count : "+(QVariant(Procount).toString())+'\n';
    for(int i=0;i<Procount;i++)
    {
        result+="Procces "+QString::number(i+1)+'\n';
        t[i]=new timer *[2];
        for(int j=0;j<Cuscount;j++)
        {
            if(Procces[i].checkCustomer(Customers[j]))
            {
                t[i][0]=&Customers[j];
                t[i][1]=&Procces[i];
                result+="Customer place in queue : "+QString::number(Customers[i].returnPlace())+"\t";
                result+="Customer service : "+Services[Customers[i].returnService()]+"\t";
                result+="Employee id : "+QString::number(Customers[i].empid)+"\n";
                result+="Wait time :\t"+t[i][0]->Status()+"\n";
                result+="Procces time :\t"+t[i][1]->Status()+"\n";
                if(Procces[i].canceled)
                    result+="Procces was canceled!\n\n";
                break;
            }
        }
    }

    int countCusServed=0;
    for(int i=0;i<Sercount;i++)
    {
        result+=Services[i]+" :"+'\n';
        result+="Queue : "+(QVariant(customer::Queue[i]).toString())+'\n';
        countCusServed+=ProcountSer[i]-customersCanceledCount[i];
        result+="Customers served : "+(QVariant(ProcountSer[i]-customersCanceledCount[i])).toString()+'\n';

        result+="Max response time : "+(QVariant(max_min_sum_avg_ser[i][0]).toString())+'\n';

        result+="Min response time : "+(QVariant(max_min_sum_avg_ser[i][1]).toString())+'\n';

        result+="Sum responses time : "+(QVariant(max_min_sum_avg_ser[i][2]).toString())+'\n';

        result+="Avrage response time : "+(QVariant(max_min_sum_avg_ser[i][3]).toString())+'\n';
    }
    result+="All customers served count : \t"+(QVariant(countCusServed)).toString()+'\n';

    result+="Max response time : "+(QVariant(max_min_sum_avg[0]).toString())+'\n';

    result+="Min response time : "+(QVariant(max_min_sum_avg[1]).toString())+'\n';

    result+="Sum responses time : "+(QVariant(max_min_sum_avg[2]).toString())+'\n';

    result+="Avrage response time : "+(QVariant(max_min_sum_avg[3]).toString())+'\n';
    return result;
}
bool banksys::Empgetjob(employee Employee,int Service)
{
    for(int i=0;i<Cuscount;i++)
    {
        if(Customers[i].trueInfo(Turn[Service],Service))
        {
            int empID;
            Employee.returnInfo(empID);
            Customers[i].empid=empID;
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
            Procces[Procount-1].setCusEmp(Customers[i],Employee);
            Turn[Service]++;
            //seting max  , min , sum and avrage procces time
            Customers[i].end();
            setMinMaxAvg();
            setEmployeeWorktime(empID);
            return true;
        }
    }
    return false;
}
bool banksys::Empendjob(employee Emp)
{
    int empID;
    Emp.returnInfo(empID);
    returnEmp(empID).Workcount++;
    qDebug()<<empID;
    for(int i=0;i<Procount;i++)
    {
        qDebug()<<"procc : "<<Procces[i].returnempID();
        if(Procces[i].returnempID()==empID)
        {
            for(int j=0;j<Cuscount;j++)
            {
                qDebug()<<"customer : "<<Procces[i].checkCustomer(Customers[j]);
                qDebug()<<"active : "<<Customers[j].active;
                if(Procces[i].checkCustomer(Customers[j]))
                {
                    if(Customers[j].active)
                    {
                        Procces[i].endProcces();
                        Customers[j].active=false;
                        setMinMaxAvg();
                        setEmployeeWorktime(empID);
                        return true;
                    }
                }
            }

        }

    }
    return false;
}
QString banksys::Turn_Queue (int queueNum)
{
    return (QVariant(Turn[queueNum]-1).toString())+"/"+(QVariant(customer::Queue[queueNum]).toString());
}
void banksys::customerServiceCancel(int place,int service)
{
    qDebug()<<"place : "<<place;
    returnCus(place,service).active=false;
    customersCanceledCount[service]++;
    for(int i=0;i<Procount;i++)
    {
        if(Procces[i].checkCustomer(returnCus(place,service)))
        {
            Procces[i].canceled=true;
            Procces[i].endProcces();
            setEmployeeWorktime(Procces[i].returnempID());
            break;
        }
    }
    setMinMaxAvg();

}
employee & banksys::returnEmp(int id)
{
    for(int i=0;i<Empcount;i++)
    {
        if(Employees[i].trueInfo(id))
            return Employees[i];
    }
}
customer & banksys::returnCus(int place,int service)
{
    for(int i=0;i<Cuscount;i++)
    {
        if(Customers[i].trueInfo(place,service))
            return Customers[i];
    }
}
void banksys::setMinMaxAvg()
{
    int count=0;
    for(int l=0;l<Sercount;l++)
    {
        int countSer=0;
        for(int i=0;i<Cuscount;i++)
        {
            if(Customers[i].returnService()==l)
            {
                if(!Customers[i].active)
                {
                    for(int j=0;j<Procount;j++)
                    {
                        if(Procces[j].checkCustomer(Customers[i]))
                        {
                            if(!Procces[j].canceled)
                            {
                                int wait=Customers[i].waittime;
                                count++;
                                countSer++;
                                if(count==1)
                                {
                                    for(int k=0;k<4;k++)
                                    {
                                        max_min_sum_avg[k]=wait;
                                    }
                                }
                                else
                                {
                                    max_min_sum_avg[2]+=wait;
                                    max_min_sum_avg[3]=max_min_sum_avg[2]/count;
                                    if(wait>max_min_sum_avg[0])
                                        max_min_sum_avg[0]=wait;
                                    else
                                        max_min_sum_avg[1]=wait;
                                }
                                if(countSer==1)
                                {
                                    for(int k=0;k<4;k++)
                                    {
                                        max_min_sum_avg_ser[l][k]=wait;
                                    }
                                }else
                                {
                                    max_min_sum_avg_ser[l][2]+=wait;
                                    max_min_sum_avg_ser[l][3]=max_min_sum_avg[2]/count;
                                    if(wait>max_min_sum_avg_ser[l][0])
                                        max_min_sum_avg_ser[l][0]=wait;
                                    else
                                        max_min_sum_avg_ser[l][1]=wait;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
void banksys::setEmployeeWorktime(int empID)
{
    int sum=0;
    for(int i=0;i<Procount;i++)
    {
        if(Procces[i].done())
        {
            if(Procces[i].returnempID()==empID)
                sum+=Procces[i].proccesTime;
        }
    }
    returnEmp(empID).worktime=sum;
}
int banksys::turnPlace(int service)
{
    return Turn[service];
}
