
#ifndef HAND_H
#define HAND_H

#include "cube.h"

/*
 * This class handles the modelization of the hand, given the number of fingers that must be displayed.
 *
 * @author : Matthieu d'Hoop
 */
class Hand {
private:
    GLfloat light_grey[3] = {0.7f, 0.7f, 0.7f};

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
