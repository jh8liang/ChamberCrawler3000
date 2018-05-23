#ifndef VAMPIRE_H_INCLUDED
#define VAMPIRE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "player.h"
using namespace std;


class Vampire: public Player
{

public:
    Vampire(int hp, int atk, int def, int gold,
            int tAtk, int tDef, int lv, bool canMove,
            string type, bool killMer, int x, int y, bool isPotion, float consumeRate);
    ~Vampire();
    void special() override;

};


#endif // VAMPIRE_H_INCLUDED
