#ifndef TOWER1_H
#define TOWER1_H

#include <QObject>
#include"basetower.h"
#include"bullet.h"
class tower1 : public basetower
{
    Q_OBJECT
public:
    tower1(QPoint p1,QString p2);
    void get_target(QList<enemy*> target);
    void attack();
    bool iffire();
    void opentower();
     void draw(QPainter*painter) const;
private:
    QList<Bullet*> mybullet;
    enemy* mytarget;
    int movespeed;
    int firespeed;
    bool fire;
    void towerupdate();
signals:
    void timerEvent(QTimerEvent *event);
};

#endif // TOWER1_H
