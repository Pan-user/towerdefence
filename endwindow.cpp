#include "endwindow.h"
#include<QLabel>
endwindow::endwindow(QWidget *parent) : QWidget(parent),status(false)
{
            this->setFixedSize(600,400);
            setWindowTitle("END");
            QLabel* final=new QLabel(this);
            final->setFont(QFont("Microsoft YaHei", 50, QFont::Bold));
            final->setStyleSheet("color:red;");
            if(status)
                final->setText("W I N");
            else
                final->setText("L O S E");
                final->move(150,150);
                final->show();
}
void endwindow::set(bool s){
    status=s;
}
