#ifndef ENEMY_PLUS_H
#define ENEMY_PLUS_H
#include "enemy.h"
#include<QList>
class enemy_plus: public enemy//第二类敌人，血量较少，移动缓慢但是会发射子弹给基地造成伤害，
{
public:
    enemy_plus(QPoint st,QPoint en,QString path,QList<enemy*>* list);
    void hitted(int);
private:
    QList<enemy*>* baby;
};

#endif // ENEMY_PLUS_H
