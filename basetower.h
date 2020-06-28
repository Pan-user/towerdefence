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
    virtual void draw(QPainter*painter) const=0;
    QPoint getp();
    QPoint getcenter();
    bool iffire();//检测是否能开火
    int get_cost();//外界得知价格的接口
    virtual void get_target(QList<enemy*> target)=0;
    virtual void attack()=0;//纯虚函数，塔的攻击和锁定目标的实现在具体的子类中
    virtual void update()=0;//纯虚函数，塔的升级在具体子类中进行
protected:
    const QPoint position;
     QPixmap apparence;
     QPoint center;

    int cost;
    int attackrange;
    int damage;
    int movespeed;
    int firespeed;
    bool fire;//是否处于开火状态
signals:


};

#endif // BASETOWER_H
