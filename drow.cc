#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "drow.h"
using namespace std;

Drow::Drow(int hp, int atk, int def, int gold, int tAtk, int tDef, int lv,
           bool canMove, string type, bool killMer, int x, int y, bool isPotion, float consumeRate):
    Player(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y, isPotion, consumeRate) {}

Drow::~Drow() {}

void Drow::special() {}
// all potions have their effect magnified by 1.5
