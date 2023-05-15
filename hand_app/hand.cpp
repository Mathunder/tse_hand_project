#include "hand.h"
#include "cube.h"
#include <GL/glu.h>

Hand::Hand() {

}

// Dessin de la partie centrale de la main, toujours affichée
void Hand::drawBase() {
    /*
     * for(colonne) {
     *    for(ligne)
     *      cube.drawCube(...)
     * }
     */

    GLfloat grey[3] = {0.7f, 0.7f, 0.7f};
    GLfloat black[3] = {0.f, 0.f, 0.f};


    //Intérieur de la main -------------------


    //Colonne 1
    cube.drawCube(-7, 0, 0.f, grey);

    //Colonne 2
    for(int i=-2; i<=1; i++)
        cube.drawCube(-6, i, 0.f, grey);

    //Colone 3
    for(int i=-4; i<=-1; i++)
        cube.drawCube(-5, i, 0.f, grey);

    //Colonne 4 & 5
    for(int j=-4; j<=-3; j++) {
        for(int i=-6; i<=7; i++)
            cube.drawCube(j, i, 0.f, grey);
    }
    cube.drawCube(-3, -7, 0.f, grey);

    //Colonne 6
    for(int i=-7; i<=3; i++)
        cube.drawCube(-2, i, 0.f, grey);

    //Colonne 7 & 8
    for(int j=-1; j<=0; j++) {
        for(int i=-7; i<=8; i++)
            cube.drawCube(j, i, 0.f, grey);
    }

    //Colonne 9
    for(int i=-7; i<=3; i++)
        cube.drawCube(1, i, 0.f, grey);

    //Colonne 10 & 11
    for(int j=2; j<=3; j++) {
        for(int i=-7; i<=7; i++)
            cube.drawCube(j, i, 0.f, grey);
    }

    //Colonne 12
    for(int i=-7; i<=3; i++)
        cube.drawCube(4, i, 0.f, grey);

    //Colonne 13
    for(int i=-4; i<=6; i++)
        cube.drawCube(5, i, 0.f, grey);

    //Colonne 14
    for(int i=-2; i<=5; i++)
        cube.drawCube(6, i, 0.f, grey);


    //Contour de la main --------------

    //Colonne 1
    cube.drawCube(-7, -2, 0.f, black);

    //Colonne 2
    cube.drawCube(-6, 2, 0.f, black);
    cube.drawCube(-6, -3, 0.f, black);
    cube.drawCube(-6, -4, 0.f, black);

    //Colonne 3
    for(int i=0; i<=7; i++)
        cube.drawCube(-5, i, 0.f, black);
    cube.drawCube(-5, -5, 0.f, black);
    cube.drawCube(-5, -6, 0.f, black);

    //Colonne 4
    cube.drawCube(-4, -7, 0.f, black);

    //Ligne dessous main
    for(int i=-4; i<=5; i++)
        cube.drawCube(i, -8, 0.f, black);

    //Colonne 6
    for(int i=4; i<=9; i++)
        cube.drawCube(-2, i, 0.f, black);

    //Colonne 9
    for(int i=4; i<=8; i++)
        cube.drawCube(1, i, 0.f, black);

    //Colonne 12
    for(int i=4; i<=7; i++)
        cube.drawCube(4, i, 0.f, black);

    //Colonne 13
    for(int i=-8; i<=-5; i++)
        cube.drawCube(5, i, 0.f, black);

    //Colonne 14
    for(int i=-4; i<=-3; i++)
        cube.drawCube(6, i, 0.f, black);

    //Colonne 15
    for(int i=-2; i<=6; i++)
        cube.drawCube(7, i, 0.f, black);

}

void Hand::drawThumb(boolean is_drawn) {
    if(is_drawn) {

        //Interieur pouce
        for(int j=1; j<=2; j++) {
            for(int i=-8; i<=-7; i++)
                cube.drawCube(i, j, 0.f, light_grey);
        }

        //Contour pouce
        for(int i=1; i<=3; i++)
            cube.drawCube(-9, i, 0.f, black);
        cube.drawCube(-8, 3, 0.f, black);
        cube.drawCube(-8, 0, 0.f, black);
        cube.drawCube(-7, 3, 0.f, black);
        cube.drawCube(-7, -1, 0.f, black);
    } else {
        cube.drawCube(-7, -1, 0.f, light_grey);
        cube.drawCube(-8, -1, 0.f, black);
        cube.drawCube(-8, 0, 0.f, black);
        cube.drawCube(-7, 1, 0.f, black);
    }
}

void Hand::drawIndex(boolean is_drawn) {
    if(is_drawn) {
        //Intérieur index
        for(int j=8; j<=12; j++) {
            for(int i=-4; i<=-3; i++)
                cube.drawCube(i, j, 0.f, light_grey);
        }
        //Contour index
        for(int i=8; i<=12; i++)
            cube.drawCube(-5, i, 0.f, black);
        cube.drawCube(-4, 13, 0.f, black);
        cube.drawCube(-3, 13, 0.f, black);
        for(int i=10; i<=12; i++)
            cube.drawCube(-2, i, 0.f, black);
    } else {
        cube.drawCube(-4, 8, 0.f, black);
        cube.drawCube(-3, 8, 0.f, black);
    }
}

void Hand::drawMiddleFinger(boolean is_drawn) {
    if(is_drawn) {
        // Intérieur majeur
        for(int j=9; j<=14; j++) {
            for(int i=-1; i<=0; i++)
                cube.drawCube(i, j, 0.f, light_grey);
        }
        // Contour majeur
        for(int i=10; i<=14; i++)
            cube.drawCube(-2, i, 0.f, black);
        cube.drawCube(-1, 15, 0.f, black);
        cube.drawCube(0, 15, 0.f, black);
        for(int i=9; i<=14; i++)
            cube.drawCube(1, i, 0.f, black);
    } else {
        cube.drawCube(-1, 9, 0.f, black);
        cube.drawCube(0, 9, 0.f, black);
    }
}

void Hand::drawRingFinger(boolean is_drawn) {
    if(is_drawn) {
        // Intérieur du doigt
        for(int j=8; j<=12; j++) {
            for(int i=2; i<=3; i++)
                cube.drawCube(i, j, 0.f, light_grey);
        }
        // Contour du doigt
        for(int i=9; i<=12; i++)
            cube.drawCube(1, i, 0.f, black);
        cube.drawCube(2, 13, 0.f, black);
        cube.drawCube(3, 13, 0.f, black);
        for(int i=8; i<=12; i++)
            cube.drawCube(4, i, 0.f, black);
    } else {
        cube.drawCube(2, 8, 0.f, black);
        cube.drawCube(3, 8, 0.f, black);
    }
}

void Hand::drawLittleFinger(boolean is_drawn) {
    if(is_drawn) {
        // Intérieur du doigt
        for(int j=7; j<=9; j++) {
            for(int i=5; i<=6; i++)
                cube.drawCube(i, j, 0.f, light_grey);
        }
        cube.drawCube(6, 6, 0.f, light_grey);
        // Contour du doigt
        cube.drawCube(4, 8, 0.f, black);
        cube.drawCube(4, 9, 0.f, black);
        cube.drawCube(5, 10, 0.f, black);
        cube.drawCube(6, 10, 0.f, black);
        cube.drawCube(7, 9, 0.f, black);
        cube.drawCube(7, 8, 0.f, black);
        cube.drawCube(7, 7, 0.f, black);
    } else {
        cube.drawCube(5, 7, 0.f, black);
        cube.drawCube(6, 6, 0.f, black);
    }
}

