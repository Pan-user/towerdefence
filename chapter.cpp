#include "chapter.h"
#include <QPaintEvent>
#include <QPainter>
#include <basetower.h>
#include "enemy.h"
#include"pos.h"
#include<QTimer>
#include "test.h"
#include<QLabel>
int chapter:: waves=1;int chapter::gold=300;static QLabel* goldbar;
chapter::chapter(QWidget *parent) : QWidget(parent),p1(400,600),p2(980,600),p3(980,100),nowhomeHP(1000),maxhomeHP(1000)
{

    this->setFixedSize(1200,800);
    setWindowTitle("第一关");
    goldbar=new QLabel(this);
    goldbar->setText("当前金币数: "+QString::number(gold));
    goldbar->setFont(QFont("Microsoft YaHei", 20, QFont::Bold));
    goldbar->setStyleSheet("color:yellow;");
    goldbar->move(450,150);
    goldbar->show();
    load();
    loadwave();
    foreach(Pos* position,poslist)
    {
        position->setParent(this);
        position->move(position->px(),position->py());
        connect(position, &Pos::choos_tower1, this, [ = ] {
            set_tower(position,1);
                });//放置塔1
        connect(position, &Pos::choos_tower2, this, [ = ] {
            set_tower(position,2);
                });//放置塔2
        connect(position, &Pos::choose_delet, this, [ = ] {
            delet(position);
                });//删除塔
    }
    QTimer *timer1 = new QTimer(this);
    QTimer *timer2 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(updatewhole()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(loadwave()));
    timer2->start(10000);
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

            }

    }
void chapter::loadGoldbar(){
    goldbar->clear();
    goldbar->setText("当前金币数: "+QString::number(gold));
    goldbar->move(450,150);
    goldbar->show();
}
void chapter::loadenemy(){
    enemy_plus* enemy1=new enemy_plus(p1,p2,":/picture/monster2.png");
    enemylist.push_back(enemy1);

}
void chapter::loadwave(){
    int i=1;
    for(i=1;i<=waves;i++)
    {

        QTimer::singleShot(i*1000,this,SLOT(loadenemy()));

    }
    waves+=1;

}

void chapter::set_tower(Pos* p,int type){
    basetower* tower;
    if(type==1)
        tower=new tower1(QPoint(p->px()+20,p->py()+20),":/picture/tower1.png");
    else
        tower=new tower2(QPoint(p->px()+20,p->py()+20),":/picture/tower2.png");
//判断是什么类型的塔
    if (gold>=tower->get_cost())
    {
        towerlist.push_back(tower);
        gold-=tower->get_cost();//扣除金币
        p->set();//改变塔基菜单选项的状态
        loadGoldbar();//改变金币显示

    }


}//放塔1
void chapter::delet(Pos* p){
        foreach(basetower* tow,towerlist)
         if(tow->getp()==QPoint(p->px(),p->py()))
             towerlist.removeOne(tow);
        gold+=50;
        p->delet();

}
void chapter::paintEvent(QPaintEvent *)

{


    QPainter painter(this);
    QPixmap preview(":/picture/map.png");
    painter.drawPixmap(0,0,this->width(),this->height(),preview);
    foreach(basetower* tow,towerlist)
    {

        tow->draw(&painter);

    }
    foreach(enemy* ene,enemylist)
    {
        ene->setParent(this);
        ene->draw(&painter);

    }
    painter.save();
    QPoint barPoint = p3;	// 绘制基地血条,同enemy
    painter.setBrush(Qt::red);
    QRect healthBar1(barPoint, QSize(100, 10));
    painter.drawRect(healthBar1);
    painter.setBrush(Qt::green);
    QRect healthBar2(barPoint, QSize((double)nowhomeHP / maxhomeHP * 100, 10));
    painter.drawRect(healthBar2);
    painter.restore();


}
void chapter::updatewhole(){


    foreach(basetower* tow,towerlist)
    {
        tow->get_target(enemylist);
    }
    foreach(enemy* ene,enemylist)
    {
        if(!ene->ifalive())
        {
            enemylist.removeOne(ene);
            gold+=100;
            loadGoldbar();
            update();
        }
        else if(iftouch(ene->nowposition(),p3,0))
        {
            nowhomeHP-=ene->arrive();
            enemylist.removeOne(ene);

        }
        else {
            if(iftouch(ene->nowposition(),ene->endposition(),2))
            ene->trans(p3);
            ene->move();
        }


    }

    repaint();
}
