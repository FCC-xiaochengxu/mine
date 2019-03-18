#ifndef BUTTON_H
#define BUTTON_H
#include<QPushButton>
#include<QString>
class Button : public QPushButton
{
    Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event);
    void changeimg(QString filepath);
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
    explicit Button(int x,int y,QWidget *parent=0);
    void change(QString img);
};

#endif // BUTTON_H