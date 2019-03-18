#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpSocket>
#include<QString>
#include"button.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private slots:
    void sendata(int row,int col);
signals:
    void change(int);
private:
    int lev;
    QTcpSocket *socket;
    QString IP;
    int port;
    void *B;
public:
    explicit Widget(QWidget *parent = 0);
    explicit Widget(QTcpSocket *socket,QString IP,int level,int port,QWidget *parent = 0);
    int initButton(int level);
//    void initsocket(QString,int);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
