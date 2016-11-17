int dummy(){return 0;}

#include <iostream>
#include <string>
#include <sstream>
#include "textHandler.cpp"
#include "game.cpp"
#include "player.cpp"
#include "room.cpp"

string command, direction;
int main()
{
    cout << "To begin a new game, type 'START'. To leave, type 'QUIT'" << endl;
    cin >> command;
    while (command != "START" && command != "QUIT")
    {
        cout << "Please use proper syntax." << endl;
        cin >> command;
    }
    if (command == "QUIT")
    {
        return 0;
    }   
    if (command == "START")
    {
        cout << "Starting new game" << endl;
        game* newGame = game::getter();
        newGame->init();
        cin >> command >> direction;
        command = command + " " + direction;
        // cout << "RABBITS" << endl;
        try
        {
            
            while (true)
            {
               newGame->input(command);
            }
        }
        catch (const std::exception&) //end game
        {
            std::cout << "MOO";
            return 0;
        }
    }

}