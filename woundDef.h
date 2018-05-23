#ifndef WOUNDDEF_H_INCLUDED
#define WOUNDDEF_H_INCLUDED
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

class WoundDef: public Item
{
public:
    WoundDef(string type, bool perm, bool canUse, int gold, Character* d);
    ~WoundDef();
    void use(Character &p1) override;
};


#endif // WOUNDDEF_H_INCLUDED
