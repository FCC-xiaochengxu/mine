#include "widget.h"
#include "login.h"
#include <QApplication>
#define IP "47.101.66.68"
#define port 8888
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 /*   for(int i=0;i<3;i++){//i为等级
          Widget w(i,0);
          w.show();
    }*/
    login l(IP,port);
    l.show();

    return a.exec();
}
