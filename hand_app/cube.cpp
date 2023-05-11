#include "cube.h"
#include <GL/glu.h>


Cube::Cube()
{

}

void Cube::drawCube(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z) {
    // Face arrière
    glBegin(GL_QUADS);
    glColor3f(blue[0], blue[1], blue[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-1);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-1);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-1);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-1);
    glEnd();

    // Face droite
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-1);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-1);
    glEnd();

    // Face bas
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.2f, 0.5f);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y , bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-1);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-1);
    glEnd();

    // Face gauche
    glBegin(GL_QUADS);
    glColor3f(dark_grey[0], dark_grey[1], dark_grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-1);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-1);
    glEnd();

    // Face haut
    glBegin(GL_QUADS);
    glColor3f(grey[0], grey[1], grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-1);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-1);
    glEnd();

    // Face avant
    glBegin(GL_QUADS);
    glColor3f(light_grey[0], light_grey[1], light_grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glEnd();
}
