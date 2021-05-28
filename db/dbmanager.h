#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QVariant>
class DbManager
{
public:

    DbManager(const QString& path);
    ~DbManager();
    bool isOpen() const;
    bool createTable();
    bool addEmployee(QString password,QString firstname,QString lastname,QString birthdate,QString identity);
    bool addEmployee(int id,QString password,QString firstname,QString lastname,QString birthdate,QString identity);
    bool removeEmployee(int ID);
    bool employeeExists(int id);
    void printAllEmployee() const;
    bool removeAllEmployee();
    bool editEmployee(int ID,QString name,bool wNeed);
    QString giveInfo(int ID,int wNeed);
    bool checkinf(int id,QString pass);


private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
