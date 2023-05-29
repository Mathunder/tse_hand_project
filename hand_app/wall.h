#ifndef WALL_H
#define WALL_H

#include "cube.h"
#include <GL/glu.h>
#include <QtWidgets>

class Wall {
private:

public:
    Wall();
    void drawWallBase(boolean is_drawn);
    void drawWallThumb(boolean is_drawn);
    void drawWallIndex(boolean is_drawn);
    void drawWallMiddleFinger(boolean middleWall_is_drawn, boolean indexWall_is_drawn, boolean ringWall_is_drawn);
    void drawWallRingFinger(boolean is_drawn);
    void drawWallLittleFinger(boolean littleWallis_drawn, boolean ringWall_is_drawn);
    Cube cube;
};

#endif // WALL_H
