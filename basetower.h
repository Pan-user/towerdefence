#ifndef BASETOWER_H
#define BASETOWER_H

#include <QObject>
#include<QPoint>
#include<QPixmap>
#include"pos.h"
#include"chapter.h"
#include"test.h"
class basetower : public QObject
{
    Q_OBJECT
public:
    basetower(QPoint p1,QString p2, chapter *game);
    //用点、界面和路径初始化塔的位置和外貌
    void draw(QPainter*painter) const;
    QPoint getp();
    void attack();
private:
    QPoint position;
    QPoint center;
    QPixmap apparence;
    int attackrange;
    int damage;
    int speed;
    bool fire;
    chapter* thispage;
signals:


};

#endif // BASETOWER_H
