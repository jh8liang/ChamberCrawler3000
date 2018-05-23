#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "subject.h"
#include "observer.h"
//#include "character.h"
//#include "item.h"
//#include "chamber.h"
using namespace std;
class Item;
class Character;

class Cell : public Subject, public Observer
{
    char symbol;
    bool canEnter;
    bool isOccupied;
    bool isGold;
    int goldvalue;
    Item *toItem;
    Character *toCharacter;
    pair<int, int> pos;
    //whether this is observed
    Info cellInfo;

public:
    Cell(char s, bool canEnt, bool isO, bool isG, int goldvalue,
         Item *i, Character *p, int x, int y);
    ~Cell();
    void reItem();
    Item* getItem ();
    Character* getCharacter ();
    void addItem(Item *i);
    void cprint ();
    void setGold (int val);
    bool getisGold ();
    void retrieveGold (Character *p1);
    //move(Character &p);
    pair<int, int> getPos();
    void enterChar(Character *c);
    void setType (char type);
    void leaveChar();
    bool occupied();
    char getSymbol();
    void notify(Subject &whoNotifyMe) override;
    Info getInfo() const override;

};


#endif // CELL_H_INCLUDED
