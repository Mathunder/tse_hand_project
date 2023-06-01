
#ifndef HAND_H
#define HAND_H

#include "cube.h"

class Hand {
private:
    GLfloat light_grey[3] = {0.7f, 0.7f, 0.7f};
//    GLfloat black[3] = {0.f, 0.f, 0.f};

public:
    Hand();
    ~Hand();
    void Display();
    void drawBase();
    void drawThumb(boolean is_drawn);
    void drawIndex(boolean is_drawn);
    void drawMiddleFinger(boolean is_drawn);
    void drawRingFinger(boolean is_drawn);
    void drawLittleFinger(boolean is_drawn);
    void setColor(GLfloat col[3]);
    Cube *cube;
    GLfloat color[3];
};

#endif // HAND_H
