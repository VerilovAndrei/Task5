#include "mainwindow.h"
#include <QApplication>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.SetGraphProperty(20,new double[20]{10,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,5,2,3,4.444}); //принимает размер массива и сам массив
    w.show();
    return a.exec();
}




