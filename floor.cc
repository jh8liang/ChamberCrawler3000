#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "cell.h"
#include "floor.h"
#include <fstream>
#include "item.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
using namespace std;

Floor :: ~Floor ()
{
    /*
    for (int i = 0; i < 25; ++i)
    {
        for (int j = 0; j < 79; ++j)
        {
            Character * c = theChamber[i][j].getCharacter();
            Item* it = theChamber[i][j].getItem ();

            if (c != nullptr)
            {
                string ct = c->getType ();
                if (ct!="Shade"&&ct!="Vampire"&&ct!="Troll" &&ct!="Goblin"&&ct!="Drow")
                {
                    delete (c);
                }
            }
            else if (it!= nullptr)
            {
                delete (it);
            }
        }
    }*/
}

Floor::Floor (int level, bool win): level{level}, win{win}
{
    // constructor
    this->numChamber = {1,2,3,4,5};
    for (int i = 0; i < 25; ++i)
    {
        vector <Cell> r;
        for(int j = 0; j < 79; ++j)
        {
            if(i == 0)
            {
                if (j == 0 || j==79)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back(c);
                }
                else
                {
                    Cell c{'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back(c);
                }
            }
            else if (i == 1)
            {
                if (j == 0 || j==78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }

            else if ( i == 2)
            {
                if ( j == 0 || j == 2|| j == 29 || j == 38 || j == 62 ||j == 78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=3 && j <= 28)||(j>=39 && j <=61))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }
            else if ( i == 3)
            {
                if ( j == 0 || j == 2|| j == 29 || j == 38 || j == 62 ||j == 78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=3 && j <= 28)||(j>=39 && j <=61))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }
            else if (i == 4)
            {
                if ( j == 0 || j == 2 || j == 62 ||j == 78|| j == 70)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=3 && j <= 28)||(j>=39 && j <=61))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else if (j == 29 || j == 38)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j >=30 && j <= 37)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else  if (j >=63 && j <= 69)
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }


            else if (i == 5)
            {
                if ( j == 0 || j == 2|| j == 29 || j == 38 ||j == 78 || j == 70 || j == 73)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=3 && j <= 28)||(j>=39 && j <=69))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else if (j == 33)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j >= 71 && j <= 72)
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
            }

            else if ( i == 6)
            {
                if ( j == 0 || j == 2|| j == 29 || j == 38 || j == 78 || j == 73|| j == 76)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);;
                }
                else if ((j >=3 && j <= 28)||(j>=39 && j <=72))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 33)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j >= 74 && j <= 75)
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
            }


            else if (i==7)
            {
                if ( j == 0 || j == 2|| j == 29 || j == 38 ||j == 78 ||j == 60 || j ==76)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=3 && j <= 12)||(j>=14 && j <= 28)||(j>=39 && j <=42)||(j>=44&&j<=59))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 33)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 13||j==43)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j >= 61 && j <= 75)
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }

            else if ( i == 8)
            {
                if (j == 0 || j==78||j == 60 || j == 76)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 13 || (j >=31 && j <= 43))
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ( j >= 61 && j <=75)
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }

            else if (i ==9)
            {
                if (j == 0||j ==37|| j ==50|| j == 60 || j ==76||j == 78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 13 || j ==31)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >= 38 && j <= 42) || (j>=44 && j <= 49))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 43)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else if (j>=61 && j <= 75)
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {

                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }

            else if (i ==10)
            {
                if (j == 0 || j == 37|| j == 50|| j == 60 || j == 76 || j ==78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else if (j == 13 || j == 31)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else if ((j >= 38 && j <= 49) || (j >= 61 && j <= 75))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }

            else if (i== 11)
            {
                if (j == 0||j ==37|| j ==50 || j ==76||j == 78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j==60)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=13 &&j <=31)||(j>=54&&j<=59))
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >= 38 && j <= 49) || (j>=61&&j <=75))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {

                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }
            else if (i==12)
            {
                if (j == 0||j ==37|| j ==50|| j == 60 || j ==76||j == 78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 13 || j ==31||j==54)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >= 38 && j <= 49) || (j>=61 && j <= 75))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 43)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else if (j>=61 && j <= 75)
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {

                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }

            else if (i ==13)
            {
                if (j == 0||j ==37|| j ==50|| j == 60 || j ==76||j == 78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 13 || j ==31||j==54)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >= 38 && j <= 42) || (j>=44 && j <= 49))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j == 69||j==43)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);

                }
                else if ((j>=61 && j <= 69)||(j>=70&&j<=75))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {

                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }
            else if (i ==14)
            {
                if (j== 0||j==3||j==25||j==78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j ==31||j==43||j==54||j==69)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=4&&j<=12)||(j>=14&&j<=24))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j==13)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }
            else if (i==15)
            {
                if (j== 0||j==3||j==25||j==78||j==64||j==76)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j ==31||j==43||j==54)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=4&&j<=24))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j==69)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=65&&j<=68) || (j>=70&&j<=75))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }
            else if (i ==16)
            {
                if (j== 0||j==3||j==25||j==78||j==64||j==76)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=4&&j<=24))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j >=31 && j<=54)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=65&&j<=75))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }
            else if (i ==17)
            {
                if (j== 0||j==3||j==25||j==78||j==64||j==76)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=4&&j<=24))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j ==31|| j==43)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=65&&j<=75))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }
            else if (i==18)
            {
                if (j== 0||j==3||j==25||j==78||j==64||j==76||j==36)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=4&&j<=24))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j ==31)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j ==43)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=65&&j<=75))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=37&&j<=42)||(j>=44&&j<=63))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }
            else if (i ==19)
            {
                if (j== 0||j==3||j==25||j==78||j==76||j==36)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=4&&j<=24))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j ==31)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=37&&j<=75))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }
            else if (i==20)
            {
                if (j== 0||j==3||j==78||j==76)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j==25||j==36)
                {
                    Cell c {'d',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=4&&j<=24))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if (j >=26 &&j<=35)
                {
                    Cell c {'p',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=37&&j<=75))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }

            }
            else if (i==21)
            {
                if (j== 0||j==3||j==25||j==78||j==76||j==36)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=4&&j<=24))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=37&&j<=75))
                {
                    Cell c {'t',true,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }
            else if (i==22)
            {
                if (j== 0||j==3||j==25||j==78||j==76||j==36)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=4&&j<=24))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else if ((j >=37&&j<=75))
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }
            else if (i==23)
            {
                if (j == 0 || j==78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'e',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }
            else
            {
                if (j == 0 || j==78)
                {
                    Cell c {'v',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
                else
                {
                    Cell c {'h',false,false, false,0,nullptr,nullptr,i,j};
                    r.emplace_back (c);
                }
            }
        }
        theChamber.emplace_back(r);
    }

    /*
    // attach observer
    for (int i = 0; i < 25; i++)
    {

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 79; j++)
        {
            if (i < 24)
            {
                if (j < 78)
                {
                    theChamber[i][j].attach(&theChamber[i+1][j+1]);
                }
                if (j > 0)
                {
                    theChamber[i][j].attach(&theChamber[i+1][j-1]);
                }
                theChamber[i][j].attach(&theChamber[i+1][j]);
            }

            if (i > 0)
            {
                if (j < 78 )
                {
                    theChamber[i][j].attach(&theChamber[i-1][j+1]);
                }
                if (j < 0)
                {
                    theChamber[i][j].attach(&theChamber[i-1][j-1]);
                }
                theChamber[i][j].attach(&theChamber[i-1][j]);
            }
            if (j < 78)
            {
                theChamber[i][j].attach(&theChamber[i][j+1]);
            }
            if (j > 0)
            {
                theChamber[i][j].attach(&theChamber[i][j-1]);
            }
            //cout << endl;
        }
    }
    }*/

    /*
    for (int j = 0; j < 79; j++)
    {
        if (i < 24)
        {
            theChamber[i][j].attach(&theChamber[i+1][j]);
            // theChamber[i][j].attach(&theChamber[i+1][j-1]);
            //cout<< "First case " << i+1 << " " << j -1;
        }
        if (i > 0)
        {
            theChamber[i][j].attach(&theChamber[i-1][j]);
            // theChamber[i][j].attach(&theChamber[i-1][j+1]);
            //cout << "Second case " << i-1 << " " << j+1;
        }
        if (j < 78)
        {
            theChamber[i][j].attach(&theChamber[i][j+1]);
            // theChamber[i][j].attach(&theChamber)[i+1][j+1];
            //cout << "third case "  << i+1 << " " << j+1 ;
        }
        if (j > 0)
        {
            theChamber[i][j].attach(&theChamber[i][j-1]);
            //  theChamber[i][j].attach(&theChamber[i-1][j-1]);
            //cout << "fourth case " << i+1  << " " << j+1 << endl;
        }
        //cout << endl;
    }*/

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 79; j++)
        {
            if (i < 24)
            {
                if (j < 78)
                {
                    theChamber[i][j].attach(&theChamber[i+1][j+1]);
                }
                if (j > 0)
                {
                    theChamber[i][j].attach(&theChamber[i+1][j-1]);
                }
                theChamber[i][j].attach(&theChamber[i+1][j]);
            }

            if (i > 0)
            {
                if (j < 78 )
                {
                    theChamber[i][j].attach(&theChamber[i-1][j+1]);
                }
                if (j > 0)
                {
                    theChamber[i][j].attach(&theChamber[i-1][j-1]);
                }
                theChamber[i][j].attach(&theChamber[i-1][j]);
            }
            if (j < 78)
            {
                theChamber[i][j].attach(&theChamber[i][j+1]);
            }
            if (j > 0)
            {
                theChamber[i][j].attach(&theChamber[i][j-1]);
            }
            //cout << endl;
        }
    }
}


