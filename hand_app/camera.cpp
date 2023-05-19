#include "camera.h"

Camera::Camera() {

}

void Camera::displayCamera() {

    Webcam::getInstance(argc, argv)->webcamThreads.push_back(std::thread(&Webcam::analyze_hand, Webcam::getInstance(argc, argv)));

    for (int i=0; i < Webcam::getInstance(argc, argv)->webcamThreads.size(); i++) {
        Webcam::getInstance(argc, argv)->webcamThreads[i].join();
    }
}
