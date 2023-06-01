#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->restart_button->setVisible(false);
    ui->label_final_score_title->setVisible(false);
    ui->label_final_score->setVisible(false);
    ui->label_lost->setVisible(false);
    QFont font;
    font.setFamily("MS Sans Serif");
    font.setPointSize(50);
    ui->label_lost->setFont(font);
    timer = new QTimer(this);
    score = 0;

    connect(timer, SIGNAL(timeout()), this, SLOT(update_scene()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update_camera()));
//    timer->start(16); // 60fps

    connect(ui->scene_widget, SIGNAL(collisionOccured()), this, SLOT(update_game_over()));
    connect(ui->scene_widget, SIGNAL(wallPassed()), this, SLOT(update_points()));
    connect(ui->scene_widget, SIGNAL(analyze()), this, SLOT(analyze()));

    start = false;
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

void MainWindow::analyze() {
    ui->camera_widget->getWebcam()->analyze_hand();
}

void MainWindow::update_game_over() {
    ui->label_lost->setVisible(true);
    ui->camera_widget->hide();
    ui->label_final_score_title->setVisible(true);
    ui->label_final_score->setText(QString::number(score));
    ui->label_final_score->setVisible(true);
    ui->restart_button->setVisible(true);
    ui->start_button->hide();
    timer->stop();
}

void MainWindow::update_points() {
    score++;
    ui->label_points->setText(QString::number(score));
}

void MainWindow::on_restart_button_clicked()
{
    score = 0;
    ui->label_points->setText(QString::number(score));
    ui->camera_widget->setVisible(true);
    ui->label_lost->setVisible(false);
    ui->label_final_score->setVisible(false);
    ui->label_final_score->setVisible(false);
    ui->label_final_score_title->setVisible(false);
    ui->restart_button->hide();
    ui->start_button->setVisible(true);
    timer->start();

}

void MainWindow::on_start_button_clicked()
{
    if(!start) {
        timer->start(16);
        ui->start_button->setText(QString("Stop"));
        start = true;
    } else {
        timer->stop();
        ui->start_button->setText(QString("Start"));
        start = false;
    }
}

