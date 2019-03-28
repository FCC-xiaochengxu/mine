#include "button.h"
#include <QApplication>
#include <QtGui>
button::button(int x,int y,QWidget *parent) : QPushButton(parent)
{
    this->size=25;
    this->x=x;
    this->y=y;
    this->col=(x-15)/size;
    this->row=(y-15)/size;
    this->Rightdouble=false;
    this->setGeometry(QRect(x,y,size,size));
    this->changeimg(":/res/res/0.bmp");
}
void Button::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton)
     {
        emit sendmsg(row,col);
    }else if(event->button()==Qt::RightButton)
    {
        if(this->Rightdouble){
            changeimg(":/res/res/0.bmp");
            this->Rightdouble=false;
        }else{
            changeimg(":/res/res/mine.bmp");
            this->Rightdouble=true;
        }
    }
}
void Button::changeimg(QString filepath){
    QIcon icon;
    QPixmap pixmap0(filepath);
    icon.addPixmap(pixmap0);
    this->setIcon(icon);
    this->setIconSize(QSize(size,size));
    this->setFixedSize(pixmap0.size());
    this->setMask(pixmap0.mask());
}
