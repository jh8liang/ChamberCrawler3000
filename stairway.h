#ifndef STAIRWAY_H_INCLUDED
#define STAIRWAY_H_INCLUDED
#include "cell.h"

class Stairway: public Cell
{
    Stairway(char s, bool canEnt, bool isO, bool isG,
             Item &i, Character &p, int x, int y);
    ~Stairway();

};


#endif // STAIRWAY_H_INCLUDED
