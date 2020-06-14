#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QPoint>
#include<Qpixmap>
#include <QPainter>
#include"test.h"
#include"chapter.h"
class enemy : public QObject
{
    Q_OBJECT
public:
    enemy(QPoint st,QPoint en,QString path,chapter* game);
    void draw(QPainter*painter) const;
    void move();
    void trans(QPoint target);
    QPoint nowposition();
    QPoint endposition();
    bool ifarrive(const QPoint p);
private:
    QPoint start;
    QPoint end;
    QPoint now;
    const QPixmap appa;
    int maxHP;
    int nowHP;
    //bool live;//是否活着
    test enetest;//用于检测路标，攻击范围和是否进入基地
    chapter* thispage;
signals:

};

#endif // ENEMY_H
