#include "tower1.h"

tower1::tower1(QPoint p1,QString p2):basetower(p1,p2){
    apparence = apparence.scaled(apparence.width()*1.5,apparence.height()*1.5,Qt::KeepAspectRatio);
    center=QPoint(p1.x()+apparence.size().width()*1.5/2-13,p1.y()+apparence.size().height()*1.5/2-13);
    damage=20;
    cost=100;
    fire=false;
    movespeed = this->startTimer(10);
    firespeed = this->startTimer(500);
    attackrange=150;
 }
void tower1::draw(QPainter*painter) const
{
    painter->drawPixmap(position,apparence);
    foreach (Bullet* one,mybullet) {
       one->draw(painter);
    }
    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(center, attackrange, attackrange);
     painter->restore();
}
 void tower1::get_target(QList<enemy *> target){
        //遍历敌人,判断是否有敌人在攻击范围内
     foreach (enemy *ene, target)
        {
            if (iftouch(center,ene->centerposition(),attackrange))
            {
                mytarget=ene;
                fire=true;
                break;
            }//只锁定最先进入视野的目标
            fire=false;//若没有敌人则关闭开火
        }
     if(target.empty())
         fire=false;

}
 void tower1::attack(){
     if(fire)
     {
        Bullet* onebullet= new Bullet(center,mytarget->centerposition(),damage,":/picture/bullet.png",mytarget);
        mybullet.push_back(onebullet);
     }
 }


void tower1::timerEvent(QTimerEvent *event){
    if (event->timerId() == movespeed)
    {
        foreach(Bullet* one,mybullet)
        {
           if (one->ifhit())
               mybullet.removeOne(one);
           else
            one->move();
        }
    }
    else if (event->timerId() == firespeed)
    {
       this->attack();
    }
}
void tower1::update(){
    damage+=10;
    firespeed = this->startTimer(300);
    apparence=QPixmap(":/picture/tower3.png");

}
