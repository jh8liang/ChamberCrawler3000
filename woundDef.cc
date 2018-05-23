#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "woundDef.h"
#include "player.h"
using namespace std;

WoundDef::WoundDef(string type, bool perm, bool canUse, int gold, Character *d):
    Item("WD", false, true, 0, nullptr)
{
    action = "PC decreases defense by 5. ";
}

WoundDef::~WoundDef() {}

void WoundDef::use(Character &p1)
{
    p1.setIsPotion (true);
    p1.setDef(-5);
}
