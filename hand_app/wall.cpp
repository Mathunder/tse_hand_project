#ifndef WALL_CPP
#define WALL_CPP

#include "wall.h"
#include <GL/glu.h>
#include <QtWidgets>

Wall::Wall(){
    position = -150.0f;
    cube = new Cube(10.f);
}

Wall::~Wall() {
    delete cube;
}

void Wall::drawWallBase(){
    // Parties du mur sur les côtés de la main

    // Colonnes pour x de -15 à -10
    for(int i=-15; i<=-10; i++)
        for(int j=-15; j<=18; j++)
            cube->drawCube(i, j, position, grey);
    // Colonnes pour x de 8 à 15
    for(int i=8; i<=15; i++)
        for(int j=-15; j<=18; j++)
            cube->drawCube(i, j, position, grey);

    // Colonnes du pouce
    // Au dessus du pouce
    for(int i=-9; i<=-7; i++)
        for(int j=4; j<=18; j++)
            cube->drawCube(i, j, position, grey);
    for(int j=3; j<=18; j++)
        cube->drawCube(-6, j, position, grey);
    // En dessous le pouce
    for(int j=-15; j<=0; j++)
        cube->drawCube(-9, j, position, grey);
    for(int j=-15; j<=-2; j++)
        cube->drawCube(-8, j, position, grey);
    for(int j=-15; j<=-3; j++)
        cube->drawCube(-7, j, position, grey);
    for(int j=-15; j<=-5; j++)
        cube->drawCube(-6, j, position, grey);

    // Colonnes de l'index
    // Colonne x=-5
    for(int j=-15; j<=-7; j++)
        cube->drawCube(-5, j, position, grey);
    for(int j=13; j<=18; j++)
        cube->drawCube(-5, j, position, grey);

    // Colonnes x=-4 et x=-3
    for(int j=-15; j<=-9; j++) {
        cube->drawCube(-4, j, position, grey);
        cube->drawCube(-3, j, position, grey);
    }
    for(int j=14; j<=18; j++) {
        cube->drawCube(-4, j, position, grey);
        cube->drawCube(-3, j, position, grey);
    }

    // Colonnes du majeur
    // Colonne x=-2
    for(int j=-15; j<=-9; j++)
        cube->drawCube(-2, j, position, grey);
    for(int j=15; j<=18; j++)
        cube->drawCube(-2, j, position, grey);
    // Colonnes x=-1 et x=0
    for(int j=-15; j<=-9; j++) {
        cube->drawCube(-1, j, position, grey);
        cube->drawCube(0, j, position, grey);
    }
    for(int j=16; j<=18; j++) {
        cube->drawCube(-1, j, position, grey);
        cube->drawCube(0, j, position, grey);
    }
    // Colonne x=1
    for(int j=-15; j<=-9; j++)
        cube->drawCube(1, j, position, grey);
    for(int j=15; j<=18; j++)
        cube->drawCube(1, j, position, grey);

    // Colonnes de l'annulaire
    // Colonnes x=-4 et x=-3
    for(int j=-15; j<=-9; j++) {
        cube->drawCube(2, j, position, grey);
        cube->drawCube(3, j, position, grey);
    }
    for(int j=14; j<=18; j++) {
        cube->drawCube(2, j, position, grey);
        cube->drawCube(3, j, position, grey);
    }
    // Colonne x=4
    for(int j=-15; j<=-9; j++)
        cube->drawCube(4, j, position, grey);
    for(int j=13; j<=18; j++)
        cube->drawCube(4, j, position, grey);

    // Colonnes de l'auriculaire
    // Colonnes x=5
    for(int j=-15; j<=-9; j++)
        cube->drawCube(5, j, position, grey);
    for(int j=12; j<=18; j++)
        cube->drawCube(5, j, position, grey);
    // Colonnes x=6
    for(int j=-15; j<=-5; j++)
        cube->drawCube(6, j, position, grey);
    for(int j=12; j<=18; j++)
        cube->drawCube(6, j, position, grey);
    // Colonnes x=7
    for(int j=-15; j<=-3; j++)
        cube->drawCube(7, j, position, grey);
    for(int j=11; j<=18; j++)
        cube->drawCube(7, j, position, grey);

    // Contour de la main ------------

    //Colonne 1
    cube->drawCube(-7, -2, position, black);

    //Colonne 2
    cube->drawCube(-6, 2, position, black);
    cube->drawCube(-6, -3, position, black);
    cube->drawCube(-6, -4, position, black);

    //Colonne 3
    for(int i=0; i<=7; i++)
        cube->drawCube(-5, i, position, black);
    cube->drawCube(-5, -5, position, black);
    cube->drawCube(-5, -6, position, black);

    //Colonne 4
    cube->drawCube(-4, -7, position, black);

    //Ligne dessous main
    for(int i=-4; i<=5; i++)
        cube->drawCube(i, -8, position, black);

    //Colonne 6
    for(int i=4; i<=9; i++)
        cube->drawCube(-2, i, position, black);

    //Colonne 9
    for(int i=4; i<=8; i++)
        cube->drawCube(1, i, position, black);

    //Colonne 12
    for(int i=4; i<=7; i++)
        cube->drawCube(4, i, position, black);

    //Colonne 13
    for(int i=-8; i<=-5; i++)
        cube->drawCube(5, i, position, black);

    //Colonne 14
    for(int i=-4; i<=-3; i++)
        cube->drawCube(6, i, position, black);

    //Colonne 15
    for(int i=-2; i<=6; i++)
        cube->drawCube(7, i, position, black);
}

