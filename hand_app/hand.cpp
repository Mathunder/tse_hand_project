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

    //Intérieur de la main -------------------

    //Colonne 1
    cube.drawCube(-7, 0, 0.f);

    //Colonne 2
    for(int i=-2; i<=1; i++)
        cube.drawCube(-6, i, 0.f);

    //Colone 3
    for(int i=-4; i<=-1; i++)
        cube.drawCube(-5, i, 0.f);

    //Colonne 4 & 5
    for(int j=-4; j<=-3; j++) {
        for(int i=-6; i<=7; i++)
            cube.drawCube(j, i, 0.f);
    }
    cube.drawCube(-3, -7, 0.f);

    //Colonne 6
    for(int i=-7; i<=3; i++)
        cube.drawCube(-2, i, 0.f);

    //Colonne 7 & 8
    for(int j=-1; j<=0; j++) {
        for(int i=-7; i<=8; i++)
            cube.drawCube(j, i, 0.f);
    }

    //Colonne 9
    for(int i=-7; i<=3; i++)
        cube.drawCube(1, i, 0.f);

    //Colonne 10 & 11
    for(int j=2; j<=3; j++) {
        for(int i=-7; i<=6; i++)
            cube.drawCube(j, i, 0.f);
    }

    //Colonne 12
    for(int i=-7; i<=3; i++)
        cube.drawCube(4, i, 0.f);

    //Colonne 13
    for(int i=-4; i<=6; i++)
        cube.drawCube(5, i, 0.f);

    //Colonne 14
    for(int i=-2; i<=5; i++)
        cube.drawCube(6, i, 0.f);

    //Contour de la main --------------


}

void Hand::drawThumb() {
    for(int j=1; j<=2; j++)
        cube.drawCube(-8, j, 0.f);
    for(int j=0; j<=2; j++)
        cube.drawCube(-7, j, 0.f);
    for(int j=-2; j<=1; j++)
        cube.drawCube(-6, j, 0.f);
    for(int j=-4; j<=-1; j++)
        cube.drawCube(-5, j, 0.f);
}

void Hand::drawIndex() {
    for(int i=-4; i<=-3; i++) {
        for(int j=4; j<=11; j++)
            cube.drawCube(i, j, 0.f);
    }
}

void Hand::drawMiddleFinger() {
    for(int i=-1; i<=0; i++) {
        for(int j=4; j<=8; j++)
            cube.drawCube(i, j, 0.f);
    }
}

void Hand::drawRingFinger() {
    for(int i=2; i<=3; i++) {
        for(int j=4; j<=7; j++)
            cube.drawCube(i, j, 0.f);
    }
}

void Hand::drawLittleFinger() {
    for(int j=4; j<=6; j++)
        cube.drawCube(5, j, 0.f);
    for(int j=4; j<=5; j++)
        cube.drawCube(6, j, 0.f);
}

