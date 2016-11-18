#ifndef PLAYER_H
#define PLAYER_H 
#include <iostream>
#include <string>
#include "room.h"

using namespace std;

class player
{
public:
    ~player() {};
    void setLocation(room* x); //loc setter
    room* getLocation(); //loc getter
    static player* playerGet();
private:
    player() {};
    player(player const& copy) {};
    static player* playerInstance;
    room* curLoc;
    friend int dummy();
};

#endif