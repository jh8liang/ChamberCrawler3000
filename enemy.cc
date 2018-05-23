#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "enemy.h"
using namespace std;

Enemy::Enemy(int hp, int atk, int def, int gold, int tAtk, int tDef,
             int lv, bool canMove, string type, bool killMer, int x, int y, bool isHostile):
    Character(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y),
    isHostile{isHostile} {}

Enemy::~Enemy() {}

void Enemy::attack(Character &other)
{
    int r = random(0, 1);
    if(r == 1)
    {
        string eType = other.getType();
        int dam = damage(other);
        other.setIsPotion(false);
        string s1;
        stringstream out;
        stringstream out1;
        out << dam;
        s1 = out.str();
        // Elf case
        if(type == "Elf" && eType != "Drow")
        {
            // first attack
            other.setHp(other.getHp()-dam);
            action = "Elf deals " + s1 + " damage to PC. ";
            // second attack
            r = random(0, 1);
            if(r == 1)
            {
                dam = damage(other);
                out1 << dam;
                s1 = out1.str();
                other.setHp(other.getHp()-dam);
                action += "\nElf deals " + s1 + " damage to PC again. ";
            }
        }
        // Orcs case
        else if(type == "Orcs" && eType == "Goblin")
        {
            // does 50% more damage to goblins
            dam *= 1.5;
            other.setHp(other.getHp()-dam);
            out1 << dam;
            s1 = out1.str();
            action = "Orcs deals " + s1 + " damage to PC. ";
        }
        // other cases
        else
        {
            other.setHp(other.getHp()-dam);
            action = type + " deals " + s1 + " damage to PC. ";
        }
        /*
        cout << "Enemy is attacker" << endl;
        cout << "Enemy is attacker" << endl;
        cout << "Atk: " << getActualAtk() << endl;
        cout << "Player Type: " << eType << endl;
        cout << "Player Def: " << other.getActualDef() << endl;
        cout << "damage: " << dam << endl;
        cout << "Player HP: " << other.getHp() << endl;
        cout << "Gold: " << gold << endl;
        cout << endl;/*/
    }
}

// set hp field for Enemy
void Enemy::setHp(const int hp)
{
    //cout << "hp: " << hp << endl;
    if (hp >= 0) this->hp =hp;
    else this->hp = 0;
}

void Enemy::setAtk(const int atk) {}

void Enemy::setDef(const int def) {}

void Enemy::addGold (const int gold)
{
}

void Enemy::setIsPotion(const bool isP) {}

// set isHostile field for Enemy
void Enemy::setIsHostile(const bool isH)
{
    isHostile = isH;
}

bool Enemy::getIsHostile()
{
    return isHostile;
}

void Enemy::setDragonHoardPos (const int x, const int y) {}

pair <int,int> Enemy::getDragonHoardPos () {}
