#ifndef TROLL_H_INCLUDED
#define TROLL_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "player.h"
using namespace std;


class Troll: public Player
{

public:
    Troll(int hp, int atk, int def, int gold,
          int tAtk, int tDef, int lv, bool canMove,
          string type, bool killMer, int x, int y, bool isPotion, float consumeRate);
    ~Troll();
    void special() override;

};


#endif // TROLL_H_INCLUDED
