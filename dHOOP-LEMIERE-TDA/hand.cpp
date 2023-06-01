#include "hand.h"
#include "cube.h"
#include <GL/glu.h>

Hand::Hand() {
    cube = new Cube(2.f);
    for(int i=0; i < 3; i++) {
        color[i] = .7f;
    }
}

// Dessin de la partie centrale de la main, toujours affichée
void Hand::drawBase() {
    // Column 1
    cube->drawCube(-7, 0, 0.f, color);

    // Column 2
    for(int i=-2; i<=1; i++)
        cube->drawCube(-6, i, 0.f, color);

    // Column 3
    for(int i=-4; i<=-1; i++)
        cube->drawCube(-5, i, 0.f, color);

    // Column 4 & 5
    for(int j=-4; j<=-3; j++) {
        for(int i=-6; i<=7; i++)
            cube->drawCube(j, i, 0.f, color);
    }
    cube->drawCube(-3, -7, 0.f, color);

    // Column 6
    for(int i=-7; i<=3; i++)
        cube->drawCube(-2, i, 0.f, color);

    // Column 7 & 8
    for(int j=-1; j<=0; j++) {
        for(int i=-7; i<=8; i++)
            cube->drawCube(j, i, 0.f, color);
    }

    // Column 9
    for(int i=-7; i<=3; i++)
        cube->drawCube(1, i, 0.f, color);

    // Column 10 & 11
    for(int j=2; j<=3; j++) {
        for(int i=-7; i<=7; i++)
            cube->drawCube(j, i, 0.f, color);
    }

    // Column 12
    for(int i=-7; i<=3; i++)
        cube->drawCube(4, i, 0.f, color);

    // Column 13
    for(int i=-4; i<=6; i++)
        cube->drawCube(5, i, 0.f, color);

    // Column 14
    for(int i=-2; i<=5; i++)
        cube->drawCube(6, i, 0.f, color);
}

void Hand::drawThumb(boolean is_drawn) {
    if(is_drawn) {
        // Inside thumb
        for(int j=1; j<=2; j++) {
            for(int i=-8; i<=-7; i++)
                cube->drawCube(i, j, 0.f, color);
        }
    } else {
        cube->drawCube(-7, -1, 0.f, color);
    }
}

void Hand::drawIndex(boolean is_drawn) {
    if(is_drawn) {
        // Inside index
        for(int j=8; j<=12; j++) {
            for(int i=-4; i<=-3; i++)
                cube->drawCube(i, j, 0.f, color);
        }
    }
}

void Hand::drawMiddleFinger(boolean is_drawn) {
    if(is_drawn) {
        // Inside middle finger
        for(int j=9; j<=14; j++) {
            for(int i=-1; i<=0; i++)
                cube->drawCube(i, j, 0.f, color);
        }
    }
}

void Hand::drawRingFinger(boolean is_drawn) {
    if(is_drawn) {
        // Inside finger
        for(int j=8; j<=12; j++) {
            for(int i=2; i<=3; i++)
                cube->drawCube(i, j, 0.f, color);
        }

    }
}

void Hand::drawLittleFinger(boolean is_drawn) {
    if(is_drawn) {
        // Inside finger
        for(int j=7; j<=10; j++) {
            for(int i=5; i<=6; i++)
                cube->drawCube(i, j, 0.f, color);
        }
        cube->drawCube(6, 6, 0.f, color);
    }
}

void Hand::setColor(GLfloat col[3]) {
    for(int i=0; i < 3; i++) {
        color[i] = col[i];
    }
}

Hand::~Hand() {
    delete cube;
}
