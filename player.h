#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "character.h"

class Player: public Character
{
protected:
    int maxHp;
    bool isPotion;
    float consumeRate;
public:
    Player(int hp, int atk, int def, int gold,
           int tAtk, int tDef, int lv, bool canMove,
           string type, bool killMer, int x, int y, bool isPotion, float consumeRate);
    virtual ~Player();
    void attack(Character &other) override;
    void setHp(const int hp) override;
    void setAtk(const int atk) override;
    void setDef(const int def) override;
    void setIsPotion(const bool isP) override;
    void setIsHostile(const bool isH) override;
    void addGold(const int gold) override;
    bool getIsHostile() override;
    void setDragonHoardPos (const int x, const int y) override;
    pair <int,int> getDragonHoardPos () override;
};

#endif // PLAYER_H_INCLUDED
