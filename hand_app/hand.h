
#ifndef HAND_H
#define HAND_H

#include "cube.h"

class Hand {
private:

public:
    Hand();
    void Display();
    void drawBase();
    void drawThumb();
    void drawIndex();
    void drawMiddleFinger();
    void drawRingFinger();
    void drawLittleFinger();
    Cube cube;
};

#endif // HAND_H
