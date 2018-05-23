#ifndef CHAMBER_H_INCLUDED
#define CHAMBER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "floor.h"
#include "cell.h"
using namespace std;

class Chamber: public Floor
{
    vector<vector<Cell*>> theChamber;

public:
    Chamber(int id, bool win);
    ~Chamber();
    void addCharacter(char c);
    void replace(Cell &c);


};


#endif // CHAMBER_H_INCLUDED
