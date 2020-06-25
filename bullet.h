#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "enemy.h"
#include<cmath>
#include"test.h"
#include<QPixmap>
class Bullet : public QObject
{
    Q_OBJECT
public:
    Bullet(QPoint start, QPoint end, int damage,
           QString path,enemy* target);

    void draw(QPainter *painter) const;
    void move();
    void setCurrentPos(QPoint pos);
    QPoint currentPos() const;
    bool ifhit();
private:
    const QPoint	_start;
    QPoint	_end;
    QPixmap appa;
    QPoint	now;
    int		_damage;
    enemy*  _target;
    bool    hit;


signals:

};

#endif // BULLET_H
