#include "receipt.h"
#include "ui_receipt.h"
#include <server.h>
#include <QVariant>
#include <QtDebug>
#include <QMessageBox>
Receipt::Receipt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Receipt)
{
    ui->setupUi(this);
}

Receipt::~Receipt()
{
    delete ui;
}
void Receipt::setCustomer(customer Customer)
{
    Receipt::Customer=Customer;
    on_btnRefresh_clicked();
}
void Receipt::on_btnRefresh_clicked()
{
    int place=Customer.returnPlace();
    int service=Customer.returnService();
    Customer.empid=Server::Bank.empIDProcces(service,place);
    ui->lblTurnQueue->setText(Server::Bank.Turn_Queue(Customer.returnService()));
    ui->lblPlace->setText((QVariant(Customer.returnPlace()).toString()));
    if(Customer.empid==-1)
    {
        QMessageBox msgBox;
        msgBox.setText("You are so late :( ");
        msgBox.exec();
    }else if(Customer.empid!=0)
    {
        QMessageBox msgBox;
        msgBox.setText("Your turn!! your employee id is : "+(QVariant(Customer.empid).toString()));
        msgBox.exec();
    }
}
