#include "camera.h"
#include "ui_camera.h"
#include <QTimer>


Camera::Camera(QWidget *parent) : QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    webcam = new Webcam();

}

void Camera::displayCamera() {
    ui->camera_label->setPixmap(QPixmap::fromImage(webcam->toImg()));
//    QPixmap img = QPixmap::fromImage(webcam->open());
//    QPixmap resized_img = img.scaled(QSize(300, 200), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//    ui->camera_label->setPixmap(resized_img);
//    webcam->getInstance()->webcamThreads.push_back(std::thread(webcam->analyze_hand, webcam->getInstance()));

//    for (int i=0; i < webcam->getInstance()->webcamThreads.size(); i++) {
//       webcam->getInstance()->webcamThreads[i].join();
//    }
}

Camera::~Camera()
{
    delete ui;
    delete webcam;
}
