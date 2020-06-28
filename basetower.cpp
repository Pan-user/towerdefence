#include "basetower.h"
basetower::basetower(QPoint p1,QString p2):QObject(0),position(p1),apparence(p2),center(p1.x()+apparence.size().width()*1.2/2,p1.y()+apparence.size().height()*1.2/2){

}

QPoint basetower::getp(){return position;}
QPoint basetower::getcenter(){return center;}
bool basetower::iffire(){

         return fire;
 }
int basetower::get_cost(){return cost;}


