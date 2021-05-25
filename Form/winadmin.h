#ifndef WINADMIN_H
#define WINADMIN_H

#include <QMainWindow>

namespace Ui {
class winAdmin;
}

class winAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit winAdmin(QWidget *parent = nullptr);
    ~winAdmin();

private:
    Ui::winAdmin *ui;
};

#endif // WINADMIN_H
