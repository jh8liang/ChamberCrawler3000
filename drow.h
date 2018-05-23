#ifndef DROW_H_INCLUDED
#define DROW_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "player.h"
using namespace std;


class Drow: public Player
{

public:
    Drow(int hp, int atk, int def, int gold,
         int tAtk, int tDef, int lv, bool canMove,
         string type, bool killMer, int x, int y, bool isPotion, float consumeRate);
    ~Drow();
    void special() override;

};


#endif // DROW_H_INCLUDED
