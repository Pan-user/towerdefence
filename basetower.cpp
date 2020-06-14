#include "basetower.h"
basetower::basetower(QPoint p1,QString p2,chapter* game):QObject(0),position(p1),apparence(p2),center(p1.x()+apparence.size().width()*1.2/2,p1.y()+apparence.size().height()*1.2/2),attackrange(100),fire(false),thispage(game){
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
void basetower::attack(){



        // 遍历敌人,看是否有敌人在攻击范围内
        QList<enemy *> enemyList=thispage->getenemy();
        foreach (enemy *enemy, enemyList)
        {
            if ()
            {

                break;
            }
        }

}
