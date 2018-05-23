#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "shade.h"
using namespace std;

Shade::Shade(int hp, int atk, int def, int gold, int tAtk, int tDef, int lv,
             bool canMove, string type, bool killMer, int x, int y, bool isPotion, float consumeRate):
    Player(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y, isPotion, consumeRate) {}

Shade::~Shade() {}

void Shade::special() {}
