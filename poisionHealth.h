#ifndef POISIONHEALTH_H_INCLUDED
#define POISIONHEALTH_H_INCLUDED
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

class PoisionHealth: public Item
{
public:
    PoisionHealth(string type, bool perm, bool canUse, int gold, Character *d);
    ~PoisionHealth();
    void use(Character &p1) override;
};


#endif // POISIONHEALTH_H_INCLUDED
