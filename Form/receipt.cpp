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
    ui->lblTurnQueue->setText(Server::Bank.Services[service]+" "+Server::Bank.Turn_Queue(service));
    ui->lblPlace->setText((QVariant(place).toString()));
    if(Server::Bank.returnCus(place,service).active==false)
    {
        QMessageBox msgBox;
        msgBox.setText("You are so late :( ");
        msgBox.exec();
    }else if(Server::Bank.returnCus(place,service).empid!=0)
    {
        QMessageBox msgBox;
        msgBox.setText("Your turn!! your employee id is : "+(QVariant(Server::Bank.returnCus(place,service).empid).toString()));
        msgBox.exec();
    }
}
