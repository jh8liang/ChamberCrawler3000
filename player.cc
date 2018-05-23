#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "player.h"

using namespace std;

Player::Player(int hp, int atk, int def, int gold,
               int tAtk, int tDef, int lv, bool canMove,
               string type, bool killMer, int x, int y, bool isPotion, float consumeRate):
    Character(hp, atk, def, gold, tAtk, tDef, lv, canMove, type, killMer, x, y),
    maxHp{hp}, isPotion{isPotion}, consumeRate{consumeRate} {}

Player::~Player() {}

void Player::attack(Character &other)
{
    string eType = other.getType();
    int dam = damage(other);
    string s1;
    string s2;
    stringstream out;
    stringstream out1;
    out << dam;
    s1 = out.str();
    out1 << other.getHp();
    s2 = out1.str();
    // 50% chance to cause the player character to miss
    if(eType == "Halfling")
    {
        int r = random(0, 1);
        if(r == 1)
        {
            other.setHp(other.getHp()-dam);
            // Vampire case
            if (type == "Vampire")
            {
                hp+=5;
                action = "PC deals " + s1 + " damages to Halfling"
                         + " (" + s2 + " HP) and regains 5 HP. ";
            }
            // Goblin case
            else if (type == "Goblin" && other.isDead())
            {
                gold += 5;
                action = "PC deals " + s1 + " damages to Halfling"
                         + " (" + s2 + " HP) and steals 5 Gold. ";
            }
            else
            {
                action = "PC deals " + s1 + " damages to Halfling (" + s2 + " HP). ";
            }
        }
        else
        {
            action = "PC miss an attack on Halfling. ";
        }
    }

    else
    {
        other.setHp(other.getHp()-dam);
        other.setIsHostile(true);
        // Vampire case
        if(type == "Vampire")
        {
            // Vampires are allergic to dwarves and lose 5HP
            if(eType == "Dwarf")
            {
                hp-=5;
                action = "PC deals " + s1 + " damages to Dwarf"
                         + " (" + s2 + " HP) and loses 5 HP. ";
            }
            else
            {
                hp+=5;
                action = "PC deals " + s1 + " damages to " + other.getType()
                         + " (" + s2 + " HP) and regains 5 HP. ";
            }

        }
        // Goblin case
        else if(type == "Goblin" && other.isDead())
        {
            gold+=5;
            action = "PC deals " + s1 + " damages to " + other.getType()
                     + " (" + s2 + " HP) and steals 5 HP. ";
        }
        else
        {
            action = "PC deals " + s1 + " damages to " + other.getType()
                     + " (" + s2 + " HP). ";
        }

    }

    /*
    cout << "Player is attacker" << endl;
    cout << "Player Atk: " << getActualAtk() << endl;
    cout << "Type: " << eType << endl;
    cout << "Enemy Def: " << other.getActualDef() << endl;
    cout << "damage: " << dam << endl;
    cout << "Enemy HP: " << other.getHp() << endl;
    cout << "Gold: " << gold << endl;
    cout << endl;/*/
}

// set hp field for Player
void Player::setHp(const int hp)
{
    int adjusted = hp - this->hp;
    if(isPotion) adjusted *= consumeRate;

    if (adjusted < 0)
    {
        (this->hp + adjusted) < 0 ? this->hp = 0 : this->hp += adjusted;
    }
    else if(type != "Vampire")
    {
        hp > maxHp ? this->hp = maxHp : this->hp += adjusted;
    }
    else
    {
        this->hp += adjusted;
    }
}

// set atk field for Player
void Player::setAtk(const int atk)
{
    tempAtk += atk*consumeRate;
}

// set def field for Player
void Player::setDef(const int def)
{
    tempDef += def*consumeRate;
}

// set isPotion field for Player
void Player::setIsPotion(const bool isP)
{
    isPotion = isP;
}

void Player::setIsHostile(const bool isH) {}

void Player::addGold(const int gold)
{
    this->gold += gold;
}

bool Player::getIsHostile() {}

void Player::setDragonHoardPos (const int x, const int y) {}

pair <int,int> Player::getDragonHoardPos () {}



