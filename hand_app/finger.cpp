#include "finger.h"
#include <GL/glu.h>


Finger::Finger() {

}

void Finger::drawFinger() {
    if(this->finger_is_drawn) {

        glClearColor(0.9f, 0.9f, 0.9f, 0.0f);

        // Définition de la matrice de projection pour définir la perspective
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(70.0f, 50.0f, 2.0f, 10.0f);

        // Définition de la matrice de modélisation-visualisation pour définir la camera
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(2.0f, 2.0f, 5.0f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);


        // Face 1
        glBegin(GL_QUADS);
        glColor3ub(0.5f, 0.5f, 0.5f);
        glVertex3f(0.f, 0.f, 0.f);
        glVertex3f(1.f, 0.f, 0.f);
        glVertex3f(1.f, 1.f, 0.f);
        glVertex3f(0.f, 1.f, 0.f);
        glEnd();
    }
}
