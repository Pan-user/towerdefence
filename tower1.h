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
    void attack(QList<Bullet*> bullet);
    void get_target(QList<enemy*> target);
    bool fire();
private:
    Bullet* bullet1;
signals:

};

#endif // TOWER1_H
