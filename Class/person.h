#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QVariant>
class person
{
    protected:
        QString firstName;
        QString lastName;
        QString birthDate;
        QString identityCode; //We define the type of string because we do not need to do mathematical calculations
        void setPerson(QString Firstname,QString Lastname,QString Birthdate,QString Identitycode);
        QString Status();
};

#endif // PERSON_H
