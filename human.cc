#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "human.h"
using namespace std;

Human::Human(int hp, int atk, int def, int gold, int tAtk, int tDef,
             int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile):
    Enemy(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y, isHostile) {}

Human::~Human() {}

void Human::special() {}
// drops 2 normal piles of gold

