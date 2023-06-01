
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
    // Constructor
    Hand();
    // Destructor
    ~Hand();
    // Draws the base oh the hand (the cubes that are always displayed no matter the configuration)
    void drawBase();
    // Draws the thumb (always called so a boolean is given as an argument)
    void drawThumb(boolean is_drawn);
    // Draws the index (always called so a boolean is given as an argument)
    void drawIndex(boolean is_drawn);
    // Draws the middle finger (always called so a boolean is given as an argument)
    void drawMiddleFinger(boolean is_drawn);
    // Draws the ring finger (always called so a boolean is given as an argument)
    void drawRingFinger(boolean is_drawn);
    // Draws the little finger (always called so a boolean is given as an argument)
    void drawLittleFinger(boolean is_drawn);
    // Sets the color of the back of the hand
    void setColor(GLfloat col[3]);
    Cube *cube;
    GLfloat color[3];
};

#endif // HAND_H
