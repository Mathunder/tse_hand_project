#include "scene.h"
#include "ui_scene.h"
#include "hand.h"
#include "webcam.h"

Scene::Scene(QWidget *parent) : QOpenGLWidget(parent),
    ui(new Ui::Scene)
{
    ui->setupUi(this);

    webcam = new Webcam();
    hand = new Hand();
    wall = new Wall();
}

void Scene::initializeGL() {
    glClearColor(0.9f, 0.9f, 0.9f, 0.0f);

    glEnable(GL_DEPTH_TEST);

    // Définition de la matrice de projection pour définir la perspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0f, 511.0f/271.0f, 2.0f, 50.0f);

    // Définition de la matrice de modélisation-visualisation pour définir la camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-10.0f, 15.0f, 20.0f, 0.f, 5.f, 0.f, 0.f, 1.f, 0.f);

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Scene::resizeGL(int width, int height) {

}

void Scene::paintGL() {
    hand->drawBase();
    hand->drawThumb(webcam->finger[0]);
    hand->drawIndex(webcam->finger[1]);
    hand->drawMiddleFinger(webcam->finger[2]);
    hand->drawRingFinger(webcam->finger[3]);
    hand->drawLittleFinger(webcam->finger[4]);
//    hand->rotate();
    wall->drawWallBase();
    wall->drawWallThumb(false);
    wall->drawWallIndex(false);
    wall->drawWallMiddleFinger(false, false, false);
    wall->drawWallRingFinger(false);
    wall->drawWallLittleFinger(false, false);
    wall->translate();
}

void Scene::setWebcam(Webcam *webcam) {
    this->webcam = webcam;
}

Scene::~Scene()
{
    delete ui;
    delete webcam;
    delete hand;
    delete wall;
}
