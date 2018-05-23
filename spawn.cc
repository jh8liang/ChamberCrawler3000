#include <iostream>
#include "cell.h"
#include "floor.h"
#include <utility>
#include "boostAtk.h"
#include "item.h"
#include "player.h"
#include "character.h"
#include "woundAtk.h"
#include "woundDef.h"
#include "drow.h"
#include "boostDef.h"
#include "restoreHealth.h"
#include "poisionHealth.h"
#include "shade.h"
#include "vampire.h"
#include "goblin.h"
#include "enemy.h"
#include "troll.h"
#include "human.h"
#include "dragon.h"
#include "dwarf.h"
#include "elf.h"
#include "merchant.h"
#include "orcs.h"
#include "halfling.h"
#include "smallTresure.h"
#include "normalTresure.h"
#include "merchantHoard.h"
#include "dragonHoard.h"
#include "spawn.h"

using namespace std;

//likely put in floor

//player character location, stairway location,potions, gold, enemies.


void getChamberinfo(int ind, vector<int> &info)
{
    if (ind == 1) ///top left chamber
    {
        info = {3, 6, 3, 28, ind};
    }
    else if (ind == 2)    //bottom left chamber
    {
        info = {15, 21, 2, 24, ind};
    }
    else if (ind == 3)    // top right chamber
    {
        info = {3, 12, 39,75, ind};
    }
    else if (ind == 4)    //middle chamber
    {
        info = {10, 12, 38, 49, ind};
    }
    else     //bottom right chamber
    {
        info = {16, 21, 37,75, ind};
    }
}



