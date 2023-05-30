#ifndef WALL_H
#define WALL_H

#include "cube.h"
#include <GL/glu.h>
#include <QtWidgets>

class Wall {
private:
    GLfloat light_grey[3] = {0.7f, 0.7f, 0.7f};
    GLfloat grey[3] = {0.5f, 0.5f, 0.5f};
    GLfloat dark_grey[3] = {0.3f, 0.3f, 0.3f};
    GLfloat black[3] = {0.f, 0.f, 0.f};
    GLfloat blue[3] = {0.f, 0.f, 1.f};
    float *position;
public:
    Wall();
    void drawWallBase();
    void drawWallThumb(boolean is_drawn);
    void drawWallIndex(boolean is_drawn);
    void drawWallMiddleFinger(boolean middleWall_is_drawn, boolean indexWall_is_drawn, boolean ringWall_is_drawn);
    void drawWallRingFinger(boolean is_drawn);
    void drawWallLittleFinger(boolean littleWallis_drawn, boolean ringWall_is_drawn);
    void setPosition(float pos);
    float* getPosition();
    Cube cube;
};

#endif // WALL_H
