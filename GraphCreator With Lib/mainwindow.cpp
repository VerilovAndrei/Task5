#include "mainwindow.h"
//#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <math.h>
#include <iostream>

float a;
float b;
float c;
double cX;
double cY;
int keyPressed;

double* scaleArray = nullptr;
auto scaleArraySize = 0;

QPoint mousePoint = QPoint(1,1);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mousePoint = QPoint(this->width(),this->height());
    setMouseTracking(true);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
   this->setMouseTracking(true);
   mousePoint = event->pos();
   cX =  mousePoint.x() / ((double)this->width());
   cY =  mousePoint.y() / ((double)this->height());

   update();
}
void MainWindow::wheelEvent(QWheelEvent* event)
{
    if(event->delta() > 0 && keyPressed == Qt::Key_Shift)
        {
          a += 1 - cX;
          b += 1 - cY;
          c -= cX ;
        }
    else if(event->delta() < 0 && keyPressed == Qt::Key_Shift)
        {
          a -= 1 - cX;
          b -= 1 - cY;
          c += cX;
        }
    else if(event->delta() > 0 && keyPressed == Qt::Key_Control)
    {
        b += 1;
    }
    else if(event->delta() < 0 && keyPressed == Qt::Key_Control)
    {
        b -= 1;
    }
    else if(event->delta() > 0)
    {
        a += 1;
    }
    else if(event->delta() < 0)
    {
        a -= 1;
    }
    this->update();
}
void MainWindow::keyPressEvent(QKeyEvent* event)
{
    keyPressed = event->key();
    this->update();
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    keyPressed = Qt::Key_unknown;
    this->update();
}

void MainWindow::graph()
{
    if(scaleArray == nullptr)
    {
        scaleArray = new double[3]{0,1,2};
        scaleArraySize = 3;
    }

    if (a == 0)
        a = this->width() / 12;
    if (b == 0)
        b = 30;

    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    painter.drawLine(50,this->height() - 50,50,50);
    painter.drawLine(50,this->height() / 2,this->width()- 50,this->height()  /2);

    for(int i = 50 - a; i < this->width(); i += a)
    {
        auto jopa = i + c * 5;
        if (jopa < this->width() - 50)
        {
            auto y1 = this->height() / 2 + 5 ;
            auto y2 = this->height() / 2 - 5 ;
            if (jopa > 50){
              painter.drawLine(jopa,y1,jopa,y2);

            }
        }
    }

    for(int i = this->height() / 2 - b; i > 50; i -= b )
    {
        auto jopa = i ;
        painter.drawLine(45,jopa,55,jopa);

    }
    for(int i = this->height() / 2 + b; i < this->height(); i += b )
    {
       auto jopa = i ;
       painter.drawLine(45,jopa,55,jopa);

    }

    for(int i = 0; i < scaleArraySize;i++)
    {

        auto eWidth = 8;
        painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
        painter.drawEllipse(50 + i * a + c * 5 - eWidth/2,this->height() / 2 - scaleArray[i] * b   - eWidth/2,eWidth,eWidth);

        painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
        painter.drawText(35,this->height() / 2 - scaleArray[i] * b,QString::number(scaleArray[i]));

        painter.setPen(QPen(Qt::gray, 1, Qt::DotLine, Qt::FlatCap));
        painter.drawLine(50 + i * a + c * 5,this->height() / 2 - scaleArray[i] * b,35,this->height() / 2 - scaleArray[i] * b);

        painter.setPen(QPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap));
        painter.drawLine(50 + i * a + c * 5,this->height() / 2 - scaleArray[i] * b,50 + (i + 1) * a + c * 5,this->height() / 2 - scaleArray[i+1] * b);

        painter.setPen(QPen(Qt::gray, 1, Qt::DotLine, Qt::FlatCap));
        painter.drawLine(50 + i * a + c * 5,this->height() / 2 - scaleArray[i] * b,50 + i * a + c * 5,this->height() / 2);

        painter.setPen(QPen(Qt::darkMagenta, 1, Qt::SolidLine, Qt::FlatCap));
        if(i != 0) painter.drawText(50 + i * a + c * 5,this->height() / 2 +50,QString::number(i));
    }
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.drawEllipse(mousePoint,2,2);
}

void MainWindow::paintEvent(QPaintEvent*) {
    graph();
}

void MainWindow::SetGraphProperty(int size, double* array)
{
    scaleArraySize = size;
    scaleArray = array;
}
