#ifndef ORC_H_INCLUDED
#define ORC_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "enemy.h"
using namespace std;


class Orcs: public Enemy
{

public:
    Orcs(int hp, int atk, int def, int gold, int tAtk, int tDef,
         int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile);
    ~Orcs();
    void special() override;

};


#endif // ORC_H_INCLUDED
