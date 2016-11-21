#include <iostream>
#include <stdlib.h>
#include <unistd.h>
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
        cout << "You have arrived." << endl << endl;
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
    if (playerLocation->descripGet() =="Your boss be here!")
    {
        cout << playerLocation->descripGet() << endl;
        cout << "You found your boss! You win!\n";
        exit(0);
    }
    else if (playerLocation->descripGet() == "It's the break room. Cheryl is here.\n'Want to hear my favourite story?' asks Cheryl.(YES/NO)")
    {
        cout << playerLocation->descripGet() << endl;
        string moby;
        cin >> moby;
        if (moby == "YES")
        {
            cout << "Really?! No one ever listens to my stories!" << endl << endl << "Moby Dick, Chapter 1\n\nCall me Ishmael.\nSome years ago--never mind how long precisely--having little or no money in my purse,\nand nothing particular to interest me on shore, I thought I would sail about a little and see the watery part of the world.\nIt is a way I have of driving off the spleen and regulating the circulation.\nWhenever I find myself growing grim about the mouth; whenever it is a damp, drizzly November in my soul;\nwhenever I find myself involuntarily pausing before coffin warehouses, and bringing up the rear of every funeral I meet;\nand especially whenever my hypos get such an upper hand of me, that it requires a strong moral principle to prevent me from deliberately stepping into the street,\nand methodically knocking people's hats off--then, I account it high time to get to sea as soon as I can.\nThis is my substitute for pistol and ball.\nWith a philosophical flourish Cato throws himself upon his sword; I quietly take to the ship.\nThere is nothing surprising in this.\nIf they but knew it, almost all men in their degree, some time or other, cherish very nearly the same feelings towards the ocean with me.\nThere now is your insular city of the Manhattoes, belted round by wharves as Indian isles by coral reefs--commerce surrounds it with her surf.\nRight and left, the streets take you waterward.\nIts extreme downtown is the battery, where that noble mole is washed by waves, and cooled by breezes, which a few hours previous were out of sight of land.\nLook at the crowds of water-gazers there.\nCircumambulate the city of a dreamy Sabbath afternoon.\nGo from Corlears Hook to Coenties Slip, and from thence, by Whitehall, northward.\nWhat do you see?--Posted like silent sentinels all around the town, stand thousands upon thousands of mortal men fixed in ocean reveries.\nSome leaning against the spiles; some seated upon the pier-heads;\nsome looking over the bulwarks of ships from China;\nsome high aloft in the rigging, as if striving to get a still better seaward peep.\n";
            sleep(2);
            cout << endl << "But these are all landsmen; of week days pent up in lath and plaster--tied to counters, nailed to benches, clinched to desks.\nHow then is this?  Are the green fields gone? What do they here?\nBut look! here come more crowds, pacing straight for the water, and seemingly bound for a dive.\nStrange!\nNothing will content them but the extremest limit of the land; loitering under the shady lee of yonder warehouses will not suffice.\nNo. They must get just as nigh the water as they possibly can without falling in.\nAnd there they stand--miles of them--leagues.\nInlanders all, they come from lanes and alleys, streets and avenues--north, east, south, and west.  Yet here they all unite.  Tell me, does the magnetic virtue of the needles of the compasses of all those ships attract them thither?\nOnce more. Say you are in the country; in some high land of lakes.\nTake almost any path you please, and ten to one it carries you down in a dale, and leaves you there by a pool in the stream.\nThere is magic in it.\nLet the most absent-minded of men be plunged in his deepest reveries--stand that man on his legs, set his feet a-going, and he will infallibly lead you to water, if water there be in all that region.\nShould you ever be athirst in the great American desert, try this experiment, if your caravan happen to be supplied with a metaphysical professor.\nYes, as every one knows, meditation and water are wedded for ever.\nBut here is an artist.\nHe desires to paint you the dreamiest, shadiest, quietest, most enchanting bit of romantic landscape in all the valley of the Saco.\nWhat is the chief element he employs?\nThere stand his trees, each with a hollow trunk, as if a hermit and a crucifix were within; and here sleeps his meadow, and there sleep his cattle; and up from yonder cottage goes a sleepy smoke.\nDeep into distant woodlands winds a mazy way, reaching to overlapping spurs of mountains bathed in their hill-side blue.\n";
            sleep(2);
            cout << "- - - - " << endl << "- - - - - -" << endl << "blah blah blah blah" << endl << "- - - - - -" << endl << "- - - - " << endl << "'Hey are you listening?!' Oh boy, you dozed off there for a bit.\nYou make some flimsy excuse to get away from Cheryl.\nMan that story was boring!\nOh snap! It looks like listening to that story cost you 25 moves!\n" << endl;
            game* action = game::getter();
            for (int i = 0; i < 25; i++)
            {
                action->deadlineDec();
            }
            
        }
    }
    else
    {
        cout << playerLocation->descripGet() << endl;
        game* action = game::getter();
        action->deadlineDec();
        cout << endl;
    }


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
void quit::executeInternal(string args)
{
    cout << "Goodbye."<< endl;
    exit(0);
}
//item interface
void use::executeInternal(string args)
{
	// cout << "I'm being used!" << endl;
    player* whereAmI = player::playerGet();
	room* playerLocation = whereAmI->getLocation();
	// cout << "TEST" << endl;
    if (playerLocation->checkForItems(args) >= 0)
	{
		cout << "experimental item used.\n\n";
		game* action = game::getter();
		action->changeDeadline(playerLocation->useItem(args));
	}
	else
	{
		cout << "There is no such thing in your vicinity.\n\n"; 
	}
}
void use::handle(int i)
{
	// textHandlerBase* temp = getNext();
	next->handle(i);
}
//end item interface
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