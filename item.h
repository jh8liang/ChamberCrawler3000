#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "character.h"
#include "player.h"
#include "shade.h"
using namespace std;

//class Player;
//class Character;
class Item
{
protected:
//Character p1;
    string type;
    bool permenant;
    bool canUse;
    int gold;
    Character *protector;
    string action;
//Cell pos;

public:
    string getType();
    void setProtector (Character *d);
    bool getcanUse ();
    void setcanUse (bool u);
    Item(string type, bool perm, bool canUse, int gold, Character *d);
    virtual ~Item();
    virtual void use(Character &p1) = 0;
    void setAction(string &s);
    string getAction();
};


#endif // ITEM_H_INCLUDED
