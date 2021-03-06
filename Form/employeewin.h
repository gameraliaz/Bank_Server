#ifndef EMPLOYEEWIN_H
#define EMPLOYEEWIN_H

#include <QMainWindow>
#include <QVariant>
#include <Class/banksys.h>
namespace Ui {
class employeeWin;
}

class employeeWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit employeeWin(QWidget *parent = nullptr);
    ~employeeWin();
    void setEmployee(employee Employee);
    void setBank(banksys &bankSys);
private slots:
    void on_cmbService_currentIndexChanged(int index);

    void on_btnGetjob_clicked();

    void on_btnEndjob_clicked();

private:
    banksys *bank;
    Ui::employeeWin *ui;
    bool active;
    int service;
    employee Employee;
    int place;
};

#endif // EMPLOYEEWIN_H
