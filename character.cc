#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <math.h>
#include "character.h"
using namespace std;

Character::Character(int hp, int atk, int def, int gold, int tAtk, int tDef,
                     int lv, bool canMove, string type, bool killMer, int x, int y):
    hp{hp}, atk{atk}, def{def}, gold{gold}, tempAtk{tAtk}, tempDef{tDef},
    level{lv}, canMove{canMove}, type{type}, killedMerchant{killMer}, pos (x, y) {
    action = "";
    }

Character::~Character() {}

void Character::attack(Character &other) {}

void Character::special() {}

void Character::setPos(const int x, const int y)
{
    pos.first = x;
    pos.second = y;
}

bool Character::isDead()
{
    return hp <= 0;
}

int Character::getHp()
{
    return hp;
}

int Character::getActualAtk() const
{
    return atk+tempAtk;
}

int Character::getActualDef() const
{
    return def+tempDef;
}

bool Character::getCanMove()
{
    return canMove;
}

string Character::getType()
{
    return type;
}

int Character::getGold()
{
    return gold;
}

void Character ::setDragonHoardPos (const int x, const int y)
{
}

pair <int,int> Character::getDragonHoardPos () {}

pair<int, int> &Character::getPos()
{

    //cout << pos.first << " " << pos.second << endl;
    return pos;
}

void Character::reset()
{
    tempAtk = 0;
    tempDef = 0;
}

void Character::setCanMove(bool canMove)
{
    this->canMove = canMove;
}

void Character::setHp(const int hp) {}

void Character::setAtk(const int atk) {}

void Character::setDef(const int def) {}

void Character::setIsHostile(const bool isH) {}

void Character::addGold (const int gold) {}

void Character::setIsPotion(const bool isP) {}

bool Character::getIsHostile() {}

int Character::random(int min, int max)
{
    //return a random number in [min, max]
    return (rand() % (max - min + 1)) + min;
}

int Character::damage(const Character &other)
{
    int actualAtk = getActualAtk();
    int otherDef = other.getActualDef();
    if(actualAtk <= 0)
    {
        return 0;
    }
    else if(otherDef <= 0)
    {
        return actualAtk;
    }
    return ceil((float)100/(100+otherDef)) * actualAtk;
}

void Character::setAction(string &s)
{
    action = s;
}

string Character::getAction()
{
    return action;
}

