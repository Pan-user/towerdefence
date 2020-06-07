#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include<QPushButton>
#include<list.h>
#include "Pos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   void paintEvent(QPaintEvent *);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
