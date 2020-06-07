#include "basetower.h"
#include <QPainter>

basetower::basetower(QPoint p1,QString p2):QObject(0),position(p1),apparence(p2){
    apparence = apparence.scaled(apparence.width()*1.2,apparence.height()*1.2,Qt::KeepAspectRatio);
}

void basetower::draw(QPainter*painter) const
{
    painter->drawPixmap(position,apparence);
}
QPoint basetower::getp(){return position;}
