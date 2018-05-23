#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "troll.h"
using namespace std;

Troll::Troll(int hp, int atk, int def, int gold, int tAtk, int tDef, int lv,
             bool canMove, string type, bool killMer, int x, int y, bool isPotion, float consumeRate):
    Player(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y, isPotion, consumeRate) {}

Troll::~Troll() {}

void Troll::special()
{
    //gain hp every turn
    hp += 5;
    if(hp >= maxHp) hp = maxHp;
}

