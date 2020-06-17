#include "tower2.h"

tower2::tower2(QPoint p1,QString p2):basetower(p1,p2){
     damage=10;
     fire=false;
     movespeed = this->startTimer(8);
     firespeed = this->startTimer(500);

 }
void tower2::draw(QPainter*painter) const
{
    painter->drawPixmap(position,apparence);
    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(center, attackrange, attackrange);
     painter->restore();
}
 void tower2::get_target(QList<enemy *> target){
      int i=0;
     //遍历敌人,判断是否有敌人在攻击范围内
     foreach (enemy *ene, target)
        {
            if (iftouch(center,ene->centerposition(),attackrange))
            {
                mytarget.push_back(ene);
                fire=true;
                i=1;
            }//只锁定所有进入视野的目标
            if(!i)
            fire=false;//若没有敌人则关闭开火
        }

}
 void tower2::attack(){
     if(fire)
     {
     }
 }


void tower2::timerEvent(QTimerEvent *event){
    if (event->timerId() == movespeed)
    {

    }
    else if (event->timerId() == firespeed)
    {
       this->attack();
    }
}
