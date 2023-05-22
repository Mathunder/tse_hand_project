#ifndef CAMERA_H
#define CAMERA_H

#include "webcam.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Camera; }
QT_END_NAMESPACE

class Camera : public QWidget
{
    Q_OBJECT
protected:
    void displayCamera();

public:
    explicit Camera(QWidget *parent = nullptr);
    ~Camera();

private:
    Ui::Camera *ui;
    int argc;
    char **argv;
    Webcam *webcam = new Webcam(argc, argv);
};

#endif // CAMERA_H
