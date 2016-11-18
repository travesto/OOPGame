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
    do
    {
        cin >> command;
        if(command != "START" && command != "QUIT")
            cout << "Please use proper syntax." << endl;
    }
    while (command != "START" && command != "QUIT");
    
    if (command == "QUIT")
    {
        return 0;
    }   
    if (command == "START")
    {
        cout << "Starting new game" << endl;
        game* newGame = game::getter();
        newGame->init();
        // cout << "RABBITS" << endl;
        try
        {
            while (true)
            {
                getline(cin, command);
                // cout << command << endl;
                if(command != "")
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