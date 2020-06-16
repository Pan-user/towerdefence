#ifndef BASETOWER_H
#define BASETOWER_H

#include <QObject>
#include<QPoint>
#include<QPixmap>
#include"pos.h"
#include"test.h"
#include"bullet.h"
class basetower : public QObject
{
    Q_OBJECT
public:
    basetower(QPoint p1,QString p2);
    //用点和路径初始化塔的位置和外貌
    void draw(QPainter*painter) const;
    QPoint getp();
    QPoint getcenter();

    //virtual void attack(QList<Bullet*> blist);
    //virtual void get_target(QList<enemy*> target);
protected:
    QPoint position;
    QPoint center;
    QPixmap apparence;
    int attackrange;
    int damage;
    int speed;


signals:


};

#endif // BASETOWER_H
