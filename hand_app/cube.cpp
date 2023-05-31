#include "cube.h"
#include <GL/glu.h>


Cube::Cube(float depth)
{
    this->depth = depth;
}

Cube::~Cube() {
}

void Cube::drawCubeTexture(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z, GLfloat color[], GLuint texture) {
    // Face arrière
    glBegin(GL_QUADS);
    glColor3f(blue[0], blue[1], blue[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-2);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-2);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-2);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-2);
    glEnd();

    // Face droite
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-2);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-2);
    glEnd();

    // Face bas
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.2f, 0.5f);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y , bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-2);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-2);
    glEnd();

    // Face gauche
    glBegin(GL_QUADS);
    glColor3f(dark_grey[0], dark_grey[1], dark_grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-2);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-2);
    glEnd();

    // Face haut
    glBegin(GL_QUADS);
    glColor3f(grey[0], grey[1], grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-2);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-2);
    glEnd();

//    // Face avant
    glBindTexture(GL_TEXTURE_2D, texture);
    // On dessine la texture et la face avant
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glEnd();

}

void Cube::drawCube(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z, GLfloat color[]) {
    // Face arrière
    glBegin(GL_QUADS);
    glColor3f(blue[0], blue[1], blue[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Face droite
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Face bas
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.2f, 0.5f);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y , bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Face gauche
    glBegin(GL_QUADS);
    glColor3f(dark_grey[0], dark_grey[1], dark_grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Face haut
    glBegin(GL_QUADS);
    glColor3f(grey[0], grey[1], grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Face avant
    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glEnd();
}
