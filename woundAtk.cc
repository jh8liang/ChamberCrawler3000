#include "woundAtk.h"
using namespace std;

WoundAtk::WoundAtk(string type, bool perm, bool canUse, int gold, Character *d):
    Item("WA", false, true, 0, nullptr) {
   action = "PC decreases attack by 5. ";}

WoundAtk::~WoundAtk() {}

void WoundAtk::use(Character &p1)
{
    p1.setIsPotion(true);
    p1.setAtk(-5);
}
