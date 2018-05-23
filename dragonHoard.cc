#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "dragonHoard.h"
using namespace std;

DragonHoard::DragonHoard(string type, bool perm, bool canUse, int gold, Character *d):
    Item("dragon_g", true, false, 6, nullptr) {
    action = "";
    }

DragonHoard::~DragonHoard() {}

void DragonHoard::use(Character &p1)
{
    if (protector->getHp() == 0)
    {
        canUse = true;
        p1.addGold(gold);
    }
}

/*DragonHoard::setProtector (Character *d) {
	this->protector = d;
}*/