void Floor::print ()
{
    for (int i = 0; i < 25; ++i)
    {
        for (int j = 0; j <79; ++j)
        {
            (theChamber[i][j]).cprint ();
        }
        cout <<endl;
    }
}

/*bool Floor:: isWin (Characrer *c) {
  bool whichfloor = level;
  return (whichfloor == 5)&&(((c->pos)->symbol) == 's');
}*/


void Floor:: PlacePlayer ()
{
    int whichchamber = rand ()% 5 + 1;
}

void Floor::move(Character *c, Cell &cell)
{
    if (c->getCanMove())
    {
        srand(time(NULL)); //random seed
        int min = 1;
        int max = 8;

        while (true)
        {
            int secret_move = min + rand() % ((max-min) + 1 );
            pair <int, int> cord = c->getPos();
            int row = cord.first;
            int col = cord.second;
            //cout <<"secret_move: " <<  secret_move << endl;
            if (secret_move == 1)
            {
                row += 1;
                col += 1;
            }
            else if (secret_move == 2)
            {
                row -= 1;
                col -= 1;
            }
            else if (secret_move == 3)
            {
                row += 1;
                col -= 1;
            }
            else if (secret_move == 4)
            {
                row -= 1;
                col += 1;
            }
            else if (secret_move == 5)
            {
                row += 1;
            }
            else if (secret_move == 6)
            {
                row -= 1;
            }
            else if (secret_move == 7)
            {
                col += 1;
            }
            else
            {
                col -= 1;
            }

            /*cout << "cond1"<< (row < 25) << endl;
            cout << "cond2" << (col < 79) << endl;
            cout << "cond3" << (theChamber[row][col].getSymbol() == 't') << endl;
            cout << "cond4" << (!theChamber[row][col].occupied()) << endl;
            cout << "symbol: " << theChamber[row][col].getSymbol() << endl;*/

            if (row < 25 && col < 79 &&
                    theChamber[row][col].getSymbol() == 't' &&
                    !theChamber[row][col].occupied())
            {

                cell.leaveChar();
                theChamber[row][col].enterChar(c);
                c->setPos(row, col);
                return;
            }

        }
    }
}


