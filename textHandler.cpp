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
void go::executeInternal(string)
{
    cout << "WHY ";
    abort();
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
    cout << action->checkTime();
    // abort();
    //take more input
}