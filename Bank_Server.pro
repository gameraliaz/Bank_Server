QT       += core gui
QT += sql
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Class/banksys.cpp \
    Class/customer.cpp \
    Class/employee.cpp \
    Class/person.cpp \
    Class/procces.cpp \
    Class/timer.cpp \
    Form/customerwin.cpp \
    Form/employeewin.cpp \
    Form/receipt.cpp \
    Form/winadmin.cpp \
    Form/winloginemployee.cpp \
    db/dbmanager.cpp \
    main.cpp \
    server.cpp

HEADERS += \
    Class/banksys.h \
    Class/customer.h \
    Class/employee.h \
    Class/person.h \
    Class/procces.h \
    Class/timer.h \
    Form/customerwin.h \
    Form/employeewin.h \
    Form/receipt.h \
    Form/winadmin.h \
    Form/winloginemployee.h \
    db/dbmanager.h \
    server.h

FORMS += \
    Form/customerwin.ui \
    Form/employeewin.ui \
    Form/receipt.ui \
    Form/winadmin.ui \
    Form/winloginemployee.ui \
    server.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    db/Database.db

RESOURCES += \
    Resource.qrc
