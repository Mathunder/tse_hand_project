#ifndef CUBE_H
#define CUBE_H

#include <GL/gl.h>

class Cube {
private:
    GLfloat light_grey[3] = {0.7f, 0.7f, 0.7f};
    GLfloat grey[3] = {0.5f, 0.5f, 0.5f};
    GLfloat dark_grey[3] = {0.3f, 0.3f, 0.3f};
    GLfloat black[3] = {0.f, 0.f, 0.f};
    GLfloat blue[3] = {0.f, 0.f, 1.f};
public:
    Cube();

    void drawCube(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z, GLfloat color[]);
};

#endif // CUBE_H
