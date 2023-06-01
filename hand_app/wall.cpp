#ifndef WALL_CPP
#define WALL_CPP

#include "wall.h"
#include <GL/glu.h>
#include <QtWidgets>

Wall::Wall(){
    position = -150.0f;
    cube = new Cube(10.f);
//    mur_texture = &mur_text;
}

Wall::~Wall() {
    delete cube;
}

void Wall::drawLogo() {
    // Textures logo (divisé en 4 pour être affiché en plus grand)
    QImage logo_1(":/res/logo/logo_tse_1.png");
    logo_1 = logo_1.mirrored(false, true);
    logo_1 = logo_1.convertToFormat(QImage::Format_RGBA8888);
    QImage logo_2(":/res/logo/logo_tse_2.png");
    logo_2 = logo_2.mirrored(false, true);
    logo_2 = logo_2.convertToFormat(QImage::Format_RGBA8888);
    QImage logo_3(":/res/logo/logo_tse_3.png");
    logo_3 = logo_3.mirrored(false, true);
    logo_3 = logo_3.convertToFormat(QImage::Format_RGBA8888);
    QImage logo_4(":/res/logo/logo_tse_4.png");
    logo_4 = logo_4.mirrored(false, true);
    logo_4 = logo_4.convertToFormat(QImage::Format_RGBA8888);

    GLuint * textures = new GLuint[4];
    glGenTextures(4, textures);
    // Texture 1
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, logo_1.width(), logo_1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, logo_1.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Texture 2
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, logo_2.width(), logo_2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, logo_2.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Texture 3
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, logo_3.width(), logo_3.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, logo_3.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Texture 4
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, logo_4.width(), logo_4.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, logo_4.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    // On affiche les cubes sur lesquels ont affiche le logo TSE (divisé en 4)
    cube->drawCubeTextureLogo(-15, 18, position, textures[0]);
    cube->drawCubeTextureLogo(-14, 18, position, textures[1]);
    cube->drawCubeTextureLogo(-14, 17, position, textures[2]);
    cube->drawCubeTextureLogo(-15, 17, position, textures[3]);
}

