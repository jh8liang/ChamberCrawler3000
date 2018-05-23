#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "dwarf.h"
using namespace std;

Dwarf::Dwarf(int hp, int atk, int def, int gold, int tAtk, int tDef,
             int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile):
    Enemy(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y, isHostile) {}

Dwarf::~Dwarf() {}

void Dwarf::special() {}
