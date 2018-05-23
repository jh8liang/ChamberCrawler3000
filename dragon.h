#ifndef DRAGON_H_INCLUDED
#define DRAGON_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "enemy.h"
using namespace std;


class Dragon: public Enemy
{
    pair<int, int> dhPos;

public:
    Dragon(int hp, int atk, int def, int gold, int tAtk, int tDef,
           int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile);
    ~Dragon();
    void special() override;
    void setDragonHoardPos (const int x, const int y) override;
    pair <int,int> getDragonHoardPos () override;
};


#endif // DRAGON_H_INCLUDED
