#include "server.h"
#include "ui_server.h"
banksys Server::Bank;
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
    Winadmin = new winAdmin();
    Winadmin->show();
}

void Server::on_btnEmployee_clicked()
{
    Winlogin = new winLoginEmployee();
    Winlogin->show();
}

void Server::on_btnCustomer_clicked()
{
    WinCustomer = new CustomerWin();
    WinCustomer->show();
}
