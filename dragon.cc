#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "dragon.h"
using namespace std;

Dragon::Dragon(int hp, int atk, int def, int gold, int tAtk, int tDef,
               int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile):
    Enemy(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y, isHostile) {}

Dragon::~Dragon() {}

void Dragon::setDragonHoardPos (const int x, const int y)
{
    dhPos.first = x;
    dhPos.second = y;
}

pair<int, int> Dragon::getDragonHoardPos()
{
    return dhPos;
}

void Dragon::special() {}
