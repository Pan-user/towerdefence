#ifndef TOWER2_H
#define TOWER2_H

#include <QObject>
#include"basetower.h"
class tower2 : public basetower
{
    Q_OBJECT
public:
    tower2(QPoint p1,QString p2);
    void get_target(QList<enemy*> target);
    void attack();
    void draw(QPainter*painter) const;
private:
    QList<enemy*> mytarget;//群攻复数个目标
    void timerEvent(QTimerEvent *event);
signals:

};

#endif // TOWER2_H
