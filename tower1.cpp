#include "tower1.h"

tower1::tower1(QPoint p1,QString p2):basetower(p1,p2){
     damage=10;
     fire=false;
     movespeed = this->startTimer(10);
     firespeed = this->startTimer(500);

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
            }
            fire=false;
        }

}
 void tower1::attack(){
     if(fire)
     {
        Bullet* onebullet= new Bullet(center,mytarget->centerposition(),damage,":/picture/bullet.png",mytarget);
        mybullet.push_back(onebullet);
     }
 }
bool tower1::iffire(){

         return fire;
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
