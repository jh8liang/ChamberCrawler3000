#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "smallTresure.h"
using namespace std;

SmallTreasure::SmallTreasure(string type, bool perm, bool canUse, int gold, Character *d):
    Item("s_g", true, true, 1, nullptr)
{
    action = "";
}

SmallTreasure::~SmallTreasure() {}

void SmallTreasure::use(Character &p1)
{
    p1.addGold(gold);
}
