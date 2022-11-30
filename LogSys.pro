#-------------------------------------------------
#
# Project created by QtCreator 2016-03-17T12:41:38
#
#-------------------------------------------------

QT       += core sql gui widgets
QT      += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LogSys
TEMPLATE = app


SOURCES += main.cpp\
    bank.cpp \
        loginsystem.cpp \
    qdb.cpp \
       databasehandler.cpp

HEADERS  += loginsystem.h \
    bank.h \
    qdb.h   \
        databasehandler.h

FORMS    += loginsystem.ui

DISTFILES += \
    db.s3db.sql

RESOURCES += \
    elements.qrc
