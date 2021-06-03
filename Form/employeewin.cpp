#include "employeewin.h"
#include "ui_employeewin.h"
#include <server.h>
#include <QTime>
#include <QtDebug>
employeeWin::employeeWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::employeeWin)
{
    ui->setupUi(this);
    active=false;
    for (int i=0;i<Server::Bank.Sercount;i++) {
        ui->cmbService->addItem(Server::Bank.Services[i]);
    }
}

employeeWin::~employeeWin()
{
    delete ui;
}

void employeeWin::setEmployee(employee Employee)
{
    int id;
    Employee.returnInfo(id);
    employeeWin::Employee=Server::Bank.returnEmp(id);
    ui->lblEmployeeName->setText(Employee.Name());
    ui->lblLoginTime->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void employeeWin::on_cmbService_currentIndexChanged(int index)
{
    ui->lblQueue->setText(Server::Bank.Turn_Queue(index));
}

void employeeWin::on_btnGetjob_clicked()
{

    int id;
    Employee.returnInfo(id);
    int Service=ui->cmbService->currentIndex();
    if(Server::Bank.Turn_Queue(Service).split('/')[0]==Server::Bank.Turn_Queue(Service).split('/')[1])
    {
        if(active)
        {
            active=false;
            Server::Bank.customerServiceCancel(service);
        }
    }
    else if(!active)
    {
        Server::Bank.Empgetjob(Server::Bank.returnEmp(id),Service);
        active=true;
        service=Service;
    }else
    {
        Server::Bank.customerServiceCancel(service);
        service=Service;
        Server::Bank.Empgetjob(Server::Bank.returnEmp(id),Service);
    }
    ui->lblQueue->setText(Server::Bank.Turn_Queue(Service));
}

void employeeWin::on_btnEndjob_clicked()
{
    if(active)
    {
        int id;
        Employee.returnInfo(id);
        Server::Bank.Empendjob(Server::Bank.returnEmp(id));
        active=false;
    }
}
