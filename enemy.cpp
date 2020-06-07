#include "enemy.h"

enemy::enemy(QPoint st,QPoint en,QString path):QObject(0),appa(path){
    this->now=st;
    this->start=st;
    this->end=en;
}
void enemy::draw(QPainter*painter) const
{
    painter->drawPixmap(now,appa);
}
void enemy::move(){
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
