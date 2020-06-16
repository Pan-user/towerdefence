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
    void load();
    QList<enemy*> getenemy() const{return enemylist;};
    friend class tower1;
private:
    QList<Pos*> poslist;
    QList<tower1*> towerlist;
    QList<enemy*> enemylist;
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
