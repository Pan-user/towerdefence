#include "enemy.h"

enemy::enemy(QPoint st,QPoint en,QString path,chapter* game):QObject(0),appa(path),maxHP(100),nowHP(100),thispage(game){
    this->now=st;
    this->start=st;
    this->end=en;

}
void enemy::draw(QPainter*painter) const
{
    //if (!live)
       //return;
    painter->save();
    QPoint healthPoint = now + QPoint(13 , -5);	// 绘制血条
    painter->setBrush(Qt::red);
    QRect healthBar1(healthPoint, QSize(50, 2));
    painter->drawRect(healthBar1);
    painter->setBrush(Qt::green);
    QRect healthBar2(healthPoint, QSize((double)nowHP / maxHP * 50, 2));
    painter->drawRect(healthBar2);
    painter->drawPixmap(now,appa);
    painter->restore();

}
void enemy::move(){
    //if (!live)
       //return;
    now.setX(now.x()+(end.x()-start.x())/300);
    now.setY(now.y()+(end.y()-start.y())/300);
}
void enemy::trans(QPoint target){
    start=end;
    end=target;
}
QPoint enemy::nowposition(){
    return(now);
}
QPoint enemy::endposition(){
    return(end);
}
bool enemy::ifarrive(const QPoint p){
   if(enetest.iftouch(p,now,0))
       return true;
}
