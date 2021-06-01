#include "employeewin.h"
#include "ui_employeewin.h"
#include <server.h>
#include <QTime>
#include <ctime>
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
    ui->lblLoginTime->setText(QTime::fromMSecsSinceStartOfDay(10 * 1000).toString("hh:mm:ss"));
}

void employeeWin::on_cmbService_currentIndexChanged(int index)
{
    ui->lblQueue->setText(Server::Bank.Turn_Queue(index));
}



void employeeWin::on_btnGetjob_clicked()
{
    int id;
    Employee.returnInfo(id);
    service=ui->cmbService->currentIndex();
    if(!active)
    {
        timecare=time_t(NULL);
        Server::Bank.Empgetjob(Server::Bank.returnEmp(id),service);
        active=true;
    }else
    {
        Server::Bank.returnEmp(id).worktime-=timecare;
        timecare=time_t(NULL);
        Server::Bank.Empgetjob(Server::Bank.returnEmp(id),service);
    }
    ui->lblQueue->setText(Server::Bank.Turn_Queue(service));
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
