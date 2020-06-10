#include "basetower.h"
#include <QPainter>

basetower::basetower(QPoint p1,QString p2):QObject(0),position(p1),apparence(p2),fire(false),attackrange(100),center(p1.x()+apparence.size().width()*1.2/2,p1.y()+apparence.size().height()*1.2/2){
    apparence = apparence.scaled(apparence.width()*1.2,apparence.height()*1.2,Qt::KeepAspectRatio);
    center=QPoint(p1.x()+apparence.size().width()/2,p1.y()+apparence.size().height()/2+10);


}

void basetower::draw(QPainter*painter) const
{
    painter->drawPixmap(position,apparence);
    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(center, attackrange, attackrange);
     painter->restore();
}
QPoint basetower::getp(){return position;}
