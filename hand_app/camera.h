#ifndef CAMERA_H
#define CAMERA_H

#include "webcam.h"
#include <QWidget>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class Camera; }
QT_END_NAMESPACE

class Camera : public QWidget
{
    Q_OBJECT
public:
    explicit Camera(QWidget *parent = nullptr);
    void displayCamera();
    ~Camera();

private:
    Ui::Camera *ui;
    Webcam *webcam;
    bool analyze = false;
//    cv::VideoCapture *window;
//    cv::Mat frame;
//    QImage img;
};

#endif // CAMERA_H
