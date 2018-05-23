#include <iostream>
#include "subject.h"
using namespace std;

Subject::~Subject() {}

void Subject::attach(Observer *o)
{
    observers.push_back(o);
}

void Subject::notifyObservers()
{
    for (auto &o:observers)
    {
        o->notify(*this);
    }
}
