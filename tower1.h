#ifndef TOWER1_H
#define TOWER1_H
#include"basetower.h"
#include"bullet.h"
#include"QTimer"
class tower1 : public basetower
{
    Q_OBJECT
public:
    tower1(QPoint p1,QString p2);
    void get_target(QList<enemy*> target);
    void attack();
    void draw(QPainter*painter) const;
private:
    QList<Bullet*> mybullet;
    enemy* mytarget;//只有一个目标
    void timerEvent(QTimerEvent *event);
signals:
};

#endif // TOWER1_H
