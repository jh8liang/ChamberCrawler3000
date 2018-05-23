#ifndef DRAGONHOARD_H_INCLUDED
#define DRAGONHOARD_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "item.h"
#include "dragon.h"
#include "character.h"
using namespace std;

class DragonHoard: public Item
{
    Character *protector;

public:
    DragonHoard(string type, bool perm,
                bool canUse, int gold, Character *d);
    ~DragonHoard();
    // void setProtector (Character *d);
    void use(Character &p1) override;
    bool isPlayer(Character &p1);
};


#endif // DRAGONHOARD_H_INCLUDED
