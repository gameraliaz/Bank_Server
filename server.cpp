#include "server.h"
#include "ui_server.h"
#include <Form/winloginemployee.h>

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

}

void Server::on_btnEmployee_clicked()
{
    winLoginEmployee Winlogin;
    Winlogin.show();
}

void Server::on_btnCustomer_clicked()
{

}
