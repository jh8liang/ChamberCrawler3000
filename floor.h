#ifndef _FLOOR_H
#define _FLOOR_H
#include <string>
#include <vector>
#include "cell.h"
#include "character.h"
#include "subject.h"

class Floor
{
    int level;
    bool win;
//  bool isfile;
// string filename;
    vector <int> numChamber;
public:
    vector <vector <Cell>> theChamber;
    Floor (int level, bool win);
    void print ();
    //bool isWin (Character *c);
    void PlacePlayer ();
    void move(Character *c, Cell &cell);
    ~Floor ();
};

#endif
