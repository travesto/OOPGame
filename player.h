#include <iostream>
#include <string>
using namespace std;

class player
{
public:
    player();
    ~player();
    void move(char input) { return game.input();}
    string look(char look) {return room.descriptionGet();}
    string talk(char talk) {return npc.dialogueGet();}

private:
    
};