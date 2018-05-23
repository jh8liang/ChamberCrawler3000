#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED
#include "cell.h"

class Door: public Cell
{
    Door(char s, bool canEnt, bool isO, bool isG,
         Item &i, Character &p, int x, int y);
    ~Door();

};


#endif // DOOR_H_INCLUDED
