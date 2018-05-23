#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include "chamber.h"
using namespace std;

Chamber::Chamber(int id, bool win): Floor(id, win) {}

Chamber::~Chamber() {}

void Chamber::addCharacter(char c)
{

}

void Chamber::replace(Cell &c)
{

}

