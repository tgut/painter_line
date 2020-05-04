#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int p, t;   //p represent the x coordinate of the start point of painting, t represent the  x coordinate of time
    QTimer *timer;
    QPoint *point;
    QPainterPath *path;
    void virtual paintEvent(QPaintEvent *);     //paintEvent method, need to be reimplemented

private slots:
    void timerUpdate();      //slot method for the timer signal timeout()
    void startPainting();    //slot method for start button signal click()
    void stopPainting();     //slot method for stop button signal clicked()
};

#endif // MAINWINDOW_H
