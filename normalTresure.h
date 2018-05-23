#ifndef NORMALTRESURE_H_INCLUDED
#define NORMALTRESURE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "item.h"
using namespace std;

class NormalTresure: public Item
{
public:
    NormalTresure(string type, bool perm, bool canUse, int gold, Character *d);
    ~NormalTresure();
    void use(Character &p1) override;
};


#endif // NORMALTRESURE_H_INCLUDED
