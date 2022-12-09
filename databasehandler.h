#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>


class DatabaseHandler : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();
            QString TempUser;
            QString Money;


 public slots:
    void networkReplyReadyRead();
    void createuser(QString Username,QString Password,QString Email,QString Name, QString Address, QString PhoneNumber,QString Money);
    bool findUser(QString Username,QString Password);

signals:

private:
       QNetworkAccessManager * m_networkManager;
        QNetworkReply * m_networkReply;
        QNetworkReply * m_networkRequest;
        QByteArray Temp;

};


#endif // DATABASEHANDLER_H
