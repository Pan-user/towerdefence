#ifndef CHAPTER1_H
#define CHAPTER1_H

#include <QWidget>
#include <QPaintEvent>
#include "Pos.h"
#include<QList>
#include <Qtimer>
#include"basetower.h"
#include"enemy.h"
#include"bullet.h"
#include"tower1.h"
#include"tower2.h"
#include"enemy_plus.h"
#include<QLabel>
#include"endwindow.h"
#include<QMediaPlayer>
#include<QMediaPlaylist>
class chapter : public QWidget
{
    Q_OBJECT
public:
    explicit chapter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void load();//加载位置
    QList<enemy*> getenemy() const{return enemylist;};
    void loadGoldbar();
private:
    QList<Pos*> poslist;
    QList<basetower*> towerlist;//用基类容器存储不同的塔
    QList<enemy*> enemylist;//存储敌人
    QPoint p1,p2,p3;
    int maxhomeHP;
    int nowhomeHP;
    static int waves;//静态成员变量，波数
    static int gold;//静态成员变量，金币
    QLabel* noMoney;
    QTimer *timer1;
    QTimer *timer2;
    QMediaPlayer* bgmplayer;
private slots:
    void updatewhole();
    void delet(Pos* p);
    void set_tower(Pos* p,int type);//p为放塔的位置，type为放什么类型的塔
    void upDate(Pos*p);
    void loadwave();
    void loadenemy1();
    void loadenemy2();
    void alertVanish();
signals:

};

#endif // CHAPTER1_H
