#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "room.h"
using namespace std;

room::room()
{
    roomAdj = map<direction, room*>();
    descriptions = vector<string>();
}
void room::setRoom(direction dir, room* adj)
{
    roomAdj[dir] = adj;
    direction temp = reverse(dir);
    adj->roomAdj[temp] = this;
}
room* room::getRoom(direction dir)
{
    if (roomAdj[dir]) 
    {
        return roomAdj[dir];    
    }
    return NULL;
}
void room::addDesc(string desc)
{
    descriptions.push_back(desc);
}
string room::descripGet()
{
    int v1 = rand() % descriptions.size();
    return descriptions[v1];
}
room::~room()
{
}