#include "Pos.h"
#include <QPainter>
#include<QPixmap>
#include <QMouseEvent>
Pos::Pos(QPoint p1):Button(":/picture/BASE.png"),P(p1),appa(":/picture/BASE.png"){
    appa = appa.scaled(appa.width()/1.5,appa.height()/1.5,Qt::KeepAspectRatio);
    setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction* set_tower1=new QAction(this);
    QAction* set_tower2=new QAction(this);
    QAction* update=new QAction(this);
    QAction* delet=new QAction(this);
    set_tower1->setText("放置杰尼龟(-100 c)");
    set_tower2->setText("放置小火龙(-150 c)");
    update->setText("升级(-200 c)");
    delet->setText("拆除塔(+50 c)");
    delet->setEnabled(false);
    update->setEnabled(false);
    connect(set_tower1, &QAction::triggered, this, [ = ] {
        emit choos_tower1();//放塔1
            });
    connect(set_tower2, &QAction::triggered, this, [ = ] {

        emit choos_tower2();//放塔2
            });
    connect(delet, &QAction::triggered, this, [ = ] {

        emit choose_delet();//删除塔
            });
    connect(update, &QAction::triggered, this, [ = ] {
        emit choose_up();//升级
            });
    addAction(set_tower1);
    addAction(set_tower2);
    addAction(update);
    addAction(delet);
    myOption.push_back(set_tower1);
    myOption.push_back(set_tower2);
    myOption.push_back(update);
    myOption.push_back(delet);
    }

void Pos::set(){
    myOption[0]->setEnabled(false);
    myOption[1]->setEnabled(false);
    myOption[2]->setEnabled(true);
    myOption[3]->setEnabled(true);


}
void Pos::delet(){
    myOption[0]->setEnabled(true);
    myOption[1]->setEnabled(true);
    myOption[2]->setEnabled(false);
    myOption[3]->setEnabled(false);


}
void Pos::up(){
    myOption[2]->setEnabled(false);
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


