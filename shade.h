#ifndef SHADE_H_INCLUDED
#define SHADE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "player.h"
using namespace std;


class Shade: public Player
{

public:
    Shade(int hp, int atk, int def, int gold,
          int tAtk, int tDef, int lv, bool canMove,
          string type, bool killMer, int x, int y, bool isPotion, float consumeRate);
    ~Shade();
    void special() override;

};


#endif // SHADE_H_INCLUDED
