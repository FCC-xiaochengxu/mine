#include "login.h"
#include "ui_login.h"
#include "error.h"
#include "widget.h"
#include <QCryptographicHash>
#include <QByteArray>
#include <QStringList>
login::login(QString IP,int port,QWidget *parent) :
    IP(IP),port(port),QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->socket=NULL;
    this->doubleclick=false;
}
login::~login()
{
    delete ui;
}
void login::connect_suc(){
  ui->loginButton->setEnabled(false);

}
void login::recvdata(){
    QByteArray buffer;
        //读取缓冲区数据
    buffer = socket->readAll();
    QString buf=buffer;

    QStringList list = buf.split(",");
    buf=list[0];
    if(buf!="登陆成功"){
        error *e;
        e=new error(this);
        QPixmap pixmap = QPixmap(":/res/res/error_info.png");
        e->setTipIcon(pixmap);
        e->setTipInfo(buf);
        if(e->isHidden())
        {
           e->show();
        }
        return;
    }
    QString lev=list[1];
    int level=lev.toInt();
    Widget w(this->socket,IP,port,level);
    w.show();
    this->close();

}
void login::client_dis(){
    ui->loginButton->setEnabled(true);
}
void login::on_loginButton_clicked()
{
    if(this->doubleclick){
        ui->loginButton->setText("登陆");
        this->socket->close();
        this->doubleclick=false;
    }else{
        ui->loginButton->setText("取消");
        this->doubleclick=true;
        initsocket();
        connect(socket,SIGNAL(connected()),this,SLOT(connect_suc()));
        connect(socket,SIGNAL(disconnected()),this,SLOT(client_dis()));
        QString team=ui->Edit->text();
        QString password=ui->passwordEdit->text();
        if(NULL == team||NULL==password){
            return;
        }
        QByteArray bytePwd = password.toLatin1();
        QByteArray bytePwdMd5 = QCryptographicHash::hash(bytePwd, QCryptographicHash::Md5);
        QString strPwdMd5 = bytePwdMd5.toHex();
        QString data=team+","+strPwdMd5;
        this->socket->write(data.toUtf8());
        connect(socket, SIGNAL(readyRead()), this, SLOT(recvdata()));
    }
}
void login::initsocket(){
    this->socket=new QTcpSocket();
    socket->connectToHost(this->IP,this->port);
}
