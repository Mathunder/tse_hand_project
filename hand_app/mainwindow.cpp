#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->label_lost->setVisible(false);
    QFont font;
    font.setFamily("MS Sans Serif");
    font.setPointSize(50);
    ui->label_lost->setFont(font);
    timer = new QTimer(this);
    score = 0;

    connect(timer, SIGNAL(timeout()), this, SLOT(update_scene()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
    timer->start(16); // 60fps

    connect(ui->scene_widget, SIGNAL(collisionOccured()), this, SLOT(update_lost()));
    connect(ui->scene_widget, SIGNAL(wallPassed()), this, SLOT(update_points()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete timer;
}

void MainWindow::update_scene() {
    future_scene = QtConcurrent::run([this]() {
        ui->scene_widget->update();
        ui->scene_widget->setWebcam(ui->camera_widget->getWebcam());
    });
}

void MainWindow::update_camera() {
    ui->camera_widget->displayCamera();
}

void MainWindow::update_lost() {
    ui->label_lost->setVisible(true);
    ui->camera_widget->hide();
}

void MainWindow::update_points() {
    score++;
    ui->label_points->setText(QString::number(score));
}
