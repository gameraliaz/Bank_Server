#include "person.h"

void person::setPerson(QString Firstname,QString Lastname,QString Birthdate,QString Identitycode)
{
    firstName=Firstname;
    lastName=Lastname;
    birthDate=Birthdate;
    identityCode=Identitycode;
}
QString person::Status()
{
    QString result="";
    result="Name : "+firstName+" "+lastName +"\tBirth date : "+birthDate+"\t Identity code : "+identityCode+'\n';
    return result;
}
