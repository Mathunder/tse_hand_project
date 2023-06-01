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
    // Constructor
    explicit Scene(QWidget *parent = nullptr);
    // Allows to link the webcam that analyzes the hand and the 3D scene (link Webcam and Scene)
    void setWebcam(Webcam *webcam);
    // Destructor
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
    // The following signals must be sent when :
    // A collision happened
    void collisionOccured();
    // The wall has been passed
    void wallPassed();
    // The hand must be analyzed
    void analyze();
};

#endif // SCENE_H
