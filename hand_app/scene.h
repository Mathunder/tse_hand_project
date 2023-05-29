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

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

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
};

#endif // SCENE_H
