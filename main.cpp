#include "loginsystem.h"
#include <QApplication>
#include "databasehandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSystem w;
    w.show();
    
    DatabaseHandler dataDB;
    dataDB.createuser();
    return a.exec();
}
