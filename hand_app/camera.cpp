#include "camera.h"
#include "ui_camera.h"
#include <QTimer>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>


Camera::Camera(QWidget *parent) : QWidget(parent), ui(new Ui::Camera)
{
    ui->setupUi(this);
    webcam = new Webcam();
    ui->camera_label->setScaledContents(true);
    analyze = false;
}

void Camera::displayCamera() {
    //Display of the camera
    ui->camera_label->setPixmap(QPixmap::fromImage(webcam->run()));
}

Camera::~Camera()
{
    delete ui;
    delete webcam;
}

void Camera::on_analyze_button_clicked()
{
    analyze = true;
    if(analyze)
        webcam->analyze_hand();
}

Webcam* Camera::getWebcam() {
    return webcam;
}
