#include "bullet.h"
Bullet::Bullet(QPoint start, QPoint end, int damage,QString path,enemy* target):_start(start),_end(end),_damage(damage),appa(path),_target(target){

}
void Bullet::draw(QPainter *painter) const{
    painter->drawPixmap(now,appa);
};
void Bullet::move(){
    if(_target==NULL)
        return;
    float deltay =(_target->nowposition().y()-now.y())/sqrt(pow(_target->nowposition().x()-now.x(),2)+pow(_target->nowposition().y()-now.y(),2));
    float deltax =(_target->nowposition().x()-now.x())/sqrt(pow(_target->nowposition().x()-now.x(),2)+pow(_target->nowposition().y()-now.y(),2));
    if(iftouch(_target->nowposition(),now,1))
        _target->hitted(_damage);
    now.setX(now.x()+deltax);
    now.setY(now.y()+deltay);
};
void Bullet::setCurrentPos(QPoint pos){
    now=pos;
};
QPoint Bullet::currentPos() const{
    return now;
};
