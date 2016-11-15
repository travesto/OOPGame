#include <iostream>
#include "game.h"

game::game()
{
    deadline = 500;
    commandChain = new go();
}
game::~game()
{
}
game* game::instance = new game;
game* game::getter()
{
    return instance;
}
int game::checkTime()
{
    return deadline;
}
void game::input(string com)
{
    string input;
    string remaining;
    for (int i = 0; i < com.length(); i++)
    {
        if (com[i] == ' ')
        {
            input = com.substr(0, i);
            remaining = com.substr(i+1);
            break;
        }
    }
    commandChain->execute(input, remaining);
}