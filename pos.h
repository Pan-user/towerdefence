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
    void set();//放塔操作对应的菜单选项改变
    void delet();//拆塔操作对应的菜单选项改变
    void up();//升级对应的菜单选项改变
private:
    QPoint	P;	//坐标
    QPixmap appa;
    QList<QAction*> myOption;//操作菜单的选项
signals:
    void choos_tower1();
    void choos_tower2();
    void choose_delet();
    void choose_up();
};
#endif // POS_H
