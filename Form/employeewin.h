#ifndef EMPLOYEEWIN_H
#define EMPLOYEEWIN_H

#include <QMainWindow>

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
};

#endif // EMPLOYEEWIN_H
