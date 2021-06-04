#include "customerwin.h"
#include "ui_customerwin.h"
#include <Class/customer.h>
#include <QDebug>
CustomerWin::CustomerWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerWin)
{
    ui->setupUi(this);
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
    bank->addCustommer(service);
    Customer=bank->loginCustomer(customer::Queue[service],service);
    WinReceipt->setBank(*bank);
    WinReceipt->setCustomer(Customer);
    WinReceipt->show();
}
void CustomerWin::setBank(banksys &bankSys)
{
    bank=&bankSys;
    for (int i=0;i<bank->Sercount;i++)
        ui->cmbService->addItem(bank->Services[i]);
}
