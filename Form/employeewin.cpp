#include "employeewin.h"
#include "ui_employeewin.h"
#include <QTime>
#include <QtDebug>
employeeWin::employeeWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::employeeWin)
{
    ui->setupUi(this);
}

employeeWin::~employeeWin()
{
    delete ui;
}

void employeeWin::setEmployee(employee Employee)
{
    int id;
    Employee.returnInfo(id);
    employeeWin::Employee=bank->returnEmp(id);
    ui->lblEmployeeName->setText(Employee.Name());
    ui->lblLoginTime->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void employeeWin::on_cmbService_currentIndexChanged(int index)
{
    ui->lblQueue->setText(bank->Turn_Queue(index));
}

void employeeWin::on_btnGetjob_clicked()
{

    int id;
    Employee.returnInfo(id);
    int Service=ui->cmbService->currentIndex();
    if(bank->Turn_Queue(Service).split('/')[0]==bank->Turn_Queue(Service).split('/')[1])
    {
        if(active)
        {
            active=false;
            bank->customerServiceCancel(service);
        }
    }
    else if(!active)
    {
        bank->Empgetjob(bank->returnEmp(id),Service);
        active=true;
        service=Service;
    }else
    {
        bank->customerServiceCancel(service);
        service=Service;
        bank->Empgetjob(bank->returnEmp(id),Service);
    }
    ui->lblQueue->setText(bank->Turn_Queue(Service));
}

void employeeWin::on_btnEndjob_clicked()
{
    if(active)
    {
        int id;
        Employee.returnInfo(id);
        bank->Empendjob(bank->returnEmp(id));
        active=false;
    }
}
void employeeWin::setBank(banksys &bankSys)
{
    bank=&bankSys;
    active=false;
    for (int i=0;i<bank->Sercount;i++) {
        ui->cmbService->addItem(bank->Services[i]);
    }
}
