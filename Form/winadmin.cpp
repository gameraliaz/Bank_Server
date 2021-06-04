#include "winadmin.h"
#include "ui_winadmin.h"
#include <Class/employee.h>
#include <QMessageBox>
#include <QDebug>
winAdmin::winAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winAdmin)
{
    ui->setupUi(this);
}

winAdmin::~winAdmin()
{
    delete ui;
}

void winAdmin::on_btnCreateEmployee_clicked()
{
    if(ui->txtIdentity->text()!=""&&ui->txtFirstName->text()!=""&&ui->txtLastName->text()!=""&&ui->txtPassword->text()!=""&&ui->txtRepPassword->text()!="")
    {
        if(ui->txtRepPassword->text()==ui->txtPassword->text())
        {
            bank->addEmployee(ui->txtPassword->text(),ui->txtFirstName->text(),ui->txtLastName->text(),ui->dpBirthDate->text(),ui->txtIdentity->text());
            ui->txtInfo->setText(bank->Status());
            ui->txtID->setText((QVariant(employee::Ids+1).toString()));
            ui->txtFirstName->setText("");
            ui->txtLastName->setText("");
            ui->txtIdentity->setText("");
            ui->txtPassword->setText("");
            ui->txtRepPassword->setText("");
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Error: Password and password replication are not the same.");
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Error: All requested information must be complete.");
        msgBox.exec();
    }
}

void winAdmin::on_btnAddService_clicked()
{
    bank->addService(ui->txtServiceName->text());
    ui->txtServiceName->setText("");
    ui->txtInfo->setText(bank->Status());
}

void winAdmin::on_btnShowBankInfo_clicked()
{
    ui->txtInfo->setText(bank->Status());
}
void winAdmin::setBank(banksys &bankSys)
{
    bank=&bankSys;
    ui->txtID->setText((QVariant(employee::Ids+1).toString()));
    ui->txtInfo->setText(bank->Status());
}
