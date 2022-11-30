#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QSqlTableModel>
#include "databasehandler.h"

namespace Ui {
class LoginSystem;
}

class LoginSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginSystem(QWidget *parent = 0);
    ~LoginSystem();
    bool Login(QString u, QString p);
    bool loggedIn;
    QString picName;
    QString picDir = QCoreApplication::applicationDirPath()+"/../../LogSys/users/avatar";
    QSqlTableModel* tblMdl;
    DatabaseHandler datalibDb;

private slots:
    void on_completeRegButton_3_clicked();
    void on_loginButton_clicked();

    void on_logoutButton_clicked();

    void on_completeRegButton_clicked();

    void on_debitpushButton_clicked();

    void on_completeRegButton_2_clicked();

    void on_backButton_8_clicked();

    void on_backButton_7_clicked();

    void on_backButton_clicked();

    void on_regButton_clicked();

    void on_backButton_2_clicked();

    void on_backButton_3_clicked();

    void on_backButton_4_clicked();

    void on_creditPushButton_clicked();

    void on_editButton_clicked();

    void on_delButton_clicked();

    void on_editedButton_clicked();

    void on_winStack_currentChanged(int arg1);

    void on_uplButton_clicked();

    void on_uplButton_2_clicked();

    void on_adminButton_clicked();

    void on_pageButton_clicked();

    void on_editedButton_2_clicked();

    void on_backButton_5_clicked();

    void on_userBrowse_clicked();

    void on_delUButton_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_adminBrowse_clicked();

    void on_delAButton_clicked();

private:
    Ui::LoginSystem *ui;
    QString username;
    QString password;
};

#endif // LOGINSYSTEM_H
