#include "customerwin.h"
#include <server.h>
#include "ui_customerwin.h"
#include <Class/customer.h>
#include <QDebug>
CustomerWin::CustomerWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerWin)
{
    ui->setupUi(this);
    for (int i=0;i<Server::Bank.Sercount;i++)
        ui->cmbService->addItem(Server::Bank.Services[i]);
}

CustomerWin::~CustomerWin()
{
    delete ui;
}

void CustomerWin::on_btnGet_clicked()
{
    WinReceipt =new Receipt;
    int service=ui->cmbService->currentIndex();
    customer Customer;
    Server::Bank.addCustommer(service);
    Customer=Server::Bank.loginCustomer(customer::Queue[service],service);
    WinReceipt->setCustomer(Customer);
    WinReceipt->show();
}
