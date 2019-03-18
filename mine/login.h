#ifndef LOGIN_H
#define LOGIN_H
#include<QTcpSocket>
#include <QWidget>
#include<QString>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QString IP="47.101.66.68",int port=8888,QWidget *parent = 0);
    ~login();
private:
    void initsocket();
private slots:
    void on_loginButton_clicked();
    void connect_suc();
    void client_dis();
    void recvdata();
private:
    Ui::login *ui;
    QTcpSocket *socket;
    int port;
    QString IP;
    bool doubleclick;
};

#endif // LOGIN_H
