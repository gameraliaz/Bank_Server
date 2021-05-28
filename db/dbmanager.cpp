#include <db/dbmanager.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include <QMessageBox>

DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        QMessageBox msgBox;
        msgBox.setText("Error: connection with database fail.");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Database: connection ok.");
        msgBox.exec();
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createTable()
{
    bool success = true;

    QSqlQuery query;
    query.prepare("CREATE TABLE employee(id INTEGER PRIMARY KEY, firstname TEXT, lastname TEXT, birthdate TEXT, identity TEXT,password TEXT);");

    if (!query.exec())
    {
        QMessageBox msgBox;
        msgBox.setText("Couldn't create the table 'employee': one might already exist.");
        msgBox.exec();
        success = false;
    }

    return success;
}

bool DbManager::addEmployee(QString password,QString firstname,QString lastname,QString birthdate,QString identity)
{
    bool success = false;
    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO employee (firstname,lastname,birthdate,identity ,password) VALUES (:firstname,:lastname,:birthdate,:identity , :password)");
    queryAdd.bindValue(":firstname", firstname);
    queryAdd.bindValue(":lastname", lastname);
    queryAdd.bindValue(":birthdate", birthdate);
    queryAdd.bindValue(":identity", identity);
    queryAdd.bindValue(":password", password);
    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("add employee failed: " + queryAdd.lastError().text());
        msgBox.exec();
    }
    return success;
}

bool DbManager::addEmployee(int id,QString password,QString firstname,QString lastname,QString birthdate,QString identity)
{
    bool success = false;
    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO employee (id,firstname,lastname,birthdate,identity ,password) VALUES (:firstname,:lastname,:birthdate,:identity , :password)");
    queryAdd.bindValue(":id", id);
    queryAdd.bindValue(":firstname", firstname);
    queryAdd.bindValue(":lastname", lastname);
    queryAdd.bindValue(":birthdate", birthdate);
    queryAdd.bindValue(":identity", identity);
    queryAdd.bindValue(":password", password);
    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("add employee failed: " + queryAdd.lastError().text());
        msgBox.exec();
    }
    return success;
}

bool DbManager::removeEmployee(int ID)
{
    bool success = false;
    QSqlQuery queryDelete;
    queryDelete.prepare("DELETE FROM employee WHERE id = (:id)");
    queryDelete.bindValue(":id", ID);
    success = queryDelete.exec();

    if(!success)
    {
        QMessageBox msgBox;
        msgBox.setText("remove Employee failed: "+queryDelete.lastError().text());
        msgBox.exec();
    }

    return success;
}

void DbManager::printAllEmployee() const
{
    qDebug() << "Employee in db:";
    QSqlQuery query("SELECT * FROM employee");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}

bool DbManager::employeeExists(int id)
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM people WHERE id = (:id)");
    checkQuery.bindValue(":id", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("employee exists failed: "+checkQuery.lastError().text());
        msgBox.exec();
    }

    return exists;
}

bool DbManager::removeAllEmployee()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM employee");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("remove all employee failed: "+removeQuery.lastError().text());
        msgBox.exec();
    }

    return success;
}

QString DbManager::giveInfo(int ID,int wNeed)//wNeed   1=> firstname  2=> lastname  3=> birthdate  4=> identity  5=>password
{
    QSqlQuery query("SELECT * FROM employee");
    while (query.next())
    {
        if(query.value(0).toInt()==ID)
        {
            return  query.value(wNeed).toString();
        }
    }
    return "-0";
}

bool DbManager::checkinf(int id,QString password)
{
    QSqlQuery query("SELECT * FROM employee");
    int idpass = query.record().indexOf("password");
    while (query.next())
    {
        if(query.value(0).toInt()==id)
        {
            QString pass = query.value(idpass).toString();
            if(pass==password)
            {
                return true;
            }else
            {
                return false;
            }
        }
    }
    return false;
}
