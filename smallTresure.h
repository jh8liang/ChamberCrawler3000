#ifndef SMALLTRESURE_H_INCLUDED
#define SMALLTRESURE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "item.h"
#include "player.h"
using namespace std;

class SmallTreasure: public Item
{
public:
    SmallTreasure(string type, bool perm, bool canUse, int gold, Character *d);
    ~SmallTreasure();
    void use(Character &p1) override;
};


#endif // SMALLTRESURE_H_INCLUDED
