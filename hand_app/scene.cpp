#include "scene.h"
#include "ui_scene.h"
#include "hand.h"

Scene::Scene(QWidget *parent) : QOpenGLWidget(parent),
    ui(new Ui::Scene)
{
    ui->setupUi(this);

//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
//    timer->start(1000); //60fps
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
    hand->drawThumb(true);
    hand->drawIndex(true);
    hand->drawMiddleFinger(true);
    hand->drawRingFinger(true);
    hand->drawLittleFinger(true);
}

Scene::~Scene()
{
    delete ui;
//    delete timer;
}

//void Scene::update() {
//    initializeGL();
//    paintGL();
//}
