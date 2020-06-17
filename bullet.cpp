#include "bullet.h"
Bullet::Bullet(QPoint start, QPoint end, int damage,QString path,enemy* target):_start(start),_end(end),_damage(damage),appa(path),_target(target),now(start),hit(false){
    appa=appa.scaled(appa.width()/5,appa.height()/5,Qt::KeepAspectRatio);
}
void Bullet::draw(QPainter *painter) const{
    painter->drawPixmap(now,appa);
};
void Bullet::move(){

    int deltay =5*(_target->centerposition().y()-now.y())/sqrt(pow(_target->centerposition().x()-now.x(),2)+pow(_target->centerposition().y()-now.y(),2));
    int deltax =5*(_target->centerposition().x()-now.x())/sqrt(pow(_target->centerposition().x()-now.x(),2)+pow(_target->centerposition().y()-now.y(),2));
    //用三角函数值移动
    if(iftouch(_target->centerposition(),now,5))
    {
        _target->hitted(_damage);
        hit=true;
    }
    now.setX(now.x()+deltax);
    now.setY(now.y()+deltay);
};
void Bullet::setCurrentPos(QPoint pos){
    now=pos;
};
QPoint Bullet::currentPos() const{
    return now;
};
bool Bullet::ifhit(){
    return hit;
}
