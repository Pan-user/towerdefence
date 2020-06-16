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
protected:
    QPoint position;
    QPoint center;
    QPixmap apparence;
    int attackrange;
    int damage;
signals:


};

#endif // BASETOWER_H
