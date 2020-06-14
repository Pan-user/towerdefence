#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "enemy.h"
#include<cmath>
class Bullet : public QObject
{
    Q_OBJECT
public:
    Bullet(QPoint start, QPoint end, int damage, enemy *target,
           QString path);

    void draw(QPainter *painter) const;
    void move();
    void setCurrentPos(QPoint pos);
    QPoint currentPos() const;

private slots:
    void hitTarget();

private:
    const QPoint	_start;
    const QPoint	_end;
    const QPixmap   appa;
    QPoint			now;
    enemy *			_target;
    int				_damage;



signals:

};

#endif // BULLET_H
