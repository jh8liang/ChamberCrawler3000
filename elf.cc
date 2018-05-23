#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "elf.h"
using namespace std;

Elf::Elf(int hp, int atk, int def, int gold, int tAtk, int tDef,
         int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile):
    Enemy(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y, isHostile) {}

Elf::~Elf() {}

void Elf::special() {}
