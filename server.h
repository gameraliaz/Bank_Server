#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QVariant>
#include <Class/banksys.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Server; }
QT_END_NAMESPACE

class Server : public QMainWindow
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();
private slots:

    void on_btnAdmin_clicked();

    void on_btnEmployee_clicked();

    void on_btnCustomer_clicked();

private:
    static banksys Bank;
    Ui::Server *ui;
};
#endif // SERVER_H