void Wall::drawWallThumb(boolean is_drawn){
    if(is_drawn){
        // Colonnes x=-9 et x=-8
        for(int j=1; j<=3; j++){
            cube->drawCube(-9, j, position, grey);
            cube->drawCube(-8, j, position, grey);
        }
        // Colonne x=-7
        for(int j=2; j<=3; j++)
            cube->drawCube(-7, j, position, grey);

        // Coutour mur pouce fermé
        cube->drawCube(-8, -1, position, black);
        cube->drawCube(-8, -1, position, black);
        cube->drawCube(-8, 0, position, black);
        cube->drawCube(-7, 1, position, black);
    }
    else {
        //Contour pouce levé
        for(int i=1; i<=3; i++)
            cube->drawCube(-9, i, position, black);
        cube->drawCube(-8, 3, position, black);
        cube->drawCube(-8, 0, position, black);
        cube->drawCube(-7, 3, position, black);
        cube->drawCube(-7, -1, position, black);
        cube->drawCube(-8, -1, position, grey);
    }

}

void Wall::drawWallIndex(boolean is_drawn){
    if(is_drawn){
        // Colonnes x=-5
        for(int j=8; j<=12; j++)
            cube->drawCube(-5, j, position, grey);
        // Colonnes x=-4 et x=-3
        for(int j=9; j<=13; j++){
            cube->drawCube(-4, j, position, grey);
            cube->drawCube(-3, j, position, grey);
        }
        // Contour index fermé
        cube->drawCube(-4, 8, position, black);
        cube->drawCube(-3, 8, position, black);
    } else {
        // Contour index levé
        for(int i=8; i<=12; i++)
            cube->drawCube(-5, i, position, black);
        cube->drawCube(-4, 13, position, black);
        cube->drawCube(-3, 13, position, black);
        for(int i=10; i<=12; i++)
            cube->drawCube(-2, i, position, black);
    }
}

void Wall::drawWallMiddleFinger(boolean middleWall_is_drawn, boolean indexWall_is_drawn, boolean ringWall_is_drawn){
    if(middleWall_is_drawn){
        // Colonnes x=-2 et x=1
        for(int j=13; j<=14; j++){
            cube->drawCube(-2, j, position, grey);
            cube->drawCube(1, j, position, grey);
        }
        //        cube->drawCube(1, 9, position, grey);
        // Colonnes x=-1 et x=0
        for(int j=10; j<=16; j++){
            cube->drawCube(-1, j, position, grey);
            cube->drawCube(0, j, position, grey);
        }
        // Si l'index est aussi fermé / le mur de l'index est dessiné
        if(indexWall_is_drawn){
            for(int j=10; j<=14; j++)
                cube->drawCube(-2, j, position, grey);
        }
        // Si l'annulaire est aussi fermé / le mur d'annulaire est dessiné
        if(ringWall_is_drawn){
            for(int j=9; j<=14; j++)
                cube->drawCube(1, j, position, grey);
        }

        // Contour majeur fermé
        cube->drawCube(-1, 9, position, black);
        cube->drawCube(0, 9, position, black);

    } else {
        // Contour majeur levé
        for(int i=10; i<=14; i++)
            cube->drawCube(-2, i, position, black);
        cube->drawCube(-1, 15, position, black);
        cube->drawCube(0, 15, position, black);
        for(int i=9; i<=14; i++)
            cube->drawCube(1, i, position, black);
    }
}

void Wall::drawWallRingFinger(boolean is_drawn){
    if(is_drawn){
        // Colonnes x=2 et x=3
        for(int j=9; j<=13; j++){
            cube->drawCube(2, j, position, grey);
            cube->drawCube(3, j, position, grey);
        }
        // Colonne x=4
        for(int j=11; j<=12; j++)
            cube->drawCube(4, j, position, grey);

        // Contour de l'annulaire fermé
        cube->drawCube(2, 8, position, black);
        cube->drawCube(3, 8, position, black);

    } else {
        // Contour de l'annulaire levé
        for(int i=9; i<=12; i++)
            cube->drawCube(1, i, position, black);
        cube->drawCube(2, 13, position, black);
        cube->drawCube(3, 13, position, black);
        for(int i=8; i<=12; i++)
            cube->drawCube(4, i, position, black);
    }
}

void Wall::drawWallLittleFinger(boolean littleWall_is_drawn, boolean ringWall_is_drawn){
    if(littleWall_is_drawn){
        // Colonnes x=5 et x=6
        for(int j=8; j<=11; j++){
            cube->drawCube(5, j, position, grey);
            cube->drawCube(6, j, position, grey);
        }
        cube->drawCube(6, 7, position, grey);
        cube->drawCube(7, 10, position, grey);


        // Colonne x=7
        for(int j=7; j<=9; j++)
            cube->drawCube(7, j, position, grey);
        // Si l'annulaire est aussi fermé / le mur d'annulaire est dessiné
        if(ringWall_is_drawn){
            for(int j=8; j<=10; j++)
                cube->drawCube(4, j, position, grey);
        }

        // Contour auriculaire fermé
        cube->drawCube(5, 7, position, black);
        cube->drawCube(6, 6, position, black);

    } else {
        // Contour auriculaire levé
        cube->drawCube(4, 8, position, black);
        cube->drawCube(4, 9, position, black);
        cube->drawCube(4, 10, position, black);
        cube->drawCube(5, 11, position, black);
        cube->drawCube(6, 11, position, black);
        cube->drawCube(7, 10, position, black);
        cube->drawCube(7, 9, position, black);
        cube->drawCube(7, 8, position, black);
        cube->drawCube(7, 7, position, black);
    }
}

float Wall::getPosition() {
    return position;
}

void Wall::setPosition(float pos) {
    position = pos;
}

#endif // WALL_CPP
