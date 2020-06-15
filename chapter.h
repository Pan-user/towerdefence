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

private:
    QList<Pos*> poslist;
    QList<tower1*> towerlist;
    QList<enemy*> enemylist;
    QList<Bullet*> bulltelist;
    QPoint p1,p2,p3;
    QPoint* mark;

private slots:
    void updatewhole();
    void set(Pos* p);
    void loadwave();
signals:

};

#endif // CHAPTER1_H
