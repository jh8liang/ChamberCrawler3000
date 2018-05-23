#ifndef RESTOREHEALTH_H_INCLUDED
#define RESTOREHEALTH_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "item.h"
#include "player.h"
using namespace std;

class RestoreHealth: public Item
{
public:
    RestoreHealth(string type, bool perm, bool canUse, int gold, Character *d);
    ~RestoreHealth();
    void use(Character &p1) override;
};


#endif // RESTOREHEALTH_H_INCLUDED
