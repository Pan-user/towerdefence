#ifndef BUTTON_H
#define BUTTON_H
#include<Qpixmap>
#include <QWidget>
#include<QPushButton>
#include <QMouseEvent>
class Button : public QPushButton
{
    Q_OBJECT
public:
   Button(QString m);
   /*void mouseReleaseEvent(QMouseEvent *e);*/
private:


signals:

};

#endif // BUTTON_H
