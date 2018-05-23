#ifndef DWARF_H_INCLUDED
#define DWARF_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "enemy.h"
using namespace std;


class Dwarf: public Enemy
{

public:
    Dwarf(int hp, int atk, int def, int gold, int tAtk, int tDef,
          int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile);
    ~Dwarf();
    void special() override;

};


#endif // DWARF_H_INCLUDED