void Wall::drawWallBase(){
    // Parties du mur sur les côtés de la main
    // Colonnes pour x=-15 et x=-14
    for(int j=-15; j<=16; j++)
        cube->drawCube(-15, j, position);
    for(int j=-15; j<=16; j++)
        cube->drawCube(-14, j, position);
    // Colonnes pour x de -13 à -10
    for(int i=-13; i<=-10; i++)
        for(int j=-15; j<=18; j++)
            cube->drawCube(i, j, position);
    // Colonnes pour x de 8 à 15
    for(int i=8; i<=15; i++)
        for(int j=-15; j<=18; j++)
            cube->drawCube(i, j, position);

    // Colonnes du pouce
    // Au dessus du pouce
    for(int i=-9; i<=-7; i++)
        for(int j=4; j<=18; j++)
            cube->drawCube(i, j, position);
    for(int j=3; j<=18; j++)
        cube->drawCube(-6, j, position);
    // En dessous le pouce
    for(int j=-15; j<=0; j++)
        cube->drawCube(-9, j, position);
    for(int j=-15; j<=-2; j++)
        cube->drawCube(-8, j, position);
    for(int j=-15; j<=-3; j++)
        cube->drawCube(-7, j, position);
    for(int j=-15; j<=-5; j++)
        cube->drawCube(-6, j, position);

    // Colonnes de l'index
    // Colonne x=-5
    for(int j=-15; j<=-7; j++)
        cube->drawCube(-5, j, position);
    for(int j=13; j<=18; j++)
        cube->drawCube(-5, j, position);

    // Colonnes x=-4 et x=-3
    for(int j=-15; j<=-9; j++) {
        cube->drawCube(-4, j, position);
        cube->drawCube(-3, j, position);
    }
    for(int j=14; j<=18; j++) {
        cube->drawCube(-4, j, position);
        cube->drawCube(-3, j, position);
    }

    // Colonnes du majeur
    // Colonne x=-2
    for(int j=-15; j<=-9; j++)
        cube->drawCube(-2, j, position);
    for(int j=15; j<=18; j++)
        cube->drawCube(-2, j, position);
    // Colonnes x=-1 et x=0
    for(int j=-15; j<=-9; j++) {
        cube->drawCube(-1, j, position);
        cube->drawCube(0, j, position);
    }
    for(int j=16; j<=18; j++) {
        cube->drawCube(-1, j, position);
        cube->drawCube(0, j, position);
    }
    // Colonne x=1
    for(int j=-15; j<=-9; j++)
        cube->drawCube(1, j, position);
    for(int j=15; j<=18; j++)
        cube->drawCube(1, j, position);

    // Colonnes de l'annulaire
    // Colonnes x=-4 et x=-3
    for(int j=-15; j<=-9; j++) {
        cube->drawCube(2, j, position);
        cube->drawCube(3, j, position);
    }
    for(int j=14; j<=18; j++) {
        cube->drawCube(2, j, position);
        cube->drawCube(3, j, position);
    }
    // Colonne x=4
    for(int j=-15; j<=-9; j++)
        cube->drawCube(4, j, position);
    for(int j=13; j<=18; j++)
        cube->drawCube(4, j, position);

    // Colonnes de l'auriculaire
    // Colonnes x=5
    for(int j=-15; j<=-9; j++)
        cube->drawCube(5, j, position);
    for(int j=12; j<=18; j++)
        cube->drawCube(5, j, position);
    // Colonnes x=6
    for(int j=-15; j<=-5; j++)
        cube->drawCube(6, j, position);
    for(int j=12; j<=18; j++)
        cube->drawCube(6, j, position);
    // Colonnes x=7
    for(int j=-15; j<=-3; j++)
        cube->drawCube(7, j, position);
    for(int j=11; j<=18; j++)
        cube->drawCube(7, j, position);

    // Contour de la main ------------

    //Colonne 1
    cube->drawCube(-7, -2, position);

    //Colonne 2
    cube->drawCube(-6, 2, position);
    cube->drawCube(-6, -3, position);
    cube->drawCube(-6, -4, position);

    //Colonne 3
    for(int i=0; i<=7; i++)
        cube->drawCube(-5, i, position);
    cube->drawCube(-5, -5, position);
    cube->drawCube(-5, -6, position);

    //Colonne 4
    cube->drawCube(-4, -7, position);

    //Ligne dessous main
    for(int i=-4; i<=5; i++)
        cube->drawCube(i, -8, position);

    //Colonne 6
    for(int i=4; i<=9; i++)
        cube->drawCube(-2, i, position);

    //Colonne 9
    for(int i=4; i<=8; i++)
        cube->drawCube(1, i, position);

    //Colonne 12
    for(int i=4; i<=7; i++)
        cube->drawCube(4, i, position);

    //Colonne 13
    for(int i=-8; i<=-5; i++)
        cube->drawCube(5, i, position);

    //Colonne 14
    for(int i=-4; i<=-3; i++)
        cube->drawCube(6, i, position);

    //Colonne 15
    for(int i=-2; i<=6; i++)
        cube->drawCube(7, i, position);

}

void Wall::drawWallThumb(boolean is_drawn){
    if(is_drawn){
        // Colonnes x=-9 et x=-8
        for(int j=1; j<=3; j++){
            cube->drawCube(-9, j, position);
            cube->drawCube(-8, j, position);
        }
        // Colonne x=-7
        for(int j=2; j<=3; j++)
            cube->drawCube(-7, j, position);

        // Coutour mur pouce fermé
        cube->drawCube(-8, -1, position);
        cube->drawCube(-8, -1, position);
        cube->drawCube(-8, 0, position);
        cube->drawCube(-7, 1, position);
    }
    else {
        //Contour pouce levé
        for(int i=1; i<=3; i++)
            cube->drawCube(-9, i, position);
        cube->drawCube(-8, 3, position);
        cube->drawCube(-8, 0, position);
        cube->drawCube(-7, 3, position);
        cube->drawCube(-7, -1, position);
        cube->drawCube(-8, -1, position);
    }

}

