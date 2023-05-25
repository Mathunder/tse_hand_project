#include "camera.h"
#include "ui_camera.h"
#include <QTimer>


Camera::Camera(QWidget *parent) : QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    webcam = new Webcam();
    ui->camera_label->setScaledContents(true);
//    ui->camera_label->setFixedSize();
}

void Camera::displayCamera() {
    //Display of the camera
    ui->camera_label->setPixmap(QPixmap::fromImage(webcam->toImg()));

    //Analyze the user's hand
    while(analyze) {
        webcam->getInstance()->webcamThreads.push_back(std::thread(webcam->analyze_hand, webcam->getInstance()));

        for (int i=0; i < webcam->getInstance()->webcamThreads.size(); i++) {
           webcam->getInstance()->webcamThreads[i].join();
        }
    }
}

Camera::~Camera()
{
    delete ui;
    delete webcam;
}
