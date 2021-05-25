#include "winadmin.h"
#include "ui_winadmin.h"

winAdmin::winAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winAdmin)
{
    ui->setupUi(this);
}

winAdmin::~winAdmin()
{
    delete ui;
}
