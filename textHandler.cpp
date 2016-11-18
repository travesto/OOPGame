#include <iostream>
#include <stdlib.h>
#include "textHandler.h"
#include "room.h"
#include "game.h"
#include "player.h"
using namespace std;


textHandlerBase::textHandlerBase(string command)
{
    next = 0;
    cmd = command;
}
void textHandlerBase::setNext(textHandlerBase* setN)
{
    next = setN;
}
void go::handle(int i)
{
    textHandlerBase* temp = getNext();
    temp->handle(i);
}
void go::executeInternal(string a)
{
    player* whereAmI = player::playerGet();
    room* playerLocation = whereAmI->getLocation();
    direction newDir = getFromString(a);
    room* newRoom = playerLocation->getRoom(newDir);
    if (newDir == INVALID)
    {
        cout << "Go where?\n\n" << endl;
    }
    else if(newRoom)
    {
        whereAmI->setLocation(newRoom);
        game* action = game::getter();
        action->deadlineDec();
        cout << endl;    
    }
    else
    {
        cout << "You walked into the wall, dummy.\nTry a different direction or LOOK AROUND.\n\n";    
    }
}
void look::handle(int i)
{
    next->handle(i);
}
void look::executeInternal(string z)
{
    player* whereAmI = player::playerGet();
    room* playerLocation = whereAmI->getLocation();
    cout << playerLocation->descripGet() << endl;
    game* action = game::getter();
    action->deadlineDec();
    cout << endl;
    //take more input
}
void check::executeInternal(string x)
{
    game* getGame = game::getter();
    getGame->checkTime();
    cout << endl;
}
void check::handle(int i)
{
    next->handle(i);
}
void no::executeInternal(string args)
{
    game* action = game::getter();
    action->deadlineDec();
    cout << "Yes. -1 step.\n\n";
}
// void no::executeInternal(string z)
void no::handle(int i)
{
    next->handle(i);
}
void invalid::execute(string, string)
{
    cout << "Invalid input, ya dingus.\n\n";
}