#include "employeewin.h"
#include "ui_employeewin.h"
#include <server.h>
#include <QTime>
#include <ctime>
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
    employeeWin::Employee=Employee;
    ui->lblEmployeeName->setText(Employee.Name());
    ui->lblLoginTime->setText(QTime::fromMSecsSinceStartOfDay(10 * 1000).toString("hh:mm:ss"));
}

void employeeWin::on_cmbService_currentIndexChanged(int index)
{
    ui->lblQueue->setText(Server::Bank.Turn_Queue(index));
}



void employeeWin::on_btnGetjob_clicked()
{
    service=ui->cmbService->currentIndex();
    if(!active)//
    {
        Employee.stop_start_working();
        timecare=time(NULL);
        Server::Bank.Empgetjob(Employee,service);
        active=true;
    }else
    {
        Employee.worktime-=(time(NULL)-timecare);
        Server::Bank.customerServiceCancel(service);
        Server::Bank.Empgetjob(Employee,service);
    }
}


void employeeWin::on_btnEndjob_clicked()
{
    if(active)
    {
        Employee.Workcount++;
        Employee.stop_start_working();
        Server::Bank.Empendjob(Employee);
    }
}
