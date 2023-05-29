#ifndef CAMERA_H
#define CAMERA_H

#include "webcam.h"
#include <QWidget>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui {
class Camera;
}
QT_END_NAMESPACE

class Camera : public QWidget
{
    Q_OBJECT
public:
    explicit Camera(QWidget *parent = nullptr);
    void displayCamera();
    Webcam* getWebcam();
    ~Camera();

private:
    Ui::Camera *ui;
    Webcam *webcam;
    bool analyze;
    unsigned int nb_threads = std::thread::hardware_concurrency();

private slots:
    void on_analyze_button_clicked();
};

#endif // CAMERA_H
