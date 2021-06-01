#ifndef WINADMIN_H
#define WINADMIN_H

#include <QMainWindow>
#include <QVariant>
namespace Ui {
class winAdmin;
}

class winAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit winAdmin(QWidget *parent = nullptr);
    ~winAdmin();

private slots:
    void on_btnCreateEmployee_clicked();

    void on_btnAddService_clicked();

    void on_btnShowBankInfo_clicked();

private:
    Ui::winAdmin *ui;
};

#endif // WINADMIN_H
