#ifndef RECEIPT_H
#define RECEIPT_H

#include <QMainWindow>
#include <Class/customer.h>
namespace Ui {
class Receipt;
}

class Receipt : public QMainWindow
{
    Q_OBJECT

public:
    explicit Receipt(QWidget *parent = nullptr);
    ~Receipt();
    void setCustomer(customer Customer);

private slots:
    void on_btnRefresh_clicked();

private:
    customer Customer;
    Ui::Receipt *ui;
};

#endif // RECEIPT_H
