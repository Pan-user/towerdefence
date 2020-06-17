#include "enemy.h"

enemy::enemy(QPoint st,QPoint en,QString path):QObject(0),appa(path),maxHP(100),nowHP(100),live(true),damage(50){
    this->now=st;
    this->start=st;
    this->end=en;
    hurted=false;
    center=QPoint(now.x()+appa.size().width()/2,now.y()+appa.size().height()/2);
}
void enemy::draw(QPainter*painter) const
{
    if (!live)
       return;
    painter->save();
    QPoint barPoint = now + QPoint(13 , -5);	// 绘制血条
    painter->setBrush(Qt::red);
    QRect healthBar1(barPoint, QSize(50, 2));
    painter->drawRect(healthBar1);
    painter->setBrush(Qt::green);
    QRect healthBar2(barPoint, QSize((double)nowHP / maxHP * 50, 2));
    painter->drawRect(healthBar2);
    painter->drawPixmap(now,appa);
    painter->restore();

}
void enemy::move(){
    if (!live)
       return;
    now.setX(now.x()+(end.x()-start.x())/300);
    now.setY(now.y()+(end.y()-start.y())/300);
    center=QPoint(now.x()+appa.size().width()/2,now.y()+appa.size().height()/2);
}
void enemy::trans(QPoint target){
    start=end;
    end=target;
}
QPoint enemy::nowposition(){
    return(now);
}
QPoint enemy::endposition(){
    return(end);
}
QPoint enemy::centerposition(){
    return(center);
}
void enemy::hitted(int damage){
    nowHP-=damage;
    if(nowHP<=0)
    live=false;
}
int enemy::arrive(){return damage;}//走入基地造成伤害
bool enemy::ifalive(){return live;}
bool enemy::ifhurted(){
    return hurted;
}
void enemy::resethurt(){
    if(hurted)
    hurted=false;
    else
    hurted=true;
}//为塔2设计，判断是否被攻击过和重置攻击
