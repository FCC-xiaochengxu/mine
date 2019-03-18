#include "button.h"
#include <QApplication>
#include <QtGui>
Button::Button(int x,int y,QWidget *parent) : QPushButton(parent)
{
    this->size=25;
    this->x=x;
    this->y=y;
    this->col=(x-15)/size;
    this->row=(y-15)/size;
    this->Rightdouble=false;
    this->setGeometry(QRect(x,y,size,size));
    this->changeimg(":/res/res/blank.bmp");
}
void Button::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton)
     {
        emit sendmsg(row,col);
    }else if(event->button()==Qt::RightButton)
    {
        if(this->Rightdouble){
            changeimg(":/res/res/blank.bmp");
            this->Rightdouble=false;
        }else{
            changeimg(":/res/res/flag.bmp");
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
/*void Button::change(QString img){

    switch (img) {
    case "black":
        changeimg("");
        break;
    case "bomb":
        changeimg("");
        break;
    case "1":
        changeimg("");
        break;
    case "2":
        changeimg("");
        break;
    case "3":
        changeimg("");
        break;
    case "4":
        changeimg("");
        break;
    case "5":
        changeimg("");
        break;
    case "6":
        changeimg("");
        break;
    case "7":
        changeimg("");
        break;
    case "8":
        changeimg("");
        break;
    default:
        break;
    }
}*/
