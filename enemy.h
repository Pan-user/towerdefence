#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QPoint>
#include<Qpixmap>
#include <QPainter>
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
private:
    QPoint start;
    QPoint end;
    QPoint now;
    QPixmap appa;
signals:

};

#endif // ENEMY_H
