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
class chapter : public QWidget
{
    Q_OBJECT
public:
    explicit chapter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void load();//加载位置
    QList<enemy*> getenemy() const{return enemylist;};

private:
    QList<Pos*> poslist;
    QList<basetower*> towerlist;//用基类容器存储不同的塔
    QList<enemy*> enemylist;//存储敌人
    QPoint p1,p2,p3;
    QPoint* mark;
    int maxhomeHP;
    int nowhomeHP;
private slots:
    void updatewhole();
    void delet(Pos* p);
    void set_tower1(Pos* p);
    void loadwave();
signals:

};

#endif // CHAPTER1_H
