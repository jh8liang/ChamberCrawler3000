#ifndef CELLINFO_H_INCLUDED
#define CELLINFO_H_INCLUDED

class Item;
class Character;

struct Info
{
    int row;
    int col;
    bool has_potion;
    bool has_gold;
    bool is_enemy;
    bool is_player;
    Item *toItem;
    Character *toCharacter;
};


#endif // CELLINFO_H_INCLUDED
