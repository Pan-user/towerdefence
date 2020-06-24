#include "tower2.h"

tower2::tower2(QPoint p1,QString p2):basetower(p1,p2){
    apparence = apparence.scaled(apparence.width()*1.2,apparence.height()*1.2,Qt::KeepAspectRatio);
    center=QPoint(p1.x()+apparence.size().width()*1.2/2,p1.y()+apparence.size().height()*1.2/2);
     damage=10;
     waverange=0;
     cost=150;
     fire=false;
     movespeed = this->startTimer(5);
     firespeed = this->startTimer(1000);
     attackrange=150;
 }
void tower2::draw(QPainter*painter) const
{
    painter->drawPixmap(position,apparence);
    painter->save();
    painter->setPen(QPen(Qt::red, 5, Qt::DashDotLine, Qt::RoundCap));
    painter->drawEllipse(center, waverange, waverange);
     painter->restore();
}
 void tower2::get_target(QList<enemy *> target){
     //mytarget.clear();//遍历前清除旧目标
     fire=false;//重置开火状态
     foreach (enemy *ene, target)//遍历敌人,判断是否有敌人在攻击范围内
        {
            if (iftouch(center,ene->centerposition(),attackrange))
            {
                mytarget.push_back(ene);
                fire=true;
            }
                                //锁定所有进入视野的目标


}
 }
 void tower2::attack(){
     if(fire)
     {
        foreach(enemy* target,mytarget)
            if(target->ifhurted())
            target->resethurt();
         waverange=1;
     }//若有敌人释放攻击波
 }
bool tower2::ifhit(QPoint p1,QPoint p2,float range){
     int ifx = p1.x() - p2.x();
         int ify = p1.y() - p2.y();
         float distance = sqrt(ifx * ifx + ify * ify);
         if (distance <= (range+1)&&distance>=(range-1))
             return true;
         else
             return false;

}
void tower2::timerEvent(QTimerEvent *event){
    if ((event->timerId() == movespeed)&&(waverange!=0))
    {
        if(waverange<attackrange)
            waverange+=1;
        else
            waverange=0;//到达最大范围后攻击波消失等待下一次释放
        foreach(enemy* target,mytarget)
         if(iftouch(center,target->centerposition(),waverange))
         {
               if(!target->ifhurted())
               {
                   target->hitted(damage);
                   target->resethurt();
               }

         }//敌人被攻击波扫过一次后结算伤害
    }
    else if(event->timerId() == firespeed)
        this->attack();

}
void tower2::update(){
    damage+=20;
    attackrange+=50;
    movespeed = this->startTimer(4);
    firespeed = this->startTimer(800);
    apparence=QPixmap(":/picture/tower4.png");

}
