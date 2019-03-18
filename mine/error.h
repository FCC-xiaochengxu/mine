#ifndef ERROR_H
#define ERROR_H

#include <QWidget>
#include<QToolButton>
#include<QPixmap>
#include <QStyle>
#include<QLabel>
class error : public QWidget
{
    Q_OBJECT
private:
public:
    explicit error(QWidget *parent = nullptr);
    void setTipIcon(QPixmap pixmap);
    void setTipInfo(QString info);
    ~error();
public slots:
    bool closeWidget();
private:
    QLabel *ask_label;
    QLabel *msg_label;
    QToolButton *close_button;
};

#endif // ERROR_H
