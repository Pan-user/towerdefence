#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QPoint>
#include<Qpixmap>
#include <QPainter>
#include"test.h"
class enemy : public QObject//最基础的敌人
{
    Q_OBJECT
public:
    enemy(QPoint st,QPoint en,QString path);
    virtual void draw(QPainter*painter) ;
    virtual void move();
    virtual void hitted(int damage);
    void trans(QPoint target);
    QPoint nowposition() const;
    QPoint endposition() const;
    QPoint centerposition() const;
    bool ifalive() const;
    bool ifhurted() const;
    int arrive() const;
    void resethurt();

protected:
    QPoint start;
    QPoint end;
    QPoint now;
    QPoint center;
    QPixmap appa;
    int maxHP;
    int nowHP;
    bool live;
    const int damage;
    bool hurted;//为塔2设计，判断是否被攻击过
signals:

};

#endif // ENEMY_H
