#ifndef POS_H
#define POS_H
#include<QPoint>
#include<QPixmap>
#include <QPainter>
#include <QList>
#include <button.h>
#include <QMouseEvent>
#include<QAction>
class Pos:public Button{
    Q_OBJECT
public:
    Pos(QPoint p1); //用坐标初始化位置
    void draw(QPainter *painter) const;
    int px();
    int py();

private:
    QPoint	P;	//坐标
    QPixmap appa;
signals:
    void choos_tower1();
    void choos_tower2();
    void choose_delet();
};
#endif // POS_H
