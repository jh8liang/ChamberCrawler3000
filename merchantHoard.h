#ifndef MERCHANTHOARD_H_INCLUDED
#define MERCHANTHOARD_H_INCLUDED
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

class MerchantHoard: public Item
{

public:
    MerchantHoard(string type, bool perm, bool canUse, int gold, Character *d);
    ~MerchantHoard();
    void use(Character &p1) override;
};


#endif // MERCHANTHOARD_H_INCLUDED
