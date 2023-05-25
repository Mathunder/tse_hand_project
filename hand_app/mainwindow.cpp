
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(16); //60fps

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update() {
    ui->scene_widget->update();
    ui->camera_widget->displayCamera();
}
