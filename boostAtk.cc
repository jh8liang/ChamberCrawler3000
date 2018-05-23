#include "boostAtk.h"
using namespace std;

class Character;

BoostAtk::BoostAtk(string type, bool perm, bool canUse, int gold, Character *d):
Item("BA", false, true, 0,nullptr)
{
    action = "PC increases attack by 5. ";
}


BoostAtk::~BoostAtk() {}

void BoostAtk::use(Character &p1)
{
    p1.setIsPotion (true);
    p1.setAtk(5);
}
