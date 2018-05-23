#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include "cell.h"

class Wall: public Cell
{
    Wall(char s, bool canEnt, bool isO, bool isG,
         Item &i, Character &p, int x, int y);
    ~Wall();

};

#endif // WALL_H_INCLUDED
