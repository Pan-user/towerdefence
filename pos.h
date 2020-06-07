#ifndef POS_H
#define POS_H
#include<QPoint>
#include<QPixmap>
#include <QPainter>
#include <QList>
#include <button.h>
#include <QMouseEvent>
class Pos:public Button{

public:
    Pos(QPoint p1); //用坐标初始化位置
    bool getif() const;//用于外界判断是否有塔
    void change();//用于放塔拆塔时改变状态
    void draw(QPainter *painter) const;
    int px();
    int py();

private:
    QPoint	P;	//坐标
    bool  ifhas;//是否有塔
    QPixmap appa;
};
#endif // POS_H
