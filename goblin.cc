#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "goblin.h"
using namespace std;

Goblin::Goblin(int hp, int atk, int def, int gold, int tAtk, int tDef, int lv,
               bool canMove, string type, bool killMer, int x, int y, bool isPotion, float consumeRate):
    Player(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y, isPotion, consumeRate) {}

Goblin::~Goblin() {}

void Goblin::special() {}
