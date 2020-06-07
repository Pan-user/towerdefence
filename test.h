#ifndef TEST_H
#define TEST_H
#include<QPoint>
#include<cmath>
class test
{
public:
    inline bool iftouch(QPoint p1, QPoint p2,int range)
    {	int ifx = p1.x() - p2.x();
        int ify = p1.y() - p2.y();
        int distance = sqrt(ifx * ifx + ify * ify);
        if (distance <= range)
            return true;
        else
            return false;
    }

};

#endif // TEST_H
