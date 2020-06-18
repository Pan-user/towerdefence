#include "enemy_plus.h"

enemy_plus::enemy_plus(QPoint st,QPoint en,QString path,QList<enemy*>* list):enemy(st,en,path)
{
    baby=list;
}
void enemy_plus::hitted(int damage){
    nowHP-=damage;
    enemy* enemy1=new enemy(now,this->end,":/picture/monster1.png");
    baby->push_back(enemy1);
    if(nowHP<=0)
    live=false;
}
