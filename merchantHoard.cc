#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "merchantHoard.h"
using namespace std;

MerchantHoard::MerchantHoard(string type, bool perm, bool canUse, int gold, Character *d):
    Item("mechant_g", true, true, 4, nullptr)
{
    action = "";
}

MerchantHoard::~MerchantHoard() {}

void MerchantHoard::use(Character &p1)
{
    p1.addGold(gold);
}
