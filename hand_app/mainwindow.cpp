#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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
    delete timer;
}

void MainWindow::update_scene()
{
    future_scene = QtConcurrent::run([this]() {
        ui->scene_widget->update();
        ui->scene_widget->setWebcam(ui->camera_widget->getWebcam());
    });
}

void MainWindow::update_camera()
{
    ui->camera_widget->displayCamera();
}