void Wall::drawWallIndex(boolean is_drawn){
    if(is_drawn){
        // Colonnes x=-5
        for(int j=8; j<=12; j++)
            cube->drawCube(-5, j, position);
        // Colonnes x=-4 et x=-3
        for(int j=9; j<=13; j++){
            cube->drawCube(-4, j, position);
            cube->drawCube(-3, j, position);
        }
        // Contour index fermé
        cube->drawCube(-4, 8, position);
        cube->drawCube(-3, 8, position);
    } else {
        // Contour index levé
        for(int i=8; i<=12; i++)
            cube->drawCube(-5, i, position);
        cube->drawCube(-4, 13, position);
        cube->drawCube(-3, 13, position);
        for(int i=10; i<=12; i++)
            cube->drawCube(-2, i, position);
    }
}

void Wall::drawWallMiddleFinger(boolean middleWall_is_drawn, boolean indexWall_is_drawn, boolean ringWall_is_drawn){
    if(middleWall_is_drawn){
        // Colonnes x=-2 et x=1
        for(int j=13; j<=14; j++){
            cube->drawCube(-2, j, position);
            cube->drawCube(1, j, position);
        }
        //        cube->drawCube(1, 9, position, grey);
        // Colonnes x=-1 et x=0
        for(int j=10; j<=16; j++){
            cube->drawCube(-1, j, position);
            cube->drawCube(0, j, position);
        }
        // Si l'index est aussi fermé / le mur de l'index est dessiné
        if(indexWall_is_drawn){
            for(int j=10; j<=14; j++)
                cube->drawCube(-2, j, position);
        }
        // Si l'annulaire est aussi fermé / le mur d'annulaire est dessiné
        if(ringWall_is_drawn){
            for(int j=9; j<=14; j++)
                cube->drawCube(1, j, position);
        }

        // Contour majeur fermé
        cube->drawCube(-1, 9, position);
        cube->drawCube(0, 9, position);

    } else {
        // Contour majeur levé
        for(int i=10; i<=14; i++)
            cube->drawCube(-2, i, position);
        cube->drawCube(-1, 15, position);
        cube->drawCube(0, 15, position);
        for(int i=9; i<=14; i++)
            cube->drawCube(1, i, position);
    }
}

void Wall::drawWallRingFinger(boolean is_drawn){
    if(is_drawn){
        // Colonnes x=2 et x=3
        for(int j=9; j<=13; j++){
            cube->drawCube(2, j, position);
            cube->drawCube(3, j, position);
        }
        // Colonne x=4
        for(int j=11; j<=12; j++)
            cube->drawCube(4, j, position);

        // Contour de l'annulaire fermé
        cube->drawCube(2, 8, position);
        cube->drawCube(3, 8, position);

    } else {
        // Contour de l'annulaire levé
        for(int i=9; i<=12; i++)
            cube->drawCube(1, i, position);
        cube->drawCube(2, 13, position);
        cube->drawCube(3, 13, position);
        for(int i=8; i<=12; i++)
            cube->drawCube(4, i, position);
    }
}

void Wall::drawWallLittleFinger(boolean littleWall_is_drawn, boolean ringWall_is_drawn){
    if(littleWall_is_drawn){
        // Colonnes x=5 et x=6
        for(int j=8; j<=11; j++){
            cube->drawCube(5, j, position);
            cube->drawCube(6, j, position);
        }
        cube->drawCube(6, 7, position);
        cube->drawCube(7, 10, position);


        // Colonne x=7
        for(int j=7; j<=9; j++)
            cube->drawCube(7, j, position);
        // Si l'annulaire est aussi fermé / le mur d'annulaire est dessiné
        if(ringWall_is_drawn){
            for(int j=8; j<=10; j++)
                cube->drawCube(4, j, position);
        }

        // Contour auriculaire fermé
        cube->drawCube(5, 7, position);
        cube->drawCube(6, 6, position);

    } else {
        // Contour auriculaire levé
        cube->drawCube(4, 8, position);
        cube->drawCube(4, 9, position);
        cube->drawCube(4, 10, position);
        cube->drawCube(5, 11, position);
        cube->drawCube(6, 11, position);
        cube->drawCube(7, 10, position);
        cube->drawCube(7, 9, position);
        cube->drawCube(7, 8, position);
        cube->drawCube(7, 7, position);
    }
}

float Wall::getPosition() {
    return position;
}

void Wall::setPosition(float pos) {
    position = pos;
}

#endif // WALL_CPP
