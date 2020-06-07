#include "Pos.h"
#include <QPainter>
#include<QPixmap>
#include <QMouseEvent>
Pos::Pos(QPoint p1):Button(":/picture/BASE.png"),P(p1),appa(":/picture/BASE.png"){
    appa = appa.scaled(appa.width()/1.5,appa.height()/1.5,Qt::KeepAspectRatio);
    ifhas=false;}
 bool Pos:: getif() const{
    return ifhas;
}
void Pos::change() {
    if(ifhas)
    ifhas=false;
    else
    ifhas=true;
}

void Pos::draw(QPainter *painter) const
{

    painter->drawPixmap(P.x(), P.y(), appa);
}
int Pos::px(){
    return P.x();
}
int Pos::py(){
    return P.y();
}


