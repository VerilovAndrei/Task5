#include "mainwindow.h"

#include <QApplication>


#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <Signal/include/signal.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Signal s1(10);

    w.SetGraphProperty(20,new double[20]{10,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,5,2,3,4.444});
    w.show();
    return a.exec();
}




