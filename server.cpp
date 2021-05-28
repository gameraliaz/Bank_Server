#include "server.h"
#include "ui_server.h"
#include <Form/winloginemployee.h>
#include<Form/winadmin.h>

banksys Server::Bank;
DbManager Server::DbEmployee("db\\EmployeesDb.db");
Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);
}

Server::~Server()
{
    delete ui;
}

void Server::on_btnAdmin_clicked()
{
    winAdmin Winadmin;
    Winadmin.show();
}

void Server::on_btnEmployee_clicked()
{
    winLoginEmployee Winlogin;
    Winlogin.show();
}

void Server::on_btnCustomer_clicked()
{

}
