#ifndef PASSAGE_H_INCLUDED
#define PASSAGE_H_INCLUDED
#include "cell.h"

class Passage: public Cell
{
    Passage(char s, bool canEnt, bool isO, bool isG,
            Item &i, Character &p, int x, int y);
    ~Passage();

};


#endif // PASSAGE_H_INCLUDED
