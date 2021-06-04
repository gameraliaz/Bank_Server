#include "server.h"
#include "ui_server.h"
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
    Winadmin->setBank(Bank);
    Winadmin->show();
}

void Server::on_btnEmployee_clicked()
{
    Winlogin = new winLoginEmployee();
    Winlogin->setBank(Bank);
    Winlogin->show();
}

void Server::on_btnCustomer_clicked()
{
    WinCustomer = new CustomerWin();
    WinCustomer->setBank(Bank);
    WinCustomer->show();
}
