#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "enemy.h"
#include<cmath>
#include"test.h"
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
private slots:

private:
    const QPoint	_start;
    QPoint	_end;
    const QPixmap   appa;
    QPoint			now;
    int				_damage;
    enemy* _target;


signals:

};

#endif // BULLET_H
