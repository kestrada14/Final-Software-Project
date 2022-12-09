#include "databasehandler.h"
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QVariantMap>

DatabaseHandler::DatabaseHandler(QObject *parent)
    : QObject(parent){
    m_networkManager = new QNetworkAccessManager(this);
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://bank-9c1c4-default-rtdb.firebaseio.com/NewUser.json")));
    connect(m_networkReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyReadyRead);
}

DatabaseHandler::~DatabaseHandler()
{
    m_networkManager->deleteLater();
}

void DatabaseHandler::networkReplyReadyRead()
{
    Temp = m_networkReply->readAll();

}

void DatabaseHandler::createuser(QString Username,QString Password,QString Email,QString Name, QString Address, QString PhoneNumber,QString Money)
{
    QVariantMap newClient;
    newClient["Username"] = Username;
    newClient["Password"] = Password;
    newClient["Phone Number"]= PhoneNumber;
    newClient["Email"]= Email;
    newClient["Name"]= Name;
    newClient["Address"]= Address;
    newClient["ZMoney"] = Money;
    QJsonDocument jsonDoc = QJsonDocument:: fromVariant(newClient);
    QNetworkRequest newClientRequestr(QUrl("https://bank-9c1c4-default-rtdb.firebaseio.com/NewUser.json"));
    newClientRequestr.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    m_networkManager->post(newClientRequestr,jsonDoc.toJson());

    connect(m_networkReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyReadyRead);
}

bool DatabaseHandler::findUser(QString Username, QString Password)
{
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://bank-9c1c4-default-rtdb.firebaseio.com/NewUser.json")));
    connect(m_networkReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyReadyRead);


    std::string user = Username.toStdString();
    std::string pass = Password.toStdString();

   qDebug() << Username << Temp;
      int j = 0;
      int record= 0;
    if(Temp.contains(user) && Temp.contains(pass)){
        while ((j = Temp.indexOf(user, j)) != -1) {
            qDebug() << "Found user" << j << Qt::endl;
            record =j;
            ++j;
        }

        qDebug() << j << record ;
        while ((record = Temp.indexOf("ZMoney", record)) != -1) {
            qDebug() << "Found MONEY" << record << Qt::endl;
            ++record;
            break;
        }
        record+=8;
        for (int island = Temp.lastIndexOf("ZMoney")+10; island < Temp.lastIndexOf("ZMoney")+18 ; island++ ){
            if(Temp[island] == 34){
                       break;
                    }
            Money = Money + Temp[island];
        }

        TempUser = Username;
        return true;

    }
    else{

        return false;
    }
}

