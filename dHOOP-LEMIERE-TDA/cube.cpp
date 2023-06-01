#include "cube.h"
#include <GL/glu.h>
#include <QtWidgets>


Cube::Cube(float depth)
{
    this->depth = depth;
}

Cube::~Cube() {
}


void Cube::drawCube(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z, GLfloat color[]) {
    // Rear face
    glMaterialfv(GL_FRONT, GL_AMBIENT, blue);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    glBegin(GL_QUADS);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Right face
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Power face
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.2f, 0.5f);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y , bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Left face
    glMaterialfv(GL_FRONT, GL_AMBIENT, dark_grey); // Matériau et couleur des prochains objets
    glMaterialfv(GL_FRONT, GL_DIFFUSE, dark_grey); // dark_grey
    glBegin(GL_QUADS);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Upper face
    glMaterialfv(GL_FRONT, GL_AMBIENT, grey); // Matériau et couleur des prochains objets
    glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
    glBegin(GL_QUADS);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Front face
    glMaterialfv(GL_FRONT, GL_AMBIENT, color); // Matériau et couleur des prochains objets
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
    glBegin(GL_QUADS);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glEnd();
}

void Cube::drawCube(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z) {
    // Rear face
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Right face
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Lower face
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y , bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Left face
    glMaterialfv(GL_FRONT, GL_AMBIENT, dark_grey);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, dark_grey);
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Upper face
    glMaterialfv(GL_FRONT, GL_AMBIENT, grey);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Front face
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glEnd();
}

void Cube::drawCubeTextureLogo(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z, GLuint texture) {
    // Rear face
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glColor3f(blue[0], blue[1], blue[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Right face
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Lower face
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glColor3f(0.5f, 0.2f, 0.5f);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y , bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Left face
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glColor3f(dark_grey[0], dark_grey[1], dark_grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Upper face
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glColor3f(grey[0], grey[1], grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Front face
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glEnd();
}
