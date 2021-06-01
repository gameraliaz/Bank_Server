#include "winadmin.h"
#include "ui_winadmin.h"
#include <Class/employee.h>
#include <server.h>
#include <QMessageBox>
winAdmin::winAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winAdmin)
{
    ui->setupUi(this);
    ui->txtID->setText((QVariant(employee::Ids+1).toString()));
    ui->txtInfo->setText(Server::Bank.Status());
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
            Server::Bank.addEmployee(ui->txtPassword->text(),ui->txtFirstName->text(),ui->txtLastName->text(),ui->dpBirthDate->text(),ui->txtIdentity->text());
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
    Server::Bank.addService(ui->txtServiceName->text());
}

void winAdmin::on_btnShowBankInfo_clicked()
{
    ui->txtInfo->setText(Server::Bank.Status());
}