void spawn(vector<vector <Cell>> &theChamber, vector <Enemy*> &arr1)
{
    int row;
    int col;
    vector <int> info(5); // record start row, end row, start col, end col
    int min;
    int max;
    string race;

    cout << "done initialization" << endl;
//-----------------------------------------------------------
    //spawn character
    //construct player
    min = 1;
    max = 5;
    int ind = min + rand() % ((max-min) + 1);


//what chamber it is?
// initilize r_min, r_max,c_min, c_max by the id of each chamber
    getChamberinfo(ind, info);


//	set character on the cell
    while(true)
    {
        row = info.at(0) + rand() % ((info.at(1)-info.at(0)) + 1 );
        col = info.at(2) + rand() % ((info.at(3)-info.at(2)) + 1 );

        if (info.back() == 3)
        {
            if (row >= 10 && row <= 12 && col >= 38 && col <= 49)
            {
                continue;
            }
            else
            {
                break;

            }
        }
    }

    cout << "already set character pos" << endl;
//generate character
    Character *p1;
    while(cin>>race)
    {
        if(race == "s")
        {
            p1 = new Shade {125,25,25,0,0,0,1,true,"Shade",false,row,col,false,1.0};
            break;
        }
        else if (race == "d")
        {
            p1 = new Drow {150,25,15,0,0,0,1,true,"Drow",false,row,col,false,1.5};
            break;
        }
        else if (race == "v")
        {
            p1 = new Vampire {50,25,25,0,0,0,1,true,"Vampire",false,row,col,false,1.0};
            break;
        }
        else if (race == "t")
        {
            p1 = new Troll {120,25,15,0,0,0,1,true,"Troll",false,row,col,false,1.0};
            break;
        }
        else if (race == "g")
        {
            p1 = new Goblin {110,15,20,0,0,0,1,true,"Goblin",false,row,col,false,1.0};
            break;
        }
        else if (race == "q")
        {
            return;
        }
        else
        {
            cin.ignore();
            cin.clear();
        }
    }



    theChamber[row][col].enterChar(p1);
    p1 = nullptr;

    cout << "already put character on the spot" <<endl;
//------------------------------------------------------------

//------------------------------------------------------------
//spwan stair
    ind = min + rand() % ((max-min) + 1);
    getChamberinfo(ind, info);

    while (true)
    {
        row = info.at(0) + rand() % ((info.at(1)-info.at(0)) + 1 );
        col = info.at(2) + rand() % ((info.at(3)-info.at(2)) + 1 );

        if (info.back() == 3 )
        {
            if (row >= 10 && row <= 12 && col >= 38 && col <= 49)
            {
                continue;
            }
            else
            {
                if (theChamber[row][col].occupied() == false)
                {
                    theChamber[row][col].setType('s');
                    break;
                }
            }
        }
    }


    cout << "already placed stairs" <<endl;

// how do i know if this is a stair; like how to get to next stair
    // cell need to modify when player walk on a stair
    // when ppl walk in passage, the player wont be displayed

//------------------------------------------------------------

//-----------------------------------------------------------
//spawn potion
    min = 1;
    max = 5;
    int num_potion = 10;
    for (int i = 0; i < num_potion; ++i)
    {
        ind = min + rand() % ((max-min) + 1);
        getChamberinfo(ind, info);

//place potion
        while (true)
        {
            row = info.at(0) + rand() % ((info.at(1)-info.at(0)) + 1 );
            col = info.at(2) + rand() % ((info.at(3)-info.at(2)) + 1 );
            if (theChamber[row][col].occupied() == false)
            {
                break;
            }

        }

        cout << "already get no " << i << "position for potion" << endl;

        //decide what type of potion it is
        min = 1;
        max = 6;
        int potion = min + rand() % ((max-min) + 1);

        if (potion == 1)
        {
            RestoreHealth *ra = new RestoreHealth{"RA",true,true,0,nullptr};
            theChamber [row][col].addItem (ra);
            ra = nullptr;
        }
        else if (potion == 2)
        {
            BoostAtk *ba = new BoostAtk {"BA",false,true,0,nullptr};
            theChamber [row][col].addItem (ba);
            ba = nullptr;
        }
        else if (potion == 3)
        {
            BoostDef *bd = new BoostDef {"BD",false, true,0,nullptr};
            theChamber [row][col].addItem (bd);
            bd = nullptr;
        }
        else if (potion == 4)
        {
            PoisionHealth *ph = new PoisionHealth{"PH",true,true,0,nullptr};
            theChamber [row][col].addItem (ph);
            ph = nullptr;
        }
        else if (potion == 5)
        {
            WoundAtk *wa = new WoundAtk {"WA",false,true,0,nullptr};
            theChamber [row][col].addItem (wa);
            wa = nullptr;
        }
        else
        {
            WoundDef *wd = new WoundDef{"WD",false,true,0,nullptr};
            theChamber [row][col].addItem (wd);
            wd = nullptr;

        }
        cout << "already put no " << i << "potion" << endl;

    }



//--------------------------------------------------------------
//--------------------------------------------------------------

    //spawn gold

    min = 1;
    max = 5;
    int num_gold = 10;
    bool is_dragon_h = false;
    pair<int, int> single_pos;
    vector <pair<int, int >> dragon_h_pos;

    for (int i = 0; i < num_gold; ++i)
    {
        ind = min + rand() % ((max-min) + 1);
        getChamberinfo(ind, info);


        //generate position;

        while (true)
        {
            row = info.at(0) + rand() % ((info.at(1)-info.at(0)) + 1 );
            col = info.at(2) + rand() % ((info.at(3)-info.at(2)) + 1 );

            if (info.back() == 3)
            {
                if (row >= 10 && row <= 12 && col >= 38 && col <= 49)
                {
                    continue;
                }
                else
                {
                    if (theChamber[row][col].occupied() == false)
                    {
                        // NEED TO CHANGE HERE!!
                        break;
                    }
                }

            }
        }

        cout << "already get no " << i << "gold's location" <<endl;
        //generate what type of gold
        min = 1;
        max = 8;
        int gold = min + rand() % ((max-min) + 1);
        if (gold == 1)
        {
            DragonHoard *dh = new DragonHoard{"dragon_g",true,false,6,nullptr};
            theChamber [row][col].addItem(dh);
            theChamber [row][col].setGold (6);
            is_dragon_h = true;
            single_pos.first = row;
            single_pos.second = col;
            dragon_h_pos.push_back(single_pos);
            dh = nullptr;

        }
        else if (gold > 1 && gold < 7)
        {
            NormalTresure *nt = new NormalTresure{"n_t",true,true,2,nullptr};
            theChamber [row][col].addItem (nt);
            theChamber [row][col].setGold (2);
            nt = nullptr;

        }
        else
        {
            SmallTreasure *st = new SmallTreasure{"s_t",true,true,1,nullptr};
            theChamber [row][col].addItem (st);
            theChamber [row][col].setGold (1);
            st = nullptr;
        }

        cout << "already placed no " << i << " gold" << endl;

    }
//-------------------------------------------------------

    //spawn enemy
    min = 1;
    max = 5;
    int num_enemy = 20;
    for (int i = 0; i < num_enemy; ++i)
    {
        ind = min + rand() % ((max-min) + 1);
        getChamberinfo(ind, info);


        //generate position for enemy

        while (true)
        {
            row = info.at(0) + rand() % ((info.at(1)-info.at(0)) + 1 );
            col = info.at(2) + rand() % ((info.at(3)-info.at(2)) + 1 );

            if (info.back() == 3 )
            {
                if (row >= 10 && row <= 12 && col >= 38 && col <= 49)
                {
                    continue;
                }
                else
                {
                    if (theChamber[row][col].occupied() == false)
                    {
                        break;
                    }
                }
            }
        }


        cout << "already get no " << i << " enemy's pos" << endl;
        // need to spawn dragon here~
        min = 0;
        max = 17;
        int result = min + rand() % ((max-min) + 1 );
        if (result >= 0 && result < 4)
        {
            Human *h = new Human{140, 20,20,0,0,0,1,true,"Human",false,row,i,true};
            theChamber [row][col].enterChar(h);
            arr1.emplace_back(h);
            h = nullptr;
        }
        else if(result >= 4 && result < 7 )
        {
            Dwarf *dw = new Dwarf {100,20,30,0,0,0,1,true,"Dwarf",false,row,i,true};
            theChamber [row][col].enterChar (dw);
            arr1.emplace_back(dw);
            dw = nullptr;
        }
        else if (result >= 7 && result < 12)
        {
            Elf *el = new Elf {140,30,10,0,0,0,1,true,"Elf",false,row,i,true};
            theChamber [row][col].enterChar (el);
            arr1.emplace_back(el);
            el = nullptr;
        }
        else if (result >= 12 && result < 14)
        {
            Orcs *o = new Orcs{180,30,25,0,0,0,1,true,"Orc",false,row,i,true};
            theChamber[row][col].enterChar (o);
            arr1.emplace_back(o);
            o = nullptr;
        }
        else if (result >= 14 && result < 16)
        {
            Halfling *ha = new Halfling {100,15,20,0,0,0,1,true,"Halfling",false,row,i,true};
            theChamber [row][col].enterChar (ha);
            arr1.emplace_back(ha);
            ha = nullptr;
        }
        else
        {
            Merchant *mer = new Merchant {30,70,5,0,0,0,1,true,"Merchant",false,row,i,false};
            theChamber[row][col].enterChar (mer);
            arr1.emplace_back(mer);
            mer = nullptr;
        }

        cout << "already placed no " << i << "enemy" << endl;
    }

    if (is_dragon_h)
    {
        for (auto it = dragon_h_pos.begin(); it!=dragon_h_pos.end(); it++)
        {
            min = 0;
            max = 7;
            ind = min + rand() % ((max-min) + 1);
            while (true)
            {
                if (ind == 0)
                {
                    row += 1;
                    col += 1;
                }
                else if (ind == 1)
                {
                    row -= 1;
                    col -= 1;
                }
                else if (ind == 2)
                {
                    row += 1;
                    col -= 1;
                }
                else if (ind == 3)
                {
                    row -= 1;
                    col += 1;
                }
                else if (ind == 4)
                {
                    row += 1;
                }
                else if (ind == 5)
                {
                    row -= 1;
                }
                else if (ind == 6)
                {
                    col += 1;
                }
                else
                {
                    col -= 1;
                }

                if(theChamber[row][col].occupied() == false)
                {
                    break;
                }

            }

            Dragon *dra = new Dragon{150,20,20,0,0,0,1,false,"Dragon",false,row,col,true};
            theChamber[row][col].enterChar(dra);
            arr1.emplace_back(dra);
            dra = nullptr;
            cout << "already create dragon" << endl;
        }
    }



}
//-----------------------------------------------------
