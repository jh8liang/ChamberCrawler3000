#ifndef HALFLING_H_INCLUDED
#define HALFLING_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "enemy.h"
using namespace std;


class Halfling: public Enemy
{

public:
    Halfling(int hp, int atk, int def, int gold, int tAtk, int tDef,
             int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile);
    ~Halfling();
    void special() override;

};


#endif // HALFLING_H_INCLUDED
