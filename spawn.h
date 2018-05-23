#ifndef SPAWN_H_INCLUDED
#define SPAWN_H_INCLUDED
#include <vector>
#include <stdlib.h>
#include <utility>
#include <string>
#include <random>
#include <map>
#include "cell.h"
#include "floor.h"
using namespace std;


void spawn(vector<vector <Cell>> &theChamber, vector <Enemy *> &arr1);


#endif // SPAWN_H_INCLUDED
