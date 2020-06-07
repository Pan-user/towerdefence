#include "button.h"
#include<QPixmap>
#include <QBitmap>
#include <QMouseEvent>
Button::Button(QString m):QPushButton(0){
    QPixmap pic(m);
    this->setFixedSize(pic.width()/1.5,pic.height()/1.5);
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pic);
    this->setIconSize(QSize(pic.width()/1.5,pic.height()/1.5));

}
/*void Button::mouseReleaseEvent(QMouseEvent *e)

{

    if (Qt::LeftButton == e->button())

    {

        emit leftClicked();

    }

    else if (Qt::RightButton == e->button())

    {

        emit rightClicked();

    }

}*/
