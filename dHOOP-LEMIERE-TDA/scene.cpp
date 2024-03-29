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
    mur = QImage(":/res/logo/mur.png").convertToFormat(QImage::Format_RGBA8888);
}

void Scene::initializeGL() {
    glClearColor(0.9f, 0.9f, 0.9f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Initializing light parameters
    GLfloat lightPosition[] = { .0f, 30.0f, 20.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    GLfloat colorDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Blanc diffus
    glLightfv(GL_LIGHT0, GL_DIFFUSE, colorDiffuse);

    // Initialization of projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0f, 511.0f/271.0f, 2.0f, 300.0f);

    // Initialization of camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-12.0f, 25.0f, 20.0f, 0.f, 10.f, 0.f, 0.f, 1.f, 0.f);
    glPushMatrix();

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Scene::paintGL() {
    // Drawing the hand
    glPopMatrix();
    hand->drawBase();
    hand->drawThumb(webcam->finger[0]);
    hand->drawIndex(webcam->finger[1]);
    hand->drawMiddleFinger(webcam->finger[2]);
    hand->drawRingFinger(webcam->finger[3]);
    hand->drawLittleFinger(webcam->finger[4]);
    glPopMatrix();

    // When the wall is out of sight, the hand configuration changes
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

    // When the wall is between -130 and -70, the detection zone begins
    if((wall->getPosition() > -130.f) && (wall->getPosition() < -70.f) && !has_been_analyzed) {
        // Changing the color of the hand
        GLfloat green[3] = {.0f + compteur, 1.f - compteur/5, .0f};
        hand->setColor(green);
        compteur += .06f;

        // When close to the end of the zone, the detection starts
        if(wall->getPosition() > -76.f) {
            // Boolean changed so that the detection is done only once per zone
            has_been_analyzed = true;
            compteur = .0f;
            emit analyze();
        }
    } else {
        GLfloat grey[3] = {.7f, .7f, .7f};
        hand->setColor(grey);
    }

    // Enabling texture for the wall
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, mur_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, mur.width(), mur.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, mur.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenTextures(1, &mur_texture);

    // Changing the position of the wall
    wall->setPosition(wall->getPosition() + 1.5f);
    wall->drawWallBase();
    wall->drawWallThumb(this->wall_finger[0]);
    wall->drawWallIndex(this->wall_finger[1]);
    wall->drawWallMiddleFinger(this->wall_finger[2], this->wall_finger[1], this->wall_finger[3]);
    wall->drawWallRingFinger(this->wall_finger[3]);
    wall->drawWallLittleFinger(this->wall_finger[4], this->wall_finger[3]);
    wall->drawLogo();
    glDisable(GL_TEXTURE_2D);

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
