#include "widget.h"
#include "ui_widget.h"
#include "button.h"
#include<QByteArray>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
Widget::Widget(QTcpSocket *socket,QString IP,int port,int level,QWidget *parent) :
    socket(socket),QWidget(parent),lev(level),IP(IP),port(port),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initButton(lev);
    this->B=NULL;
}
Widget::~Widget()
{
    delete this->socket;
    delete ui;
}
/*void Widget::initsocket(QString IP,int port){
    socket=new QTcpSocket();
    socket->connectToHost(IP,port);
}*/
int Widget::initButton(int level){
    int size=20;
    int width=0;
    int high=0;
    if(level==0){
        width=9*size+30;
        high=9*size+30;
        this->setMinimumSize(width,high);
        this->setMaximumSize(width,high);
        for(int row=0;row<9;row++){//列
            for(int col=0;col<9;col++){//行
                 this->B[row][col]=new Button(15+col*size,15+row*size,this);
                connect(B[row][col],SIGNAL(sendmsg(int,int)),this,SIGNAL(sendata(int,int)));
            }
        }
    }else{
        if(level==1){
            width=16*size+30;
            high=16*size+30;
            this->setMinimumSize(width,high);
            this->setMaximumSize(width,high);
            for(int row=0;row<16;row++){//列
                for(int col=0;col<16;col++){//行
                    this->B[row][col]=new Button(15+col*size,15+row*size,this);
                    connect(B[row][col],SIGNAL(sendmsg(int,int)),this,SIGNAL(sendata(int,int)));
                }
            }
        }else{
            if(level==2){
                width=16*size+30;
                high=16*size+30;
                this->setMinimumSize(width,high);
                this->setMaximumSize(width,high);
                for(int row=0;row<16;row++){//列
                    for(int col=0;col<16;col++){//行
                       this->B[row][col]=new Button(15+col*size,15+row*size,this);
                        connect(B[row][col],SIGNAL(sendmsg(int,int)),this,SIGNAL(sendata(int,int)));
                    }
                }
            }
        }
    }
    return 0;
}
void Widget::sendata(int row,int col){
    QString data=QString::number(row)+','+QString::number(col);
    this->socket->write(data.toUtf8());
    connect(socket, SIGNAL(readyRead()), this, SLOT(recvdata()));
}
void Widget::recvdata(){
    QByteArray buffer;
    buffer = socket->readAll();
    QString buf=buffer;
    QStringList list = buf.split(";");
    QStringList btnlist;
    int len=list.length();
    QString str="";
    int row;
    int col;
    for(int i=0;i<len;i++){
        str=list[i];
        btnlist=str.split(",");
        str=btnlist[0];
        row=str.toInt();
        str=btnlist[1];
        col=str.toInt();
        str=btnlist[3];
        B[row][col]->changeimg(str);
    }
}
