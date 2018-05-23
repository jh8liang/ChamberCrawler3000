#ifndef BOOSTDEF_H_INCLUDED
#define BOOSTDEF_H_INCLUDED
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

class BoostDef: public Item
{
public:
    BoostDef(string type, bool perm, bool canUse, int gold, Character* d);
    ~BoostDef();
    void use(Character &p1) override;
};


#endif // BOOSTDEF_H_INCLUDED
