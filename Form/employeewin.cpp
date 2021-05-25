#include "employeewin.h"
#include "ui_employeewin.h"

employeeWin::employeeWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::employeeWin)
{
    ui->setupUi(this);
    active=false;
}

employeeWin::~employeeWin()
{
    delete ui;
}
