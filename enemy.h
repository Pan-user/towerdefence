#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QPoint>
#include<Qpixmap>
#include <QPainter>
#include"test.h"
class enemy : public QObject
{
    Q_OBJECT
public:
    enemy(QPoint st,QPoint en,QString path);
    void draw(QPainter*painter) const;
    void move();
    void trans(QPoint target);
    QPoint nowposition();
    QPoint endposition();
    QPoint centerposition();
    void hitted(int);
    bool ifalive();
    int arrive();
private:
    QPoint start;
    QPoint end;
    QPoint now;
    QPoint center;
    const QPixmap appa;
    int maxHP;
    int nowHP;
    bool live;
    int damage;
signals:

};

#endif // ENEMY_H
