#include <iostream>
#include <string>

#include "player.h"
#include "room.h"
using namespace std;

player* player::playerInstance = new player;
void player::setLocation(room* x)
{
    curLoc = x;
}
player* player::playerGet()
{
    return playerInstance;
}
room* player::getLocation()
{
    return curLoc;
}
