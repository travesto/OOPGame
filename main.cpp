int dummy(){};

#include <iostream>
#include "textHandler.h"
#include "game.cpp"
#include "player.cpp"
#include "room.cpp"

string command;
int main()
{
    cout << "To begin a new game, type 'Start'. To leave, type 'Quit'" << endl;
    cin >> command;
    while (command != "Start" && command != "Quit")
    {
        cout << "Please use proper syntax." << endl;
        cin >> command;
    }
    if (command == "Quit")
    {
        return 0;
    }   
    if (command == "Start")
    {
        cout << "Starting new game" << endl;
        game* newGame = game::getter();
        cin >> command;
        try
        {
            while (true)
            {
                newGame->input(command);
            }
        }
        catch (const std::exception&) //end game
        {
            return 0;
        }
    }

}