#include "Pos.h"
#include <QPainter>
#include<QPixmap>
#include <QMouseEvent>
Pos::Pos(QPoint p1):Button(":/picture/BASE.png"),P(p1),appa(":/picture/BASE.png"){
    appa = appa.scaled(appa.width()/1.5,appa.height()/1.5,Qt::KeepAspectRatio);
    setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction* set_tower1=new QAction(this);
    QAction* set_tower2=new QAction(this);
    QAction* delet=new QAction(this);
    set_tower1->setText("放置杰尼龟(-100 c)");
    set_tower2->setText("放置小火龙(-150 c)");
    delet->setText("拆除塔(+50 c)");
    delet->setEnabled(false);
    connect(set_tower1, &QAction::triggered, this, [ = ] {
        delet->setEnabled(true);
        set_tower1->setEnabled(false);
        set_tower2->setEnabled(false);
        emit choos_tower1();//放塔1并激活删除选项
            });
    connect(set_tower2, &QAction::triggered, this, [ = ] {
        delet->setEnabled(true);
        set_tower1->setEnabled(false);
        set_tower2->setEnabled(false);
        emit choos_tower2();//放塔2并激活删除选项
            });
    connect(delet, &QAction::triggered, this, [ = ] {
        set_tower1->setEnabled(true);
        set_tower2->setEnabled(true);
        emit choose_delet();//删除塔并激活放塔选项
            });
    addAction(set_tower1);
    addAction(set_tower2);
    addAction(delet);
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


