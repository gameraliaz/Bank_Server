#ifndef CUSTOMERWIN_H
#define CUSTOMERWIN_H

#include <QMainWindow>
#include <Form/receipt.h>
#include <Class/banksys.h>
namespace Ui {
class CustomerWin;
}

class CustomerWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerWin(QWidget *parent = nullptr);
    ~CustomerWin();
    void setBank(banksys &bankSys);

private slots:
    void on_btnGet_clicked();

private:
    banksys *bank;
    Receipt *WinReceipt;
    Ui::CustomerWin *ui;
};

#endif // CUSTOMERWIN_H
