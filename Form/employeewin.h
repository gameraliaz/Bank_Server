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

private:
    Ui::employeeWin *ui;
    bool active;
};

#endif // EMPLOYEEWIN_H
