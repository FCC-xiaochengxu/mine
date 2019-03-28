#ifndef BUTTON_H
#define BUTTON_H
#include<QPushButton>
#include<QString>

class button : public QPushButton
{
    Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event);
signals:
    void sendmsg(int,int);
private:
    int x;
    int y;
    int size;
    bool Rightdouble;
    int row;
    int col;
public:
    explicit button(int x,int y,QWidget *parent=0);
    void changeimg(QString filepath);
};
#endif // BUTTON_H
