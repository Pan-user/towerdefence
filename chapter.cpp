#include "chapter.h"
#include <QPaintEvent>
#include <QPainter>
#include <basetower.h>
#include "enemy.h"
#include"pos.h"
#include<QTimer>
#include "test.h"
chapter::chapter(QWidget *parent) : QWidget(parent),p1(400,600),p2(970,600),p3(970,100)
{


    this->setFixedSize(1200,800);
    setWindowTitle("第一关");
    load();
    loadwave();
    foreach(Pos* position,poslist)
    {
        position->setParent(this);
        position->move(position->px(),position->py());
        connect(position, &Pos::clicked, this, [ = ] {
            set(position);
                });
    }//左键放塔或拆塔
    QTimer *timer1 = new QTimer(this);
    QTimer *timer2 = new QTimer(this);
    QTimer *timer3 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(updatewhole()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(loadwave()));
        timer2->start(2000);
        timer1->start(10);
}



void chapter::load(){

                Pos* posi[]={
                      new Pos(QPoint(450,500)),
                      new Pos(QPoint(600,500)),
                      new Pos(QPoint(880,500)),
                      new Pos(QPoint(880,300)),
                      new Pos(QPoint(1080,400)),
                      new Pos(QPoint(700,690)),
                      new Pos(QPoint(1000,690)),
                      new Pos(QPoint(500,690)),
                      new Pos(QPoint(450,690)),
                     };
                /*QPoint* wp[]={
                   new QPoint(400,600),
                   new QPoint(900,600),
                   new QPoint(900,100)};
               for(int i=0;i<3;i++)
                {
                   waypoint.push_back(wp[i]);
                    update();
               }*/

            for(int i=0;i<8;i++)
            {
            poslist.push_back(posi[i]);

            update();}

    }
void chapter::loadwave(){
    enemy* enemy1=new enemy(p1,p2,":/picture/tower2.png");
    enemylist.push_back(enemy1);
    update();
    repaint();
}
void chapter::set(Pos* p){
    if(p->getif())
     {
        foreach(tower1* tow,towerlist)
         if(tow->getp()==QPoint(p->px(),p->py()-10))
             towerlist.removeOne(tow);
    }
   else
    {
     tower1* tower=new tower1(QPoint(p->px(),p->py()-10),":/picture/tower1.png");
     towerlist.push_back(tower);
    }
    p->change();
    update();
    repaint();


}//放塔或拆塔

void chapter::paintEvent(QPaintEvent *)

{


    QPainter painter(this);
    QPixmap preview(":/picture/map.png");
    painter.drawPixmap(0,0,this->width(),this->height(),preview);
    foreach(tower1* tow,towerlist)
    {

        tow->draw(&painter);

    }
    foreach(enemy* ene,enemylist)
    {
        ene->setParent(this);
        ene->draw(&painter);

    }
    foreach (Bullet* mybullet,bulltelist) {
       mybullet->setParent(this);
       mybullet->draw(&painter);
    }


}
void chapter::updatewhole(){
    foreach(tower1* tow,towerlist)
    {
        tow->get_target(enemylist);
        tow->attack();
    }

    foreach(enemy* ene,enemylist)
    {
        if(iftouch(ene->nowposition(),p3,0)||(!ene->ifalive()))
            enemylist.removeOne(ene);
        else {
            if(iftouch(ene->nowposition(),ene->endposition(),0))
            ene->trans(p3);
            ene->move();
        }


    }
    repaint();
}
