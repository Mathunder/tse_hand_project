
//#include "mainwindow.h"
//#include "ui_mainwindow.h"
//#include <thread>
//#include <QFuture>
//#include <QFutureWatcher>
//#include <QtConcurrent/QtConcurrent>



//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//    timer = new QTimer(this);

//    connect(timer, SIGNAL(timeout()), this, SLOT(update_scene()));
//    connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
//    timer->start(16); //60fps
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}

//void MainWindow::update_scene() {
//    ui->scene_widget->update();
//}

//void MainWindow::update_camera() {
//    ui->camera_widget->displayCamera();
//}
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_scene()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
    timer->start(16); // 60fps

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_scene()
{
    ui->scene_widget->update();
}

void MainWindow::update_camera()
{
    ui->camera_widget->displayCamera();
}
