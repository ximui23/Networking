#include <QCoreApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString serverName = "DESKTOP-8TLTN7L\\SQLEXPRESS"; //Take from SQL Manager
    QString dbName = "test"; //Name of the databse you are trying to connect to
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3"); //specifies driver

    db.setConnectOptions();

    QString dsn = QString("DRIVER={SQL Native Client};SERVER=%1;DATABASE=%2;Trusted Connection=Yes;").arg(serverName).arg(dbName);
    //%1 is an argument which mentions serverName = "DESKTOP-8TLTN7L\SQLEXPRESS"
    //%2 is argument 2 - arg(dbName)

   //use only one of these at the time

    //db.setDatabaseName(dsn);
    db.setDatabaseName("mydsn32");
    //db.setDatabaseName("mydsn64");

    qDebug() << QSqlDatabase::isDriverAvailable("QODBC3");

    if (db.open())
    {
        qDebug() << "Connection opened!";

        qDebug() << "Closing...";
        db.close();
    }
    else
    {
        qDebug() << "Error = " << db.lastError().text();
    }


    return a.exec();
}
