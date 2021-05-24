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


void Server::on_Empcreate_clicked()
{
    Bank.addEmployee(ui->Empcreate_Pass->toPlainText(),ui->Empcreate_First->toPlainText(),ui->Empcreate_Last->toPlainText(),ui->Empcreate_Birth->toPlainText(),ui->Empcreate_Identity->toPlainText());
    ui->Lable->setText("Employee added!");
}

void Server::on_Cuscreate_clicked()
{
    Bank.addCustommer(ui->Cuscreate_Ser->toPlainText().toInt());
    ui->Lable->setText("Customer added!");
}

void Server::on_Sercreate_clicked()
{
    Bank.addService(ui->Sercreate_Sername->toPlainText());
    ui->Lable->setText("Service added!");
}

void Server::on_Getjob_clicked()
{
    if(Bank.Empgetjob(Bank.loginEmployee(ui->Getjob_Id->toPlainText().toInt(),ui->Getjob_Pass->toPlainText()),ui->Getjob_Ser->toPlainText().toInt()))
        ui->Lable->setText("job started!");
    else
        ui->Lable->setText("job cant start!");
}

void Server::on_Endjob_clicked()
{
    if(Bank.Empendjob(Bank.loginEmployee(ui->Endjob_Id->toPlainText().toInt(),ui->Endjob_Pass->toPlainText())))
    {
        ui->Lable->setText("job ended!");
    }else
        ui->Lable->setText("job cant end!");
}

void Server::on_Status_clicked()
{
    ui->Statustext->setText(Bank.Status());
}
