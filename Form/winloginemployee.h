#ifndef WINLOGINEMPLOYEE_H
#define WINLOGINEMPLOYEE_H

#include <QMainWindow>
#include <Class/banksys.h>
#include <Form/employeewin.h>
#include <QVariant>

namespace Ui {
class winLoginEmployee;
}

class winLoginEmployee : public QMainWindow
{
    Q_OBJECT

public:
    explicit winLoginEmployee(QWidget *parent = nullptr);
    ~winLoginEmployee();

private slots:
    void on_btnLogin_clicked();

private:
    employeeWin *Winemp;
    Ui::winLoginEmployee *ui;
};

#endif // WINLOGINEMPLOYEE_H
