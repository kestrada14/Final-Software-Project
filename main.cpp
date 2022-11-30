#include "loginsystem.h"
#include <QApplication>
#include "databasehandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginSystem w;
    w.show();
    
    return a.exec();
}
