#ifndef WOUNDATK_H_INCLUDED
#define WOUNDATK_H_INCLUDED
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

class WoundAtk: public Item
{
public:
    WoundAtk(string type, bool perm, bool canUse, int gold, Character *d);
    ~WoundAtk();
    void use(Character &p1) override;
};


#endif // WOUNDATK_H_INCLUDED
