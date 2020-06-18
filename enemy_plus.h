#ifndef ENEMY_PLUS_H
#define ENEMY_PLUS_H
#include "enemy.h"
#include<QList>
class enemy_plus: public enemy//第二类敌人，血量较多时防御力高，速度慢，当血量小于一半时速度加快，防御力减少
{
public:
    enemy_plus(QPoint st,QPoint en,QString path);
    void draw(QPainter*painter);
    void hitted(int);
    void move();
private:

};

#endif // ENEMY_PLUS_H
