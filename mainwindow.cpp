#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsPolygonItem>
#include <iostream>


QGraphicsItem *MainWindow::getSelectedItem()
{
    if(scene->selectedItems().count() > 0){
        return scene->selectedItems().at(0);
    }
    return  nullptr;

}

void Circle::draw(QGraphicsScene*c)
{
    scene=c;
    one=scene->addEllipse(-50,-50,100,100);
    one->setPen(Qt::NoPen);
    one->setFlag(QGraphicsItem::ItemIsSelectable);
    one->setBrush(QBrush(Qt::red));
}

void Rect::draw(QGraphicsScene*r)
{
    scene=r;
    nemo=scene->addRect(-50,-50,100,100);
    nemo->setPen(Qt::NoPen);
    nemo->setFlag(QGraphicsItem::ItemIsSelectable);
    nemo->setBrush(QBrush(Qt::blue));
}

void Triangle::draw(QGraphicsScene*t)
{
    scene=t;
    QPolygonF Tri;
    Tri.append(QPointF(-60,55));
    Tri.append(QPointF(0,-55));
    Tri.append(QPointF(60,55));
    semo=scene->addPolygon(Tri,QPen(Qt::NoPen),QBrush(Qt::green));
    semo->setFlag(QGraphicsItem::ItemIsSelectable);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    scene->addLine(-290,0,290,0,QPen(Qt::white));
    scene->addLine(0,-250,0,250,QPen(Qt::white));

    QGraphicsView*view=new QGraphicsView(this);
    view->setScene(scene);
    ui->verticalLayout->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Circle::move()
{

}

void Rect::move()
{

}

void Triangle::move()
{

}

void Circle::rotation()
{

}

void Rect::rotation()
{

}

void Triangle::rotation()
{

}


void MainWindow::on_dial_valueChanged(int arg1)
{
    QGraphicsItem * item = getSelectedItem();
    if(item){
            QTransform transform = item->transform();
            transform.rotate(arg1 - rotation_angle);
            item->setTransform(transform);
            rotation_angle=arg1;
        }
}


void MainWindow::on_pushButton_clicked() //Circle
{
    excircle=new Circle;
    excircle->draw(scene);
    QTransform transform=excircle->one->transform();
    excircle->one->setTransform(transform);

}


void MainWindow::on_pushButton_2_clicked() //Rect
{
    exrect=new Rect;
    exrect->draw(scene);
    QTransform transform=exrect->nemo->transform();
    exrect->nemo->setTransform(transform);
}


void MainWindow::on_pushButton_3_clicked() //Triangle
{
    extriangle=new Triangle;
    extriangle->draw(scene);
    QTransform transform=extriangle->semo->transform();
    extriangle->semo->setTransform(transform);
}


void MainWindow::on_pushButton_5_clicked()
{
    QGraphicsItem * item = getSelectedItem();
    if(item){
            QTransform transform = item->transform();
            transform.translate(0,-10);
            item->setTransform(transform);
        }
}


void MainWindow::on_pushButton_7_clicked()
{
    QGraphicsItem * item = getSelectedItem();
    if(item){
            QTransform transform = item->transform();
            transform.translate(0,10);
            item->setTransform(transform);
        }
}


void MainWindow::on_pushButton_6_clicked()
{
    QGraphicsItem * item = getSelectedItem();
    if(item){
            QTransform transform = item->transform();
            transform.translate(-10,0);
            item->setTransform(transform);
        }
}


void MainWindow::on_pushButton_8_clicked()
{
    QGraphicsItem * item = getSelectedItem();
    if(item){
            QTransform transform = item->transform();
            transform.translate(10,0);
            item->setTransform(transform);
        }
}

