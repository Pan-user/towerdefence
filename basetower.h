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
    virtual void draw(QPainter*painter) const;
    QPoint getp();
    QPoint getcenter();
    bool iffire();//检测是否能开火
    virtual void get_target(QList<enemy*> target);
    int get_cost();//外界得知价格的接口
    virtual void attack();//利用虚函数动态绑定，塔的攻击和锁定目标的实现在具体的子类中进行
protected:
    QPoint position;
    QPoint center;
    QPixmap apparence;
    int cost;
    int attackrange;
    int damage;
    int movespeed;
    int firespeed;
    bool fire;//是否处于开火状态
signals:


};

#endif // BASETOWER_H
