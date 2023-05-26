#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <GL/glu.h>
#include "hand.h"
#include <QTimer>

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
    ~Scene();

private:
    Ui::Scene *ui;
    Hand *hand = new Hand();
//    QTimer *timer;
//public slots:
//    void update();
};

#endif // SCENE_H
