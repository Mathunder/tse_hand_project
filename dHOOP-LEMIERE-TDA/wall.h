#ifndef WALL_H
#define WALL_H

#include "cube.h"
#include <GL/glu.h>
#include <QtWidgets>

/*
 * This class handles the modelization of the wall given the number of fingers that is randomly selected.
 *
 * @author : Alban Lemière
 * @co-author : Matthieu d'Hoop
 */
class Wall {
private:
    GLfloat light_grey[3] = {0.7f, 0.7f, 0.7f};
    GLfloat grey[3] = {0.5f, 0.5f, 0.5f};
    GLfloat dark_grey[3] = {0.3f, 0.3f, 0.3f};
    GLfloat black[3] = {0.f, 0.f, 0.f};
    GLfloat blue[3] = {0.f, 0.f, 1.f};
    float position;
    Cube *cube;

public:
    Wall();
    ~Wall();
    // Draws the cubes that are always displayed no matter the configuration
    void drawWallBase();
    // Draws the hole for the thumb or not
    void drawWallThumb(boolean is_drawn);
    // Draws the index for the thumb or not
    void drawWallIndex(boolean is_drawn);
    // Draws the hole for the middle finger or not
    void drawWallMiddleFinger(boolean middleWall_is_drawn, boolean indexWall_is_drawn, boolean ringWall_is_drawn);
    // Draws the hole for the ring finger or not
    void drawWallRingFinger(boolean is_drawn);
    // Draws the hole for the ring finger or not
    void drawWallLittleFinger(boolean littleWallis_drawn, boolean ringWall_is_drawn);
    // Draws the logo of TSE
    void drawLogo();
    // Sets the position of the wall, allowing the translation
    void setPosition(float pos);
    // Gets the position of the wall, allowing to track its progress
    float getPosition();
    // Stores the hand configuration for the wall
    bool configuration[8][5] = {
        {true, true, true, true, true},
        {false, true, true, true, true},
        {true, true, false, false, false},
        {true, true, true, false, false},
        {false, false, false, false, false},
        {false, true, true, true, false},
        {false, true, false, false, false},
        {true, true, false, false, true}
    };
};

#endif // WALL_H
