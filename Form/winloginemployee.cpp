#include "winloginemployee.h"
#include "ui_winloginemployee.h"

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

}
