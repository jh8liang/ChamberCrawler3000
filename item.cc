#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "item.h"
using namespace std;

Item::Item(string type, bool perm, bool canUse, int gold,Character *d):
    type{type}, permenant{perm}, canUse{canUse}, gold{gold}, protector{d}
{
    action = "";
}

Item::~Item() {}

void Item::use(Character &p1) {}

string Item::getType()
{
    return type;
}

void Item::setcanUse (bool u)
{
    canUse = u;
}

bool Item::getcanUse ()
{
    return canUse;
}

void Item::setProtector (Character *d)
{
    this->protector = d;
}

void Item::setAction(string &s)
{
    action = s;
}

string Item::getAction()
{
    return action;
}
