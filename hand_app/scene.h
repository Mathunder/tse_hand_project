#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <GL/glu.h>
#include "hand.h"
#include <QTimer>
#include "webcam.h"
#include "wall.h"

namespace Ui {
class Scene;
}

class Scene : public QOpenGLWidget
{
    Q_OBJECT

protected:

    // Fonction d'initialisation
    void initializeGL();

//    // Fonction de redimensionnement
//    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

public:
    explicit Scene(QWidget *parent = nullptr);
    void setWebcam(Webcam *webcam);
    ~Scene();

private:
    Ui::Scene *ui;
    Hand *hand;
    Wall *wall;
    Webcam *webcam;
    Cube *cube;
    bool wall_finger[5] = {true, true, true, true, true};
    int temp = 0;
    bool one_by_one;
    bool has_been_analyzed;
    float compteur;

signals:
    void collisionOccured();
    void wallPassed();
    void analyze();
};

#endif // SCENE_H
