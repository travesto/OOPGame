#include <iostream>
#include <string>
#include "player.h"
using namespace std;

player::player()
{
}
player::~player()
{
}
player* player::playerInstance = new player;
