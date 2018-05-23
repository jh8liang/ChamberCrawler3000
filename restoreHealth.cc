#include "restoreHealth.h"
using namespace std;

RestoreHealth::RestoreHealth(string type, bool perm, bool canUse, int gold, Character *d):
    Item("RH", true, true, 0, nullptr)
{
    action = "PC increases health by 10. ";
}


RestoreHealth::~RestoreHealth() {}

void RestoreHealth::use(Character &p1)
{
    p1.setIsPotion (true);
    p1.setHp(p1.getHp()+10);
}
