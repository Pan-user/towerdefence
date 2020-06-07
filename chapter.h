#ifndef CHAPTER1_H
#define CHAPTER1_H

#include <QWidget>
#include"basetower.h"
#include <QPaintEvent>
#include "Pos.h"
#include<QList>
#include <Qtimer>
#include"basetower.h"
#include"enemy.h"
class chapter : public QWidget
{
    Q_OBJECT
public:
    explicit chapter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void load();

private:
    QList<Pos*> poslist;
    QList<basetower*> towerlist;
    QList<enemy*> enemylist;
    /*QList <QPoint*> waypoint;*/
    QPoint p1,p2,p3;
    QPoint* mark;

private slots:
    void updatewhole();
    void set(Pos* p);
    void loadwave();
signals:

};

#endif // CHAPTER1_H
