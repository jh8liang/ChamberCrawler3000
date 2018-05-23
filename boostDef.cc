#include "boostDef.h"

using namespace std;

BoostDef::BoostDef(string type, bool perm, bool canUse, int gold, Character *d):
    Item("BD", false, true, 0, nullptr)
{
    action = "PC increases defense by 5. ";
}



BoostDef::~BoostDef() {}

void BoostDef::use(Character &p1)
{
    p1.setIsPotion (true);
    p1.setDef(5);
}
