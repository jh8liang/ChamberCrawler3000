#ifndef BOOSTATK_H_INCLUDED
#define BOOSTATK_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "item.h"
#include "character.h"
using namespace std;

class BoostAtk: public Item
{
public:
    BoostAtk(string type, bool perm, bool canUse, int gold, Character *d);
    ~BoostAtk();
    void use(Character &p1) override;
};


#endif // BOOSTATK_H_INCLUDED
