#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>

class Shape
{
public:
    virtual void draw(QGraphicsScene*ex)=0;
    virtual void move()=0;
    virtual void rotation()=0;
};

class Circle : public Shape
{
public:
    void draw(QGraphicsScene*c);
    void move();
    void rotation();
    QGraphicsScene*scene;
    QGraphicsEllipseItem*one;
};

class Triangle : public Shape
{
public:
    void draw(QGraphicsScene*t);
    void move();
    void rotation();
    QGraphicsScene*scene;
    QGraphicsPolygonItem*semo;
};

class Rect : public Shape
{
public:
    void draw(QGraphicsScene*r);
    void move();
    void rotation();
    QGraphicsScene*scene;
    QGraphicsRectItem*nemo;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Triangle*extriangle;
    Circle*excircle;
    Rect*exrect;
    int rotation_angle=0;
    QGraphicsItem*getSelectedItem();

private slots:
    void on_dial_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene*scene;
};
#endif // MAINWINDOW_H


