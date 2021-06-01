#ifndef SERVER_H
#define SERVER_H

#include <QApplication>
#include <QMainWindow>
#include <QVariant>
#include <Class/banksys.h>
#include <Form/winloginemployee.h>
#include <Form/winadmin.h>
#include <Form/customerwin.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Server; }
QT_END_NAMESPACE

class Server : public QMainWindow
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();
    static banksys Bank;
private slots:

    void on_btnAdmin_clicked();

    void on_btnEmployee_clicked();

    void on_btnCustomer_clicked();

private:
    Ui::Server *ui;
    winAdmin *Winadmin;
    winLoginEmployee *Winlogin;
    CustomerWin *WinCustomer;
};
#endif // SERVER_H
