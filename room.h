#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "item.h"

using namespace std;

enum direction {NORTH, EAST, SOUTH, WEST, INVALID};

direction reverse(direction dir)
{
    switch (dir)
    {
        case NORTH:
        {
            return SOUTH;
        }
        case EAST:
        {
            return WEST;
        }
        case SOUTH:
        {
            return NORTH;
        }
        case WEST:
        {
            return EAST;
        }
        case INVALID:
        {
            return INVALID;
        }
    }
    return INVALID;
    
}
direction getFromString(string b)
{
    string inputDirections[] = {"NORTH", "EAST", "SOUTH", "WEST", "INVALID"};
    for (int i = 0; i < 5; i++)
    {
        if (b == inputDirections[i])
        {
            return (direction)i;
        }
    }
    return INVALID;
}
class room
{
    public:
        room();
        ~room(); 
        // void npcGeneration() {};
        void addDesc(string x);
		void itemGeneration(string itemName);
        string descripGet() const;
        void setRoom(direction, room*);
        room* getRoom(direction);
		int checkForItems(string itemName);
		void examineItem(string itemName, std::ostream& out);
		int useItem(string itemName);

    private:
        map<direction, room*> roomAdj;
		item* itemList;
		int itemCount;
        std::vector<string> descriptions;
};

#endif