#ifndef BASETOWER_H
#define BASETOWER_H

#include <QObject>
#include<QPoint>
#include<QPixmap>
#include"pos.h"
class basetower : public QObject
{
    Q_OBJECT
public:
    basetower(QPoint p1,QString p2);
    //用点和路径初始化塔的位置和外貌
    void draw(QPainter*painter) const;
    QPoint getp();
private:
    QPoint position;
    QPixmap apparence;
signals:


};

#endif // BASETOWER_H
