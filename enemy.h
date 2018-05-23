#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "character.h"

class Enemy: public Character
{
protected:
    bool isHostile;

public:
    Enemy(int hp, int atk, int def, int gold, int tAtk, int tDef,
          int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile);
    virtual ~Enemy();
    void attack(Character &other) override;
    void setHp(const int hp) override;
    void addGold (const int gold) override;
    void setAtk(const int atk) override;
    void setDef(const int def) override;
    void setIsPotion(const bool isP) override;
    void setIsHostile(const bool isH) override;
    pair <int,int> getDragonHoardPos () override;
    bool getIsHostile() override;
    void setDragonHoardPos (const int x, const int y) override;
};


#endif // ENEMY_H_INCLUDED
