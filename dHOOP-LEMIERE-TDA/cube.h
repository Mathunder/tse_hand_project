#ifndef CUBE_H
#define CUBE_H

#include <GL/gl.h>
#include <QtWidgets>

/*
 * This class handles the creation and display of a cube, given its position and/or its color.
 *
 * @author : Matthieu d'Hoop
 * @co-author : Alban Lemière
 */
class Cube {
private:
    GLfloat light_grey[3] = {0.7f, 0.7f, 0.7f};
    GLfloat grey[3] = {0.5f, 0.5f, 0.5f};
    GLfloat dark_grey[3] = {0.3f, 0.3f, 0.3f};
    GLfloat black[3] = {0.f, 0.f, 0.f};
    GLfloat blue[3] = {0.f, 0.f, 1.f};
    float depth;
public:
    // Constructor
    Cube(float depth);
    // Destructor
    ~Cube();
    // Draws a colored cube at the given coordinates
    void drawCube(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z, GLfloat color[]);
    // Draws a cube that will be textured at the given coordinates
    void drawCube(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z);
    // Draws a cube with the TSE logo on it at the given coordinates
    void drawCubeTextureLogo(float bottom_left_corner_x, float bottom_left_corner_y, float bottom_left_corner_z, GLuint texture);
};

#endif // CUBE_H
