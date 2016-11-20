#include <iostream>
#include <stdlib.h>
#include "player.h"
#include "game.h"
#include "room.h"

void game::init()
{
    room* first = new room();
    room* second = new room();
    room* third = new room();
    first->setRoom(NORTH, second);
    second->setRoom(EAST, third);
    first->addDesc("\nYou're in your cubicle. It's small, beige, and boring.\nThere's a poster of a kitty on the wall telling you to 'Hang in there buddy!'\nMotivation +1. Cynicism +5.");
    second->addDesc("Hallway");
    third->addDesc("Conference Room");

    player::playerGet()->setLocation(first);
    cout << "\nMONDAY -- 9AM\nYou've settled into the routine at you job here at PratherCorp.\nEach day you show up, check your email, check Reddit, get coffee, go to the bathroom to play Tetris on your phone.\nCheck your email. Ignore the email your mom sent you.\nRead the memo about TPS reports. Toss the memo into hoop over the garbarge.\nYou miss.\nLunch break!\nSomeone ate your sandwich in the break room, probably Steve...\nBack to your Desk. Check email. Check ReOH CRAP\nYou see your boss walking across the office towards you. You hunker down, hoping to go unnoticed.\n'Well hello.' says Lumbergh.\n'Listen, I'm going to need one those computery programs you make for my board meeting at 5 today. \nThink you can do that? If you could do that, that would be greeaaat.'\nLumbergh leaves. You look at your computer. You think about crying. You think about quitting. You bang you head on the keyboard.\nYou take a deep breath and start typing.\nHuh. It only took you like an hour to write. Must be due to your excellent Professors.\nYou save the program to your floppy. You get up."<< endl;
    
    cout << "\nWhat would you like to do?\nYou have 10 moves to find your boss!\nYou can 'GO NORTH' or a similar direction.\nYou can also 'CHECK TIME' and 'LOOK AROUND'\n"<< endl;
}

game::game()
{
    deadline = 10;
    commandChain = new go();
    commandChain->addNext(new look());
    commandChain->addNext(new check());
    commandChain->addNext(new no());
    commandChain->addNext(new invalid());
}
game::~game()
{
}
game* game::instance = new game;
game* game::getter()
{
    return instance;
}
void game::checkTime()
{
    cout << "You have: " << deadline << " moves left till you're late!" << endl;
    //return deadline;
}
void game::changeDeadline(int deadlineChange)
{
	deadline += deadlineChange;
	return;
}
void game::deadlineDec()
{
    deadline--;
    if (deadline == 0)
    {
        std::cout << endl << "You missed your deadline!" << endl << endl << "Running through the hallway, you barge into the conference room." << endl << "Your boss looks up from a very important TPS report and gives you the death glare." << endl << "You gulp." << endl << "You know you're done." << endl << "You're fired." << endl << endl << "THREE MONTHS LATER" << endl << endl << "You've adjusted to your new life living in your van down by the river." << endl <<"Occasionally you call your mother, only to hear her sob about how you threw away your potential." << endl <<"She cries." << endl << "You raise the bottle to your mouth, yearning for the sweet release." << endl << endl << "FOUR MONTHS LATER" << endl << endl << "The priest stands over the grave, silent and alone. 'Such a shame' he mutters." << endl << "'Dust to dust, ash to ash'. Crumbled soil falls onto the coffin." << endl <<"The priest turns and walks away." << endl << endl << "YOU LOSE." << endl;
        exit(0);
    }
}
void game::input(string com)
{
    // std::cout << "AKBAR!";
    string input = com;
    string remaining = "";
    for (int i = 0; (unsigned)i < com.length(); i++)
    {
        if (com[i] == ' ')
        {
            input = com.substr(0, i);
            remaining = com.substr(i+1);
            break;
        }
    }
    // std::cout << "WOOF";
    commandChain->execute(input, remaining);
}