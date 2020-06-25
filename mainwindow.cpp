#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"chapter.h"
#include <QPainter>
#include <QPaintEvent>
#include<Qpixmap>
#include<button.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   this->setFixedSize(1200,800);
    ui->setupUi(this);
    setWindowTitle("塔防");
    Button *Start=new Button(":/picture/start.png");
    Start->setParent(this);
    Start->move(500,400);
    connect(Start,&QPushButton::clicked,this,[=](){
        chapter* chapter1=new chapter;
        this->close();
        chapter1->show();
    });
}
void MainWindow::paintEvent(QPaintEvent *)

{

    QPainter painter(this);
    QPixmap preview(":/picture/preview.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),preview);


}
MainWindow::~MainWindow()
{
    delete ui;
}


