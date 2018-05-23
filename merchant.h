#ifndef MERCHANT_H_INCLUDED
#define MERCHANT_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "enemy.h"
using namespace std;


class Merchant: public Enemy
{

public:
    Merchant(int hp, int atk, int def, int gold, int tAtk, int tDef,
             int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile);
    ~Merchant();
    void special() override;

};


#endif // MERCHANT_H_INCLUDED
