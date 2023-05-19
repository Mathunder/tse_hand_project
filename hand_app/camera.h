#ifndef CAMERA_H
#define CAMERA_H

#include "webcam.h"
#include <QWidget>


namespace Ui {
class Camera;
}

class Camera
{
protected:
    void displayCamera();

public:
    Camera();

private:
    Ui::Camera *ui;
    int argc;
    char **argv;
    Webcam *webcam = new Webcam(argc, argv);
};

#endif // CAMERA_H
