#include "cell.h"
#include <string>
#include <iostream>
#include <utility>
#include "character.h"
#include "item.h"
using namespace std;


Cell::Cell (char symbol, bool canEnter, bool isOccupied, bool isGold, int goldvalue,
            Item *toitem, Character *toCharacter, int x, int y):
    symbol{symbol}, canEnter{canEnter}, isOccupied{isOccupied}, toItem{toitem}, toCharacter{toCharacter},pos (x,y)
{
    bool has_gold = false;
    bool has_potion = false;
    bool is_player = false;
    bool is_enemy = false;
    cellInfo = Info{pos.first, pos.second, has_potion, has_gold, is_enemy, is_player, nullptr, nullptr};
}

Cell:: ~Cell () {}

void Cell:: reItem ()
{
    canEnter = true;
    toItem = nullptr;
    cellInfo.has_potion = false;
    cellInfo.has_gold = false;
    cellInfo.toItem = nullptr;
}

void Cell:: addItem (Item *t)
{
    canEnter = false;
    this->toItem = t;
    if (toItem->getType() == "BD" || "RH" || "BH" || "PH" ||"WA" || "WD")
    {
        cellInfo.has_potion = true;
        canEnter = false;
    }
    else
    {
        cellInfo.has_gold = true;
        canEnter = true;
    }
    cellInfo.toItem = t;
    notifyObservers();
}

Item* Cell:: getItem ()
{
    return this->toItem;
}

Character* Cell:: getCharacter ()
{
    return this->toCharacter;
}

void Cell::cprint ()
{
    if (symbol == 'v')
    {
        cout << "|";
    }
    else if (symbol == 'h')
    {
        cout << "-";
    }
    else if (symbol == 'e')
    {
        cout << " ";
    }
    else if (symbol == 's')
    {
        cout << "\\";
    }
    /*else if (symbol == 't') {
            cout << ".";
      } */
    else if (toCharacter != nullptr)
    {
        string ctype = toCharacter->getType ();
        if (ctype == "Shade"|| ctype =="Drow"||ctype =="Vampire" || ctype == "Troll" ||ctype == "Goblin")
        {
            cout << "@";
        }
        else if (ctype =="Human")
        {
            cout << "H";
        }
        else if (ctype =="Dwarf")
        {
            cout << "W";
        }
        else if (ctype =="Elf")
        {
            cout << "E";
        }
        else if (ctype =="Orc")
        {
            cout << "O";
        }
        else if (ctype == "Halfling")
        {
            cout << "L";
        }
        else if (ctype =="Merchant")
        {
            cout << "M";
        }
        else //if (ctype =="Dragon")
        {
            cout << "D";
        }
    }
    else if (toItem != nullptr)
    {
        string itype = toItem->getType();
        if (itype == "s_g"||itype =="dragon_g"||itype == "n_g"||itype == "mechant_g")
        {
            cout << "G";
        }
        else
        {
            cout << "P";
        }
    }
    else if (symbol == 'd')
    {
        cout << "+";
    }
    else if (symbol == 'p')
    {
        cout << "#";
    }
    else
    {
        cout <<".";
    }
//incomplete print method, characters and items are missing
}

void Cell::setType (char type)
{
    this->symbol = type;
}

pair<int, int> Cell:: getPos ()
{
    return pos;
}

void Cell::setGold (int val)
{
    this->isGold = true;
    this->goldvalue = val;
    this->canEnter = true;
}

void Cell:: enterChar (Character *c)
{
    canEnter = false;
    toCharacter = c;
    cellInfo.toCharacter= c;
    string ctype = toCharacter->getType();
    //  cout << "Player Type: " << ctype << endl;
    if (ctype == "Shade"|| ctype =="Drow"
            ||ctype =="Vampire" || ctype == "Troll" ||ctype == "Goblin")
    {
        //cout << "been here " << "my pos is " << pos.first << pos.second<< endl;
        cellInfo.is_player = true;
        if (cellInfo.has_gold)
        {
            toItem->use(*c);
        }
    }
    else
    {
        cellInfo.is_enemy = true;
    }
    if (pos.first == 3 && pos.second == 10)
    {
        if (toCharacter == nullptr)
        {
            //cout << "No player" <<endl;
        }
        else
        {
            //cout << "player here" <<endl;
        }
    }
}

void Cell:: leaveChar ()
{
    canEnter = true;
    toCharacter = nullptr;
    cellInfo.is_enemy = false;
    cellInfo.is_player = false;
    cellInfo.toCharacter = nullptr;
}

bool Cell::getisGold ()
{
    return isGold;
}

void Cell::retrieveGold (Character *p1)
{
    if (toItem != nullptr) {
    bool temp = toItem->getcanUse();
    if (temp)
    {
        p1->addGold(goldvalue);
        //delete (toItem);
        reItem ();
        isGold = false;
        goldvalue = 0;
    }
    }
}

bool Cell::occupied ()
{
    return !(this->canEnter);
}

char Cell::getSymbol()
{
    return symbol;
}

void Cell::notify(Subject &s)
{
    // si is other
    Info si = s.getInfo();
    /*
        cout << "im notified" <<endl;
        cout << "row " <<cellInfo.row <<"\ncol " << cellInfo.col << endl;
        cout << "is player " << si.is_player <<endl;
        cout << "enmey " << si.is_enemy <<endl;
        cout << "potion " << si.has_potion << endl;
        cout <<  endl;

    */
    /*   if (pos.first == 3 && pos.second == 10){
           if (toCharacter == nullptr){
               cout << "No player" <<endl;
           } else {
               cout << "player here" <<endl;
           }
       }
    //*/


    if (si.is_player && cellInfo.is_enemy)
    {
        //cout << "encounter enemy" << endl;
        //enemy attack here;
        if (toCharacter->getIsHostile())
        {
            cellInfo.toCharacter->attack(*(si.toCharacter));
            throw (cellInfo.toCharacter -> getAction ());
        }
    }
    if (si.is_player && cellInfo.has_potion)
    {
        //notify player there is a potion
        string s = "and sees an unknown potion. ";
        throw s;
        //cout << "sees an unknown potion." << endl;
    }
}


Info Cell::getInfo() const
{
    return cellInfo;
}

