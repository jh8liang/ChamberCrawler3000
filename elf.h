#ifndef ELF_H_INCLUDED
#define ELF_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "enemy.h"
using namespace std;


class Elf: public Enemy
{

public:
    Elf(int hp, int atk, int def, int gold, int tAtk, int tDef,
        int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile);
    ~Elf();
    void special() override;

};


#endif // ELF_H_INCLUDED
