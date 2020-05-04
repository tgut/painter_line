#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QPainterPath>
#include <QPainter>
#include <QTime>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,500);      //resize the main window
    p = t = 0;
    timer = new QTimer;
    path = new QPainterPath;
    point = new QPoint;
    connect(ui->startButton, SIGNAL(clicked()),this,SLOT(startPainting()));
    connect(ui->stopButton, SIGNAL(clicked()),this,SLOT(stopPainting()));
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete point;
    delete path;
}

void MainWindow::startPainting()
{
    timer->start(100);               //initiate the timer, with timeout interval 100ms
}

void MainWindow::stopPainting()
{
    timer->stop();                   //stop timer
}


//reimplemented virtual method paintEvent
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red)); //adjust the painter size and color
    QPoint originPoint(p,0);
    painter.translate(originPoint);  //adjust the origin point of the painting
    painter.drawPath(*path);  //painting
    QWidget::paintEvent(event);

}


//slot method, will be called when the timer is time out
void MainWindow::timerUpdate()
{
    t += 10;
    //create random number
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int rand=qrand()%this->height();
    //the next point of the painted line
    point->setX(t);
    point->setY(rand);
    path->lineTo(*point);

    //
    if(t > this->width())
    {
        p -= 10;
    }

    //in case update() method is called, the system will trigger paintEvent to repaint the window
    this->update();

}
