#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QWidget>

class endwindow : public QWidget
{
    Q_OBJECT
public:
    explicit endwindow(QWidget *parent = nullptr);
    void set(bool);
private:
    bool status;

signals:

};

#endif // ENDWINDOW_H
