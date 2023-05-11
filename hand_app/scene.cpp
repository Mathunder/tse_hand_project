#include "scene.h"
#include "ui_scene.h"
#include "finger.h"

Scene::Scene(QWidget *parent) : QOpenGLWidget(parent),
    ui(new Ui::Scene)
{
    ui->setupUi(this);
}

void Scene::initializeGL() {

}

void Scene::resizeGL(int width, int height) {

}

void Scene::paintGL() {
    Finger *index = new Finger();
    index->drawFinger();
}

Scene::~Scene()
{
    delete ui;
}
