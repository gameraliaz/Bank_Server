#include "winloginemployee.h"
#include "ui_winloginemployee.h"
#include <server.h>
#include <Form/employeewin.h>
#include <QMessageBox>
winLoginEmployee::winLoginEmployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winLoginEmployee)
{
    ui->setupUi(this);
}

winLoginEmployee::~winLoginEmployee()
{
    delete ui;
}

void winLoginEmployee::on_btnLogin_clicked()
{
    if(Server::DbEmployee.checkinf(ui->txtID->text().toInt(),ui->txtPass->text()))
    {
        employeeWin Winemp;
        Winemp.setEmployee(Server::Bank.loginEmployee(ui->txtID->text().toInt(),ui->txtPass->text()));
        Winemp.show();
        this->close();
    }else
    {
        QMessageBox msgBox;
        msgBox.setText("Error: Password or Id is not correct.");
        msgBox.exec();
    }
}
