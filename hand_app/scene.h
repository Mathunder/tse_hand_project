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


/*
 * This class draws the 3D scene and send signals if some conditions are met.
 *
 * @author : Matthieu d'Hoop
 * @co-author : Alban Lemière
 */
class Scene : public QOpenGLWidget
{
    Q_OBJECT

protected:
    void initializeGL();
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
    QImage mur;
    GLuint mur_texture;

signals:
    void collisionOccured();
    void wallPassed();
    void analyze();
};

#endif // SCENE_H
