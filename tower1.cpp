#include "tower1.h"

 tower1::tower1(QPoint p1,QString p2):basetower(p1,p2){
     damage=5;
 }
 void tower1::get_target(QList<enemy*> target){
        //遍历敌人,判断是否有敌人在攻击范围内
        foreach (enemy *ene, target)
        {
            if (iftouch(position,ene->nowposition(),attackrange))
            {
                bullet1= new Bullet(position,ene->nowposition(),damage,":/picture/bullet.png",ene);
                break;
            }
            bullet1=NULL;
        }


}
 void tower1::attack(QList<Bullet*> bullet){
    bullet.push_back(bullet1);
 }
bool tower1::fire(){
     if(bullet1==NULL)
         return false;
     else
         return true;
 }
