#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "normalTresure.h"
#include "player.h"
using namespace std;

NormalTresure::NormalTresure(string type, bool perm, bool canUse, int gold, Character *d):
    Item("n_g", true, true, 2, nullptr)
{
    action = "";
}

NormalTresure::~NormalTresure() {}

void NormalTresure::use(Character &p1)
{
    p1.addGold(gold);
}
