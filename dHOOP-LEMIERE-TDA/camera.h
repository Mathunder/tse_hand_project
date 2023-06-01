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

/*
 * This class handles the display of the webcam.
 *
 * @author : Matthieu d'Hoop
 */
class Camera : public QWidget
{
    Q_OBJECT
public:
    // Constructor
    explicit Camera(QWidget *parent = nullptr);
    // Display the image captionned by the webcam in the camera_label
    void displayCamera();
    // Returns the instance of the Webcam that is being used by the Camera
    Webcam* getWebcam();
    // Destructor
    ~Camera();

private:
    Ui::Camera *ui;
    Webcam *webcam;
    bool analyze;
    unsigned int nb_threads = std::thread::hardware_concurrency();

};

#endif // CAMERA_H
