#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
//#include "item.h"
using namespace std;

//class Cell;

class Character
{
protected:
    int hp;
    int atk;
    int def;
    int gold;
    int tempAtk;
    int tempDef;
    int level;
    bool canMove;
    string type;
    bool killedMerchant;
    pair<int, int> pos;
    string action;

public:
    Character(int hp, int atk, int def, int gold, int tAtk, int tDef,
              int lv, bool canMove, string type, bool killMer, int x, int y);
    virtual ~Character();
    virtual void attack(Character &other) = 0;
    virtual void special() = 0;
    bool isDead();
    int getHp();
    void setPos(const int x, const int y);
    int getActualAtk() const;
    int getActualDef() const;
    int getGold();
    bool getCanMove();
    string getType();
    pair<int, int> &getPos();
    void reset();
    void setCanMove(bool canMove);
    virtual void setHp(const int hp) = 0;
    virtual void setAtk(const int atk) = 0;
    virtual void setDef(const int def) = 0;
    virtual void setIsHostile(const bool isH) = 0;
    virtual void addGold(const int gold);
    virtual void setIsPotion(const bool isP) = 0;
    virtual void setDragonHoardPos (const int x, const int y) = 0;
    virtual pair <int,int> getDragonHoardPos () =0;
    virtual bool getIsHostile() = 0;
    int random(int min, int max);
    int damage(const Character &other);
    void setAction(string &s);
    string getAction();
};




#endif // CHARACTER_H_INCLUDED
