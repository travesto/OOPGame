#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

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
        void itemsGeneration() {};
        string descripGet();
        void setRoom(direction, room*);
        room* getRoom(direction);

    private:
        map<direction, room*> roomAdj;
        std::vector<string> descriptions;
};

#endif