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
    one_by_one = true;
    has_been_analyzed = false;
    compteur = .0f;
}

void Scene::initializeGL() {
    glClearColor(0.9f, 0.9f, 0.9f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    // Activation de l'éclairage
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Déclaration position, direction et couleur de la lumière (directionnelle)
    GLfloat lightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
//    GLfloat colorAmbiante[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Blanc ambiant
//    glLightfv(GL_LIGHT0, GL_AMBIENT, colorAmbiante);
    GLfloat colorDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Blanc diffus
    glLightfv(GL_LIGHT0, GL_DIFFUSE, colorDiffuse);

    // Définition de la matrice de projection pour définir la perspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0f, 511.0f/271.0f, 2.0f, 300.0f);

    // Définition de la matrice de modélisation-visualisation pour définir la camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-12.0f, 25.0f, 20.0f, 0.f, 10.f, 0.f, 0.f, 1.f, 0.f);
    glPushMatrix();

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

//void Scene::resizeGL(int width, int height) {

//}

void Scene::paintGL() {
    glPopMatrix();
    hand->drawBase();
    hand->drawThumb(webcam->finger[0]);
    hand->drawIndex(webcam->finger[1]);
    hand->drawMiddleFinger(webcam->finger[2]);
    hand->drawRingFinger(webcam->finger[3]);
    hand->drawLittleFinger(webcam->finger[4]);
    glPopMatrix();

    if(wall->getPosition() > 30.f) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 7);
        temp = dis(gen);
        for(int i=0; i < 5; i++)
            this->wall_finger[i] = !(wall->configuration[temp][i]);
        wall->setPosition(-150.f);
        one_by_one = true;
        has_been_analyzed = false;
    }

    if((wall->getPosition() > -120.f) && (wall->getPosition() < -50.f)) {
        GLfloat green[3] = {.0f + compteur, 1.f, .0f};
        hand->setColor(green);
        compteur += .05f;
        if(wall->getPosition() > -53.f && !has_been_analyzed) {
            has_been_analyzed = true;
            compteur = .0f;
            emit analyze();
        }
    } else {
        GLfloat grey[3] = {.7f, .7f, .7f};
        hand->setColor(grey);
    }

    wall->setPosition(wall->getPosition() + 2.f);
    wall->drawWallBase();
    wall->drawWallThumb(this->wall_finger[0]);
    wall->drawWallIndex(this->wall_finger[1]);
    wall->drawWallMiddleFinger(this->wall_finger[2], this->wall_finger[1], this->wall_finger[3]);
    wall->drawWallRingFinger(this->wall_finger[3]);
    wall->drawWallLittleFinger(this->wall_finger[4], this->wall_finger[3]);

    //Checking if there is a collision
    if(wall->getPosition() > -3.f && wall->getPosition() < 2.f && one_by_one) {
        bool collision = false;
        for(int i=0; i < 5; i++) {
            if(this->wall_finger[i] == webcam->finger[i]) {
                collision = true;
                break;
            }
        }
        if(collision) {
            emit collisionOccured();
        } else {
            emit wallPassed();
        }
        one_by_one = false;
    }
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
