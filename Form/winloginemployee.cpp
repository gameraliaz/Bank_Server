#include "winloginemployee.h"
#include "ui_winloginemployee.h"

winLoginEmployee::winLoginEmployee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winLoginEmployee)
{
    ui->setupUi(this);
    ui->txtID->
}

winLoginEmployee::~winLoginEmployee()
{
    delete ui;
}
