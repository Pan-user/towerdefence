#include "enemy_plus.h"

enemy_plus::enemy_plus(QPoint st,QPoint en,QString path):enemy(st,en,path)
{
    maxHP=300;
    nowHP=300;
}
void enemy_plus::hitted(int damage){
    if(nowHP>maxHP/2)
    nowHP-=damage-5;
    else
    nowHP-=damage+5;
    if(nowHP<=0)
    live=false;
}
void enemy_plus::move(){
    if(nowHP>maxHP/2){
        now.setX(now.x()+(end.x()-start.x())/500);
        now.setY(now.y()+(end.y()-start.y())/500);
    }
    else{
        now.setX(now.x()+(end.x()-start.x())/250);
        now.setY(now.y()+(end.y()-start.y())/250);
    }
    center=QPoint(now.x()+appa.size().width()/2,now.y()+appa.size().height()/2);
}
void enemy_plus::draw(QPainter*painter)
    {
        painter->save();
        QPoint barPoint = now + QPoint(13 , -5);
        painter->setBrush(Qt::red);
        QRect healthBar1(barPoint, QSize(50, 2));
        painter->drawRect(healthBar1);
        painter->setBrush(Qt::green);
        QRect healthBar2(barPoint, QSize((double)nowHP / maxHP * 50, 2));
        painter->drawRect(healthBar2);// 绘制血条
        painter->restore();
        if(nowHP<=maxHP/2){
            QPixmap appa2(":/picture/monster1.png");
            appa=appa2;
        }
            painter->drawPixmap(now,appa);

    }
