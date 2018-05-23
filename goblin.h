#ifndef GOBLIN_H_INCLUDED
#define GOBLIN_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "player.h"
using namespace std;


class Goblin: public Player
{

public:
    Goblin(int hp, int atk, int def, int gold,
           int tAtk, int tDef, int lv, bool canMove,
           string type, bool killMer, int x, int y, bool isPotion, float consumeRate);
    ~Goblin();
    void special() override;

};


#endif // GOBLIN_H_INCLUDED
