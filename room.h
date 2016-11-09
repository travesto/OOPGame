#include <iostream>
#include <string>
#include <cmap>
using namespace std;

class room
{
public:
    room();
    ~room(); 
    void npcGeneration() {};
    void itemsGeneration() {};
    string descriptionGet() {return roomDescritpion;}

private:
    map NPC;
    map items;
    map roomDescritpion;
};
