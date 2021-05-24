#ifndef WINLOGINEMPLOYEE_H
#define WINLOGINEMPLOYEE_H

#include <QMainWindow>

namespace Ui {
class winLoginEmployee;
}

class winLoginEmployee : public QMainWindow
{
    Q_OBJECT

public:
    explicit winLoginEmployee(QWidget *parent = nullptr);
    ~winLoginEmployee();

private:
    Ui::winLoginEmployee *ui;
};

#endif // WINLOGINEMPLOYEE_H
