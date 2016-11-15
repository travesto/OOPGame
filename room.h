#include <iostream>
#include <string>
#include <map>
using namespace std;

class room
{
public:
    room();
    ~room(); 
    void npcGeneration() {};
    void itemsGeneration() {};
    string descriptionGet() {}//return roomDescritpion;}

private:
    map<int, string> roomDescritpion;
    // map items;
    // map NPC;
};

string roomNum ("1,2,3,4,5");
string roomDesc ("Blah, Blerg, Bleep");
