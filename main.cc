#include <string>
#include <iostream>
#include "cell.h"
#include "floor.h"
#include <vector>
#include <utility>
#include "boostAtk.h"
#include <stdlib.h>
#include "item.h"
#include "player.h"
#include "character.h"
#include <iostream>
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
//#include "spawn.h"



int main (int argc, char *argv [])
{
    bool merchantHostile = false;
    int level = 0;
    int bausage = 0;
    int bdusage = 0;
    int wausage = 0;
    int wdusage = 0;
    int rhusage = 0;
    int phusage = 0;
    int count = 0;
    string action;
    int Health;
    int Def;
    int Atk;
    string Race;
    Character *p1;
    vector <Enemy*> arr1;
    vector <Item*> arr2;
    string filename;
    string fname = "";

    int num = argc -1;
    if (num != 0)
    {
        filename = argv[1];
        //init (argc,argv[1],arr1,arr2,p1,f);
        fname = filename;

//Floor f (1,false);
    }

    ifstream file {fname};

    while (true)
    {
        if (level == 5)
        {
            string s1;
            int g = p1->getGold();
            if(p1->getType() == "Shade") g*=1.5;
            cout << "Congratulations, you win. Your scores: " << g << endl;
            cout << "Enter your command:" << endl;
            cin >> s1;
            while (true)
            {
                if (s1 == "q")
                {
                    delete (p1);
                    p1 = nullptr;
                    for (vector<Enemy*>::iterator obj = arr1.begin();
                            obj != arr1.end(); ++obj)
                    {
                        delete *obj; // deleting what obj points to, which is a pointer
                    }
                    arr1.clear();
                    for (vector<Item*>::iterator obj = arr2.begin();
                            obj != arr2.end(); ++obj)
                    {
                        delete *obj; // deleting what obj points to, which is a pointer
                    }
                    arr2.clear();
                    return 0;
                }
                else if (s1 == "r")
                {
                    level = 0;
                    delete (p1);
                    p1 = nullptr;
                    count = 0;
                    merchantHostile = false;
                    break;
                }
                else
                {
                    cout <<"Invalid Command." << endl;
                }

            }
        }
        string race;
        bool invalid = false;
        bool freeze = false;
        //= nullptr;
        Floor f (level,false);
        if (num == 0)
        {
            // call randomly generate map (spawn)
            // spawn(f.theChamber, arr1);
            f.print ();
        }
        else
        {
            string c;
            int row = 0;
            //int count = 0+level*25;
// int column = 0;
            while (count < (25+(level*25)))
            {
                getline(file, c);

                for (int i = 0; i < 79; ++i)
                {
                    if (c[i] == '@')
                    {
                        if (level == 0)
                        {
                            while (true)
                            {
                                cout << "Please select a race: "<< endl;
                                if (cin >> race)
                                {
                                    if (race == "s")
                                    {
                                        p1 = new Shade {125,25,25,0,0,0,1,true,"Shade",false,row,i,false,1.0};
                                        break;
                                    }
                                    else if (race == "d")
                                    {
                                        p1 = new Drow {150,25,15,0,0,0,1,true,"Drow",false,row,i,false,1.5};
                                        //cout << row << " "<< i << endl;
                                        break;
                                    }
                                    else if (race == "v")
                                    {
                                        p1 = new Vampire {50,25,25,0,0,0,1,true,"Vampire",false,row,i,false,1.0};
                                        break;
                                    }
                                    else if (race == "t")
                                    {
                                        p1 = new Troll {120,25,15,0,0,0,1,true,"Troll",false,row,i,false,1.0};
                                        break;
                                    }
                                    else if (race == "g")
                                    {
                                        p1 = new Goblin {110,15,20,0,0,0,1,true,"Goblin",false,row,i,false,1.0};
                                        break;
                                    }
                                    else if (race == "q")
                                    {
                                        return 0;
                                    }
                                    else
                                    {
                                        cin.ignore ();
                                        cin.clear ();
                                    }
                                }
                            }
                        }

                        //cout << row << " " << i <<endl;
                        p1->setPos(row,i);

                        f.theChamber [row][i].enterChar (p1);
                        //p1 = nullptr;
                    }
                    else if (c[i] == '\\')
                    {
                        f.theChamber [row][i].setType ('s');
                    }
                    else if (c[i] == '0')
                    {

                        // create RH potion on heap
                        RestoreHealth *ra = new RestoreHealth{"RA",true,true,0,nullptr};
                        f.theChamber [row][i].addItem (ra);
                        arr2.emplace_back(ra);
                        ra = nullptr;
                    }
                    else if (c[i] == '1')
                    {
                        BoostAtk *ba = new BoostAtk {"BA",false,true,0,nullptr};
                        //create BA potion on heap
                        f.theChamber [row][i].addItem (ba);
                        arr2.emplace_back(ba);
                        ba = nullptr;
                    }
                    else if (c[i] == '2')
                    {
                        BoostDef *bd = new BoostDef {"BD",false, true,0, nullptr};
                        //create BD potion on heap
                        f.theChamber [row][i].addItem (bd);
                        arr2.emplace_back(bd);
                        bd = nullptr;
                    }
                    else if (c[i] == '3')
                    {
                        PoisionHealth *ph = new PoisionHealth{"PH",true,true,0, nullptr};
                        //create PH potion on heap
                        f.theChamber [row][i].addItem (ph);
                        arr2.emplace_back(ph);
                        ph = nullptr;
                    }
                    else if (c[i] == '4')
                    {
                        WoundAtk *wa = new WoundAtk {"WA",false,true,0, nullptr};
                        //create WA potion on heap
                        f.theChamber [row][i].addItem (wa);
                        arr2.emplace_back(wa);
                        wa = nullptr;
                    }
                    else if (c[i] == '5')
                    {
                        WoundDef *wd = new WoundDef{"WD",false,true,0, nullptr};
                        //create WD potion on heap
                        f.theChamber [row][i].addItem (wd);
                        arr2.emplace_back(wd);
                        wd = nullptr;
                    }
                    else if (c[i] == '6')
                    {
                        NormalTresure *nt = new NormalTresure{"n_t",true,true,2, nullptr};
                        //create normal gold pile on heap
                        f.theChamber [row][i].addItem (nt);
                        arr2.emplace_back(nt);
                        f.theChamber [row][i].setGold (2);
                    }
                    else if (c[i] == '7')
                    {
                        SmallTreasure *st = new SmallTreasure{"s_t",true,true,1,nullptr};
                        //create small gold pile on heap
                        f.theChamber [row][i].addItem (st);
                        arr2.emplace_back(st);
                        f.theChamber [row][i].setGold (1);
                        st = nullptr;
                    }
                    else if (c[i] == '8')
                    {
                        MerchantHoard *mg = new MerchantHoard {"merchant_g",true,false,4,nullptr};
                        f.theChamber [row][i].addItem(mg);
                        arr2.emplace_back(mg);
                        //create merchant gold pile on heap
                        f.theChamber [row][i].setGold (4);
                        mg = nullptr;
                    }
                    else if (c[i] == '9')
                    {
                        DragonHoard *dh = new DragonHoard{"dragon_g",true,false,6,nullptr};
                        //create dragon gold pile on heap
                        f.theChamber [row][i].addItem(dh);
                        f.theChamber [row][i].setGold (6);
                        arr2.emplace_back(dh);
                        dh = nullptr;
                    }
                    else if (c[i] == 'H')
                    {
                        Human *h = new Human{140, 20,20,0,0,0,1,true,"Human",false,row,i,true};
                        f.theChamber [row][i].enterChar(h);
                        arr1.emplace_back(h);
                        h = nullptr;
                    }
                    else if (c[i] == 'W')
                    {
                        Dwarf *dw = new Dwarf {100,20,30,0,0,0,1,true,"Dwarf",false,row,i,true};
                        f.theChamber [row][i].enterChar (dw);
                        arr1.emplace_back(dw);
                        dw = nullptr;
                    }
                    else if (c[i] == 'E')
                    {
                        Elf *el = new Elf {140,30,10,0,0,0,1,true,"Elf",false,row,i,true};
                        f.theChamber [row][i].enterChar (el);
                        arr1.emplace_back(el);
                        el = nullptr;
                    }
                    else if (c[i] == 'O')
                    {
                        Orcs *o = new Orcs{180,30,25,0,0,0,1,true,"Orc",false,row,i,true};
                        f.theChamber[row][i].enterChar (o);
                        arr1.emplace_back(o);
                        o = nullptr;
                    }
                    else if (c[i] == 'L')
                    {
                        Halfling *ha = new Halfling {100,15,20,0,0,0,1,true,"Halfling",false,row,i,true};
                        f.theChamber [row][i].enterChar (ha);
                        arr1.emplace_back(ha);
                        ha = nullptr;
                    }
                    else if (c[i] == 'M')
                    {
                        Merchant *mer = new Merchant {30,70,5,0,0,0,1,true,"Merchant",false,row,i,merchantHostile};
                        f.theChamber[row][i].enterChar (mer);
                        arr1.emplace_back(mer);
                        mer = nullptr;
                    }
                    else if (c[i] == 'D')
                    {
                        Dragon *dra = new Dragon{150,20,20,0,0,0,1,false,"Dragon",false,row,i,true};
                        f.theChamber[row][i].enterChar(dra);
                        arr1.emplace_back(dra);
                        dra = nullptr;
                    }

                }
                row += 1;
                count += 1;
            }
            Health = p1->getHp ();
            Def = p1->getActualDef ();
            Atk = p1->getActualAtk ();
            Race = p1->getType ();

            //cout << "search dragon"<< endl;
            for (int i = 0; i < 25; ++i)
            {
                for (int j = 0; j < 79; ++j)
                {
                    Character *c = f.theChamber[i][j].getCharacter ();
                    if (c != nullptr)
                    {
                        string t = c->getType ();
                        if (t=="Dragon")
                        {
                            //int row = c->getPos().first;
                            //int col = c->getPos().second;
                            //find the 8 adjecet cells for dragon hoard
                            Item *i1 = f.theChamber [i+1][j].getItem ();
                            Item *i2 = f.theChamber [i][j+1].getItem ();
                            Item *i3 = f.theChamber [i-1][j].getItem();
                            Item *i4 = f.theChamber [i][j-1].getItem ();
                            Item *i5 = f.theChamber [i-1][j+1].getItem ();
                            Item *i6 = f.theChamber [i+1][j+1].getItem ();
                            Item *i7 = f.theChamber [i-1][j-1].getItem ();
                            Item *i8 = f.theChamber [i+1][j-1].getItem ();
                            if (i1 != nullptr)
                            {
                                if (i1->getType () == "dragon_g")
                                {
                                    i1->setProtector (c);
                                    c->setDragonHoardPos((i+1), j);
                                }
                            }
                            else if (i2 != nullptr)
                            {
                                if (i2->getType () == "dragon_g")
                                {

                                    i2->setProtector (c);
                                    c->setDragonHoardPos(i, j+1);
                                }
                            }
                            else if (i3 != nullptr)
                            {
                                if (i3->getType () == "dragon_g")
                                {
                                    i3->setProtector (c);
                                    c->setDragonHoardPos(i-1, j);
                                }
                            }
                            else if (i4 != nullptr)
                            {
                                if (i4->getType () == "dragon_g")
                                {
                                    i4->setProtector (c);
                                    c->setDragonHoardPos((i), j-1);
                                }
                            }
                            else if (i5 != nullptr)
                            {
                                if (i5->getType () == "dragon_g")
                                {
                                    i5->setProtector (c);
                                    c->setDragonHoardPos((i-1), j+1);
                                }
                            }
                            else if (i6 != nullptr)
                            {
                                if (i6->getType () == "dragon_g")
                                {
                                    i6->setProtector (c);
                                    c->setDragonHoardPos((i+1), j+1);
                                }
                            }
                            else if (i7 != nullptr)
                            {
                                if (i7->getType () == "dragon_g")
                                {
                                    i7->setProtector (c);
                                    c->setDragonHoardPos((i-1), j-1);
                                }
                            }
                            else if (i8 != nullptr)
                            {
                                if (i8->getType () == "dragon_g")
                                {
                                    i8->setProtector (c);
                                    c->setDragonHoardPos((i+1), j-1);
                                }
                            }
                        }
                    }
                }
            }
            f.print();
            cout << "Race" << ": " << Race << " " << "Gold: " << p1->getGold () << "                                                    Floor: "<< level+1 <<endl;
            cout <<  "HP: " << Health << endl;
            cout << "Atk: " << Atk << endl;
            cout << "Def: " << Def << endl;
            cout << "Action: Player character has spawned." << endl;
        }

        //cout << p1->getType() << endl;
//finished initialization



        pair <int, int> pos = p1->getPos ();
//cout << p1->getType() << endl;
        //cout << p1->getPos ().first << " " << p1->getPos ().second << endl;
        bool pickGold;
        while (true)
        {
            string command;
            cout << "Please Enter a command: " << endl;
            cin >> command;
            pickGold = f.theChamber[pos.first][pos.second].getisGold ();
            if (pickGold)
            {
                f.theChamber[pos.first][pos.second].retrieveGold (p1);
            }

            if (command == "so")
            {
                pos = p1->getPos();
                cout << pos.first << " " << pos.second << endl;
                if (!f.theChamber [pos.first+1][pos.second].occupied ())
                {
                    f.theChamber[pos.first][pos.second].leaveChar ();
                    pos.first += 1;
                    p1->setPos (pos.first,pos.second);
                    f.theChamber[pos.first][pos.second].enterChar (p1);
                    action += "PC moves South ";
                }
                else
                {
                    action += "Unable to move to Cell " ;
                }
            }
            else if (command == "no")
            {
                if (!f.theChamber [pos.first-1][pos.second].occupied ())
                {
                    pos = p1->getPos();
                    f.theChamber[pos.first][pos.second].leaveChar ();
                    pos.first -= 1;
                    p1->setPos (pos.first,pos.second);
                    f.theChamber[pos.first][pos.second].enterChar (p1);
                    action += "PC moves North ";
                }
                else
                {
                    action += "Unable to move to Cell " ;
                }
            }
            else if (command == "ea")
            {
                if (!f.theChamber [pos.first][pos.second+1].occupied ())
                {
                    pos = p1->getPos();
                    f.theChamber[pos.first][pos.second].leaveChar ();
                    pos.second += 1;
                    p1->setPos (pos.first,pos.second);
                    //cout << p1->getPos().first << " " << p1->getPos().second << endl;
                    f.theChamber[pos.first][pos.second].enterChar (p1);
                    action += "PC moves East ";
                }
                else
                {
                    action += "Unable to move to Cell ";
                }

            }
            else if (command == "we")
            {
                if (!f.theChamber [pos.first][pos.second-1].occupied ())
                {
                    pos = p1->getPos();
                    f.theChamber[pos.first][pos.second].leaveChar ();
                    pos.second -= 1;
                    p1->setPos (pos.first,pos.second);
                    f.theChamber[pos.first][pos.second].enterChar (p1);
                    action += "PC moves West ";
                }
                else
                {
                    action += "Unable to move to Cell " ;
                }

            }
            else if (command == "ne")
            {
                if (!f.theChamber [pos.first-1][pos.second+1].occupied ())
                {
                    pos = p1->getPos();
                    f.theChamber[pos.first][pos.second].leaveChar ();
                    pos.second += 1;
                    pos.first -= 1;
                    p1->setPos (pos.first,pos.second);
                    f.theChamber[pos.first][pos.second].enterChar (p1);
                    action += "PC moves North East ";
                }
                else
                {
                    action += "The cell is occupied " ;
                }

            }
            else if (command == "nw")
            {
                if (!f.theChamber [pos.first-1][pos.second-1].occupied ())
                {
                    pos = p1->getPos();
                    f.theChamber[pos.first][pos.second].leaveChar ();
                    pos.second -= 1;
                    pos.first -= 1;
                    p1->setPos (pos.first,pos.second);
                    f.theChamber[pos.first][pos.second].enterChar (p1);
                    action += "PC moves North West ";
                }
                else
                {
                    action += "Unable to move to Cell " ;
                }
            }
            else if (command == "se")
            {
                if (!f.theChamber [pos.first+1][pos.second+1].occupied ())
                {
                    pos = p1->getPos();
                    f.theChamber[pos.first][pos.second].leaveChar ();
                    pos.second += 1;
                    pos.first += 1;
                    p1->setPos (pos.first,pos.second);
                    f.theChamber[pos.first][pos.second].enterChar (p1);
                    action += "PC moves South East ";
                }
                else
                {
                    action += "Unable to move to Cell " ;
                }
            }
            else if (command == "sw")
            {
                if (!f.theChamber [pos.first+1][pos.second-1].occupied ())
                {
                    pos = p1->getPos();
                    f.theChamber[pos.first][pos.second].leaveChar ();
                    pos.second -= 1;
                    pos.first += 1;
                    p1->setPos (pos.first,pos.second);
                    f.theChamber[pos.first][pos.second].enterChar (p1);
                    action += "PC moves South West ";
                }
                else
                {
                    action += "Invalid Direction " ;
                }
            }
            else if (command == "u")
            {
                cin >> command;
                if (command == "no")
                {
                    Item * it = f.theChamber [pos.first-1] [pos.second].getItem ();
                    if (it == nullptr)
                    {
                        action += "There is no potion for use. " ;
                    }
                    else if (it->getType () == "s_t" ||it->getType () == "n_t" || it->getType () == "dragon_g" ||it->getType () == "merchant_g")
                    {
                        action += "There is no potion for use. " ;
                    }
                    else
                    {
                        it->use (*p1);
                        string type = it->getType ();
                        if ( bausage == 0 && type =="BA")
                        {
                            action += "PC uses "+ type+ " ";
                            bausage += 1;
                        }
                        else if (bdusage == 0 && type =="BD")
                        {
                            action += "PC uses "+ type+ " ";
                            bdusage += 1;
                        }
                        else if (wdusage == 0 && type =="WD")
                        {
                            action += "PC uses "+ type+ " ";
                            wdusage += 1;
                        }
                        else if (wausage == 0 && type =="WA")
                        {
                            action += "PC uses "+ type+ " ";
                            wausage += 1;
                        }
                        else if (rhusage == 0 && type =="RH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else if (phusage == 0 && type =="PH")
                        {
                            action += "PC uses "+ type + " ";
                            rhusage += 1;
                        }
                        else
                        {
                            action += it->getAction ();

                        }
                        pos = p1->getPos();
                        f.theChamber[pos.first][pos.second].leaveChar ();
                        pos.first -= 1;
                        f.theChamber [pos.first][pos.second].reItem ();
                        p1->setPos (pos.first,pos.second);
                        f.theChamber[pos.first][pos.second].enterChar (p1);
                    }
                }
                else if (command == "so")
                {

                    Item * it = f.theChamber [pos.first+1] [pos.second].getItem ();
                    if (it == nullptr)
                    {
                        action += "There is no potion for use. " ;
                    }
                    else if (it->getType () == "s_t" ||it->getType () == "n_t" || it->getType () == "dragon_g" ||it->getType () == "merchant_g")
                    {
                        action += "There is no potion for use. " ;
                    }
                    else
                    {
                        it->use (*p1);
                        string type = it->getType ();
                        if ( bausage == 0 && type =="BA")
                        {
                            action += "PC uses "+ type+ " ";
                            bausage += 1;
                        }
                        else if (bdusage == 0 && type =="BD")
                        {
                            action += "PC uses "+ type+ " ";
                            bdusage += 1;
                        }
                        else if (wdusage == 0 && type =="WD")
                        {
                            action += "PC uses "+ type+ " ";
                            wdusage += 1;
                        }
                        else if (wausage == 0 && type =="WA")
                        {
                            action += "PC uses "+ type+ " ";
                            wausage += 1;
                        }
                        else if (rhusage == 0 && type =="RH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else if (phusage == 0 && type =="PH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else
                        {
                            action += it->getAction ();

                        }
                        pos = p1->getPos();
                        f.theChamber[pos.first][pos.second].leaveChar ();
                        pos.first += 1;
                        p1->setPos (pos.first,pos.second);
                        f.theChamber [pos.first][pos.second].reItem ();
                        f.theChamber[pos.first][pos.second].enterChar (p1);
                    }
                }
                else if (command == "ea")
                {
                    Item * it = f.theChamber [pos.first][pos.second+1].getItem ();
                    if (it == nullptr)
                    {
                        action += "There is no potion for use. " ;
                    }
                    else if (it->getType () == "s_t" ||it->getType () == "n_t" || it->getType () == "dragon_g" ||it->getType () == "merchant_g")
                    {
                        action += "There is no potion for use. " ;
                    }
                    else
                    {
                        it->use (*p1);
                        string type = it->getType ();
                        if ( bausage == 0 && type =="BA")
                        {
                            action += "PC uses "+ type+ " ";
                            bausage += 1;
                        }
                        else if (bdusage == 0 && type =="BD")
                        {
                            action += "PC uses "+ type+ " ";
                            bdusage += 1;
                        }
                        else if (wdusage == 0 && type =="WD")
                        {
                            action += "PC uses "+ type+ " ";
                            wdusage += 1;
                        }
                        else if (wausage == 0 && type =="WA")
                        {
                            action += "PC uses "+ type+ " ";
                            wausage += 1;
                        }
                        else if (rhusage == 0 && type =="RH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else if (phusage == 0 && type =="PH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else
                        {
                            action += it->getAction ();

                        }
                        pos = p1->getPos();
                        f.theChamber[pos.first][pos.second].leaveChar ();
                        pos.second += 1;
                        p1->setPos (pos.first,pos.second);
                        f.theChamber [pos.first][pos.second].reItem ();
                        f.theChamber[pos.first][pos.second].enterChar (p1);
                    }

                }
                else if (command == "we")
                {
                    Item * it = f.theChamber [pos.first][pos.second-1].getItem ();
                    if (it == nullptr)
                    {
                        action += "There is no potion for use. " ;
                    }
                    else if (it->getType () == "s_t" ||it->getType () == "n_t" || it->getType () == "dragon_g" ||it->getType () == "merchant_g")
                    {
                        action += "There is no potion for use. " ;
                    }
                    else
                    {
                        it->use (*p1);
                        string type = it->getType ();
                        if ( bausage == 0 && type =="BA")
                        {
                            action += "PC uses "+ type+ " ";
                            bausage += 1;
                        }
                        else if (bdusage == 0 && type =="BD")
                        {
                            action += "PC uses "+ type+ " ";
                            bdusage += 1;
                        }
                        else if (wdusage == 0 && type =="WD")
                        {
                            action += "PC uses "+ type+ " ";
                            wdusage += 1;
                        }
                        else if (wausage == 0 && type =="WA")
                        {
                            action += "PC uses "+ type+ " ";
                            wausage += 1;
                        }
                        else if (rhusage == 0 && type =="RH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else if (phusage == 0 && type =="PH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else
                        {
                            action += it->getAction ();

                        }
                        pos = p1->getPos();
                        f.theChamber[pos.first][pos.second].leaveChar ();
                        pos.second -= 1;
                        p1->setPos (pos.first,pos.second);
                        f.theChamber [pos.first][pos.second].reItem ();
                        f.theChamber[pos.first][pos.second].enterChar (p1);
                    }

                }
                else if (command == "ne")
                {

                    Item * it = f.theChamber [pos.first-1][pos.second+1].getItem ();
                    if (it == nullptr)
                    {
                        action += "There is no potion for use. " ;
                    }
                    else if (it->getType () == "s_t" ||it->getType () == "n_t" || it->getType () == "dragon_g" ||it->getType () == "merchant_g")
                    {
                        action += "There is no potion for use. " ;
                    }
                    else
                    {
                        it->use (*p1);
                        string type = it->getType ();
                        if ( bausage == 0 && type =="BA")
                        {
                            action += "PC uses "+ type+ " ";
                            bausage += 1;
                        }
                        else if (bdusage == 0 && type =="BD")
                        {
                            action += "PC uses "+ type+ " ";
                            bdusage += 1;
                        }
                        else if (wdusage == 0 && type =="WD")
                        {
                            action += "PC uses "+ type+ " ";
                            wdusage += 1;
                        }
                        else if (wausage == 0 && type =="WA")
                        {
                            action += "PC uses "+ type+ " ";
                            wausage += 1;
                        }
                        else if (rhusage == 0 && type =="RH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else if (phusage == 0 && type =="PH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else
                        {
                            action += it->getAction ();

                        }
                        pos = p1->getPos();
                        f.theChamber[pos.first][pos.second].leaveChar ();
                        pos.first -= 1;
                        pos.second += 1;
                        p1->setPos (pos.first,pos.second);
                        f.theChamber [pos.first][pos.second].reItem ();
                        f.theChamber[pos.first][pos.second].enterChar (p1);
                    }

                }
                else if (command == "nw")
                {
                    Item * it = f.theChamber [pos.first-1][pos.second-1].getItem ();
                    if (it == nullptr)
                    {
                        action += "There is no potion for use. " ;
                    }
                    else if (it->getType () == "s_t" ||it->getType () == "n_t" || it->getType () == "dragon_g" ||it->getType () == "merchant_g")
                    {
                        action += "There is no potion for use. " ;
                    }
                    else
                    {
                        it->use (*p1);
                        string type = it->getType ();
                        if ( bausage == 0 && type =="BA")
                        {
                            action += "PC uses "+ type+ " ";
                            bausage += 1;
                        }
                        else if (bdusage == 0 && type =="BD")
                        {
                            action += "PC uses "+ type+ " ";
                            bdusage += 1;
                        }
                        else if (wdusage == 0 && type =="WD")
                        {
                            action += "PC uses "+ type+ " ";
                            wdusage += 1;
                        }
                        else if (wausage == 0 && type =="WA")
                        {
                            action += "PC uses "+ type+ " ";
                            wausage += 1;
                        }
                        else if (rhusage == 0 && type =="RH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else if (phusage == 0 && type =="PH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else
                        {
                            action += it->getAction ();

                        }
                        pos = p1->getPos();
                        f.theChamber[pos.first][pos.second].leaveChar ();
                        pos.second -= 1;
                        pos.first -= 1;
                        p1->setPos (pos.first,pos.second);
                        f.theChamber [pos.first][pos.second].reItem ();
                        f.theChamber[pos.first][pos.second].enterChar (p1);
                    }

                }
                else if (command == "se")
                {
                    Item * it = f.theChamber [pos.first+1][pos.second+1].getItem ();
                    if (it == nullptr)
                    {
                        action += "There is no potion for use. " ;
                    }
                    else if (it->getType () == "s_t" ||it->getType () == "n_t" || it->getType () == "dragon_g" ||it->getType () == "merchant_g")
                    {
                        action += "There is no potion for use. " ;
                    }
                    else
                    {
                        it->use (*p1);
                        string type = it->getType ();
                        if ( bausage == 0 && type =="BA")
                        {
                            action += "PC uses "+ type+ " ";
                            bausage += 1;
                        }
                        else if (bdusage == 0 && type =="BD")
                        {
                            action += "PC uses "+ type+ " ";
                            bdusage += 1;
                        }
                        else if (wdusage == 0 && type =="WD")
                        {
                            action += "PC uses "+ type+ " ";
                            wdusage += 1;
                        }
                        else if (wausage == 0 && type =="WA")
                        {
                            action += "PC uses "+ type+ " ";
                            wausage += 1;
                        }
                        else if (rhusage == 0 && type =="RH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else if (phusage == 0 && type =="PH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else
                        {
                            action += it->getAction ();

                        }
                        pos = p1->getPos();
                        f.theChamber[pos.first][pos.second].leaveChar ();
                        pos.first += 1;
                        pos.second += 1;
                        p1->setPos (pos.first,pos.second);
                        f.theChamber [pos.first][pos.second].reItem ();
                        f.theChamber[pos.first][pos.second].enterChar (p1);
                    }

                }
                else if (command == "sw")
                {
                    Item * it = f.theChamber [pos.first+1][pos.second-1].getItem ();
                    if (it == nullptr)
                    {
                        action += "There is no potion for use. " ;
                    }
                    else if (it->getType () == "s_t" ||it->getType () == "n_t" || it->getType () == "dragon_g" ||it->getType () == "merchant_g")
                    {
                        action += "There is no potion for use. " ;
                    }
                    else
                    {
                        it->use (*p1);
                        string type = it->getType ();
                        if ( bausage == 0 && type =="BA")
                        {
                            action += "PC uses "+ type+ " ";
                            bausage += 1;
                        }
                        else if (bdusage == 0 && type =="BD")
                        {
                            action += "PC uses "+ type+ " ";
                            bdusage += 1;
                        }
                        else if (wdusage == 0 && type =="WD")
                        {
                            action += "PC uses "+ type+ " ";
                            wdusage += 1;
                        }
                        else if (wausage == 0 && type =="WA")
                        {
                            action += "PC uses "+ type+ " ";
                            wausage += 1;
                        }
                        else if (rhusage == 0 && type =="RH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else if (phusage == 0 && type =="PH")
                        {
                            action += "PC uses "+ type+ " ";
                            rhusage += 1;
                        }
                        else
                        {
                            action += it->getAction ();

                        }
                        pos = p1->getPos();
                        f.theChamber[pos.first][pos.second].leaveChar ();
                        pos.second -= 1;
                        pos.first += 1;
                        p1->setPos (pos.first,pos.second);
                        f.theChamber [pos.first][pos.second].reItem ();
                        f.theChamber[pos.first][pos.second].enterChar (p1);
                    }

                }
                else
                {
                    action += "Invalid direction. " ;
                }
            }
            else if (command == "a")
            {
                cin >> command;
                if (command == "no")
                {
                    Character *e = f.theChamber [pos.first-1][pos.second].getCharacter ();
                    if (e==nullptr)
                    {
                        action += "There is no enemy in sight " ;
                    }
                    else
                    {
                        p1->attack(*e);
                        action += p1->getAction();
                    }
                }
                else if (command == "so")
                {
                    Character *e = f.theChamber [pos.first+1][pos.second].getCharacter ();
                    if (e==nullptr)
                    {
                        action += "There is no enemy in sight " ;
                    }
                    else
                    {
                        p1->attack(*e);
                        action += p1->getAction();
                    }
                }
                else if (command == "ea")
                {
                    Character *e = f.theChamber [pos.first][pos.second+1].getCharacter ();
                    if (e==nullptr)
                    {
                        action += "There is no enemy in sight " ;
                    }
                    else
                    {
                        p1->attack(*e);
                        action += p1->getAction();
                    }
                }
                else if (command == "we")
                {
                    Character *e = f.theChamber [pos.first][pos.second-1].getCharacter ();
                    if (e==nullptr)
                    {
                        action += "There is no enemy in sight " ;
                    }
                    else
                    {
                        p1->attack(*e);
                        action += p1->getAction();
                    }
                }
                else if (command == "ne")
                {
                    Character *e = f.theChamber [pos.first-1][pos.second+1].getCharacter ();
                    if (e==nullptr)
                    {
                        action += "There is no enemy in sight " ;
                    }
                    else
                    {
                        p1->attack(*e);
                        action += p1->getAction();
                    }
                }
                else if (command == "nw")
                {
                    Character *e = f.theChamber [pos.first-1][pos.second-1].getCharacter ();
                    if (e==nullptr)
                    {
                        action += "There is no enemy in sight " ;
                    }
                    else
                    {
                        p1->attack(*e);
                        action += p1->getAction();
                    }
                }
                else if (command == "se")
                {
                    Character *e = f.theChamber [pos.first+1][pos.second+1].getCharacter ();
                    if (e==nullptr)
                    {
                        action += "There is no enemy in sight " ;
                    }
                    else
                    {
                        p1->attack(*e);
                        action += p1->getAction();
                    }
                }
                else if (command == "sw")
                {
                    Character *e = f.theChamber [pos.first+1][pos.second-1].getCharacter ();
                    if (e==nullptr)
                    {
                        action += "There is no enemy in sight " ;
                    }
                    else
                    {
                        p1->attack(*e);
                        action += p1->getAction();
                    }
                }
                else
                {
                    action += "Invalid direction. " ;
                }

            }
            else if (command == "f")
            {
                if (freeze == false)
                {
                    freeze= true;
                }
                else
                {
                    freeze = false;
                }
            }
            else if (command == "q")
            {
                delete (p1);
                p1 = nullptr;
                for (vector<Enemy*>::iterator obj = arr1.begin();
                        obj != arr1.end(); ++obj)
                {
                    delete *obj; // deleting what obj points to, which is a pointer
                }
                arr1.clear();
                for (vector<Item*>::iterator obj = arr2.begin();
                        obj != arr2.end(); ++obj)
                {
                    delete *obj; // deleting what obj points to, which is a pointer
                }
                arr2.clear();
                return 0;
            }
            else if (command == "r")
            {
                level = 0;
                bausage = 0;
                bdusage = 0;
                rhusage = 0;
                phusage = 0;
                wausage = 0;
                wdusage =0;
                count = 0;
                delete (p1);
                p1 = nullptr;
                break;
            }
            else
            {
                invalid = true;
                action += "Invalid Command ";
            }
// vampire
//before enemy attack
            if (p1->isDead ())
            {
                string s1;
                cout <<  "You have been slain.\n Enter your command: " << endl;

                cin >> s1;
                while (true)
                {
                    if (s1 == "q")
                    {
                        delete (p1);
                        p1 = nullptr;
                        for (vector<Enemy*>::iterator obj = arr1.begin();
                                obj != arr1.end(); ++obj)
                        {
                            delete *obj; // deleting what obj points to, which is a pointer
                        }
                        arr1.clear();
                        for (vector<Item*>::iterator obj = arr2.begin();
                                obj != arr2.end(); ++obj)
                        {
                            delete *obj; // deleting what obj points to, which is a pointer
                        }
                        arr2.clear();
                        return 0;
                    }
                    else if (s1 == "r")
                    {
                        count = 0;
                        level = 0;
                        bausage = 0;
                        bdusage = 0;
                        rhusage = 0;
                        phusage = 0;
                        wausage = 0;
                        wdusage =0;
                        delete (p1);
                        p1 = nullptr;
                        count = 0;
                        merchantHostile = false;
                        break;
                    }
                    else
                    {
                        cout << "Invalid Command. " << endl;
                    }

                }
                break;
            }
            //check if p1 is standing on a gold pile
            pickGold = f.theChamber[pos.first][pos.second].getisGold ();
            if (pickGold)
            {
                f.theChamber[pos.first][pos.second].retrieveGold (p1);
            }
            //call special
            // move all enemies
            int len = arr1.size();

            for (int i = 0; i < arr1.size(); ++i)
            {
                bool d =arr1.at(i)->isDead ();
                // enemy dead
                if (d)
                {
                    string t = arr1.at(i)->getType ();
                    if ( t!= "Dragon"&& t!= "Merchant"&& t!= "Human")
                    {
                        pair <int,int> p = arr1.at(i)->getPos();
                        int val = (rand() % 2) + 1;
                        p1->addGold(val);
                        f.theChamber[p.first][p.second].leaveChar ();
                        //arr1.erase (arr1.begin()+i);
                    }
                    else if (t=="Human"||t=="Merchant")
                    {
                        pair <int,int> p = arr1.at(i)->getPos();
                        //Character *temp = f.theChamber[p.first][p.second].getCharacter ();
                        //delete (temp);
                        //temp = nullptr;
                        f.theChamber[p.first][p.second].leaveChar ();
                        MerchantHoard *pg = new MerchantHoard {"merchant_g",true,false,4,nullptr};
                        f.theChamber[p.first][p.second].addItem (pg);
                        arr2.emplace_back(pg);
                        //arr1.erase (arr1.begin()+i);
                        pg = nullptr;
                        f.theChamber[p.first][p.second].setGold (4);

                    }
                    else if (t=="Dragon")
                    {
                        pair <int,int> p = arr1.at(i)->getPos();
                        pair <int, int> dhp= arr1.at(i)->getDragonHoardPos ();
                        f.theChamber[p.first][p.second].leaveChar ();
                        Item *it = f.theChamber[dhp.first][dhp.second].getItem ();
                        it->setcanUse (true);
                    }

                    arr1.erase(arr1.begin()+i);
                }

            }
            len = arr1.size();
            if (!freeze && !invalid)
            {
                for (int i = 0; i < len; ++i)
                {
                    Enemy *e = arr1.at(i);
                    int x = e->getPos().first;
                    int y = e->getPos().second;
                    f.move(e,f.theChamber[x][y]);
                }
                try
                {
                    f.theChamber[pos.first][pos.second].notifyObservers();
                }
                catch(string s1)
                {
                    action += s1;
                }
            }
            else
            {
                try
                {
                    f.theChamber[pos.first][pos.second].notifyObservers();
                }
                catch(string s1)
                {
                    action += s1;
                }
            }
            // merchant special
            for (int i = 0; i < len; ++i)
            {
                Enemy *e = arr1.at(i);
                // enemy is not a merchant or dragon
                // if enemy is human, then ......
                if(e->getType() != "Merchant" && e->getType() != "Dragon")
                {
                    e->special();
                }
                else if(e->getType() == "Merchant" && e->getIsHostile())
                {
                    merchantHostile = true;
                    for (int i = 0; i < len; ++i)
                    {
                        Enemy *e1 = arr1.at(i);
                        if (e1->getType () == "Merchant")
                        {
                            e1->special ();
                        }
                    }
                }
                // else if(e.getType() == "Dragon")
                //{

                //}
            }
            // Check if is dead before going up stairs
            if (p1->isDead ())
            {
                string s1;
                cout << "You have been slain.\n Enter your command: " << endl;

                cin >> s1;
                while (true)
                {
                    if (s1 == "q")
                    {
                        delete (p1);
                        p1 = nullptr;
                        for (vector<Enemy*>::iterator obj = arr1.begin();
                                obj != arr1.end(); ++obj)
                        {
                            delete *obj; // deleting what obj points to, which is a pointer
                        }
                        arr1.clear();
                        for (vector<Item*>::iterator obj = arr2.begin();
                                obj != arr2.end(); ++obj)
                        {
                            delete *obj; // deleting what obj points to, which is a pointer
                        }
                        arr2.clear();
                        return 0;
                    }
                    else if (s1 == "r")
                    {
                        count = 0;
                        level = 0;
                        bausage = 0;
                        bdusage = 0;
                        rhusage = 0;
                        phusage = 0;
                        wausage = 0;
                        wdusage =0;
                        delete (p1);
                        p1 = nullptr;
                        count = 0;
                        merchantHostile = false;
                        break;
                    }
                    else
                    {
                        cout << "Invalid Command. " << endl;
                    }

                }
                break;
            }

            char tp = f.theChamber[pos.first][pos.second].getSymbol ();
            if (tp == 's')
            {
                p1->reset ();
                level += 1;
                f.theChamber[pos.first][pos.second].leaveChar ();
                break;
            }
            //update character stats
            Health = p1->getHp ();
            Def = p1->getActualDef ();
            Atk = p1->getActualAtk ();
            Race = p1->getType ();

            invalid = false;
            f.print();
            // Pirnt out stats cout <<
            cout << "Race" << ": " << Race << " " << "Gold: " << p1->getGold () << "                                                    Floor: "<< level+1 <<endl;
            cout <<  "HP: " << Health << endl;
            cout << "Atk: " << Atk << endl;
            cout << "Def: " << Def << endl;
            cout << "Action: " << action << endl;
            action = "";
        }
        for (vector<Enemy*>::iterator obj = arr1.begin();
                obj != arr1.end(); ++obj)
        {
            delete *obj; // deleting what obj points to, which is a pointer
        }
        arr1.clear();
        for (vector<Item*>::iterator obj = arr2.begin();
                obj != arr2.end(); ++obj)
        {
            delete *obj; // deleting what obj points to, which is a pointer
        }
        arr2.clear();
    }
}


