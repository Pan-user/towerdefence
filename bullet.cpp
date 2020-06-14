#include "Bullet.h"

void Bullet::draw(QPainter *painter) const{
    painter->drawPixmap(now,appa);
};
void Bullet::move(){
    float deltay =(_end.y()-now.y())/sqrt(pow(_end.x()-now.x(),2)+pow(_end.y()-now.y(),2));
    float deltax =(_end.x()-now.x())/sqrt(pow(_end.x()-now.x(),2)+pow(_end.y()-now.y(),2));
    now.setX(now.x()+deltax);
    now.setY(now.y()+deltay);
};
void Bullet::setCurrentPos(QPoint pos){
    now=pos;
};
QPoint Bullet::currentPos() const{
    return now;
};
