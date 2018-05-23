#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "poisionHealth.h"
#include "player.h"
using namespace std;

PoisionHealth::PoisionHealth(string type, bool perm, bool canUse, int gold, Character *d):
    Item("PH", true, true, 0, nullptr)
{
    action = "PC decreases health by 10. ";
}

PoisionHealth::~PoisionHealth() {}

void PoisionHealth::use(Character &p1)
{
    p1.setIsPotion(true);
    p1.setHp(p1.getHp()-10);
}
