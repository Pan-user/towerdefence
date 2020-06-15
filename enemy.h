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
    bool ifarrive(const QPoint p);
    void hitted(int);
    bool ifalive();
private:
    QPoint start;
    QPoint end;
    QPoint now;
    const QPixmap appa;
    int maxHP;
    int nowHP;
    bool live;
signals:

};

#endif // ENEMY_H
