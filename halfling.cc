#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "halfling.h"
using namespace std;

Halfling::Halfling(int hp, int atk, int def, int gold, int tAtk, int tDef,
                   int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile):
    Enemy(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y, isHostile) {}

Halfling::~Halfling() {}

void Halfling::special() {}
