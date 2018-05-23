#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "enemy.h"
using namespace std;


class Human: public Enemy
{

public:
    Human(int hp, int atk, int def, int gold, int tAtk, int tDef,
          int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile);
    ~Human();
    void special() override;

};


#endif // HUMAN_H_INCLUDED
