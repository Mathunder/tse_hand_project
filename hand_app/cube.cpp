#include "cube.h"
#include <GL/glu.h>
#include <QtWidgets>


Cube::Cube(float depth)
{
    this->depth = depth;
}

Cube::~Cube() {
}


void Cube::drawCube(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z, GLfloat color[], boolean is_wall) {
    if (is_wall){
        // Texture du mur
        glEnable(GL_TEXTURE_2D);
        QImage mur(":/res/logo/mur.png");
        mur = mur.convertToFormat(QImage::Format_RGBA8888);
        GLuint mur_texture;
        glGenTextures(1, &mur_texture);

        glBindTexture(GL_TEXTURE_2D, mur_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, 4, mur.width(), mur.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, mur.bits());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



        // Face arrière
        glMaterialfv(GL_FRONT, GL_AMBIENT, blue);// Matériau et couleur des prochains objets
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
        glBegin(GL_QUADS);
        glNormal3f(0.0, 0.0, -1.0);
    //    glColor3f(blue[0], blue[1], blue[2]);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
        glEnd();

        // Face droite
        glBegin(GL_QUADS);
        glNormal3f(1.0, 0.0, 0.0);
        glColor3f(0.1f, 0.2f, 0.3f);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
        glEnd();

        // Face bas
        glBegin(GL_QUADS);
        glNormal3f(0.0, -1.0, 0.0);
        glColor3f(0.5f, 0.2f, 0.5f);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y , bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
        glEnd();


        // Texture sur les faces gauche, haut et avant
        glBindTexture(GL_TEXTURE_2D, mur_texture);
        // Face gauche
        glMaterialfv(GL_FRONT, GL_AMBIENT, dark_grey); // Matériau et couleur des prochains objets
        glMaterialfv(GL_FRONT, GL_DIFFUSE, dark_grey); // dark_grey
        glBegin(GL_QUADS);
        glNormal3f(-1.0, 0.0, 0.0);
    //    glColor3f(dark_grey[0], dark_grey[1], dark_grey[2]);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
        glEnd();

        // Face haut
        glMaterialfv(GL_FRONT, GL_AMBIENT, grey); // Matériau et couleur des prochains objets
        glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
        glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0, 0.0);
    //    glColor3f(grey[0], grey[1], grey[2]);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
        glEnd();

        // Face avant
        // On dessine la texture et la face avant
        glBegin(GL_QUADS);
        glNormal3f(0.0, 0.0, 1.0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    else { // Cubes sans texture, cubes utilisé pour la main
        // Face arrière
        glMaterialfv(GL_FRONT, GL_AMBIENT, blue);// Matériau et couleur des prochains objets
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
        glBegin(GL_QUADS);
    //    glColor3f(blue[0], blue[1], blue[2]);
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
        glMaterialfv(GL_FRONT, GL_AMBIENT, dark_grey); // Matériau et couleur des prochains objets
        glMaterialfv(GL_FRONT, GL_DIFFUSE, dark_grey); // dark_grey
        glBegin(GL_QUADS);
    //    glColor3f(dark_grey[0], dark_grey[1], dark_grey[2]);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
        glEnd();

        // Face haut
        glMaterialfv(GL_FRONT, GL_AMBIENT, grey); // Matériau et couleur des prochains objets
        glMaterialfv(GL_FRONT, GL_DIFFUSE, grey);
        glBegin(GL_QUADS);
    //    glColor3f(grey[0], grey[1], grey[2]);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
        glEnd();

        // Face avant
        glMaterialfv(GL_FRONT, GL_AMBIENT, color); // Matériau et couleur des prochains objets
        glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
        glBegin(GL_QUADS);
    //    glColor3f(color[0], color[1], color[2]);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
        glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
        glEnd();
    }
}

void Cube::drawCubeTextureLogo(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z, GLfloat color[], GLuint texture) {
    // Face arrière
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glColor3f(blue[0], blue[1], blue[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Face droite
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glColor3f(0.1f, 0.2f, 0.3f);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Face bas
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glColor3f(0.5f, 0.2f, 0.5f);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y , bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Face gauche
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glColor3f(dark_grey[0], dark_grey[1], dark_grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z-depth);
    glEnd();

    // Face haut
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glColor3f(grey[0], grey[1], grey[2]);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z-depth);
    glEnd();

    // Face avant
    glBindTexture(GL_TEXTURE_2D, texture);
    // On dessine la texture et la face avant
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y, bottom_left_corner_z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(bottom_left_corner_x, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y + 1, bottom_left_corner_z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(bottom_left_corner_x + 1, bottom_left_corner_y, bottom_left_corner_z);
    glEnd();
}
