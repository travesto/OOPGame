#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "room.h"
using namespace std;

room::room()
{
    roomAdj = map<direction, room*>();
    descriptions = vector<string>();
	itemList = new item[2];
	itemCount = 0;
}
void room::setRoom(direction dir, room* adj)
{
    roomAdj[dir] = adj;
    direction temp = reverse(dir);
    adj->roomAdj[temp] = this;
}
room* room::getRoom(direction dir)
{
    if (roomAdj[dir]) 
    {
        return roomAdj[dir];    
    }
    return NULL;
}
void room::addDesc(string desc)
{
    descriptions.push_back(desc);
}
string room::descripGet() const
{
    int v1 = rand() % descriptions.size();
    return descriptions[v1];
}

//item interface
void room::itemGeneration(string itemName)
{
	//cout << "generating..." << endl;
	if (itemCount % 2 == 0)
	{
		item* newItemList = new item[itemCount * 2];
		for (int count = 0; count < itemCount; count++)
		{
			newItemList[count] = itemList[count];
		}
		delete[] itemList;
		itemList = newItemList;
	}
	//cout << "list checked." << endl;

	string description = "";
	int deadlineEffect = 0;
	int timesUsable = 0;
	string useText = "";

	if (itemName == "POSTER")
	{
		//cout << "is a poster." << endl;
		description = "It's that same kitten poster. We're not giving you that motivation boost again, though.\n";
		deadlineEffect = -1; //this is the impact of using the item on the deadline. A positive number will cause the time before deadline to increase, whereas a negative number will do vice versa.
		timesUsable = 1;  //this is the number of times that the item is usable.
		useText = "What do you plan on doing with it? Showing it around the office?\nYeah, right. You do that.\n";
		//cout << "stuff set." << endl;
	}
	else if (itemName == "XEROX MACHINE")
	{
		description = "The machine continues to hum and whir.\nMaybe your boss might be more forgiving of you if you print out that short description of your program you wrote?\n";
		deadlineEffect = 1; //this is the impact of using the item on the deadline. A positive number will cause the time before deadline to increase, whereas a negative number will do vice versa.
		timesUsable = 1;  //this is the number of times that the item is usable.
		useText = "You print out a short description of what your program can do.\nYou even got several copies so that he can hand them out to whoever he wants.\n";
	}
	else if (itemName == "COFFEE MAKER")
	{
		description = "The coffee maker. It's your one real friend in this office.\n You would have gone insane within a week without the help of this guy.\n";
		deadlineEffect = 3; //this is the impact of using the item on the deadline. A positive number will cause the time before deadline to increase, whereas a negative number will do vice versa.
		timesUsable = 1;  //this is the number of times that the item is usable.
		useText = "You pour yourself a cup of coffee. After drinking it, you feel refreshed, like the world is just that bit brighter.\n You have a new pep to your step. Motivation +1\n";
	}
	else if (itemName == "BATHROOM")
	{
		description = "Do you really want to think anymore about that place? It's probably not a good idea to waste your time here.\n";
		deadlineEffect = -2; //this is the impact of using the item on the deadline. A positive number will cause the time before deadline to increase, whereas a negative number will do vice versa.
		timesUsable = 1;  //this is the number of times that the item is usable.
		useText = "You decide to use the bathroom. The time it takes eats up the time you have before you meet your boss, though.\n";
	}
	else if(itemName == "BOSS' BATHROOM")
	{
		description = "This is the Boss' bathroom. It's quite a bit nicer than the one you have to use. Is that toilet gold-plated?!\n";
		deadlineEffect = -6; //this is the impact of using the item on the deadline. A positive number will cause the time before deadline to increase, whereas a negative number will do vice versa.
		timesUsable = 1;  //this is the number of times that the item is usable.
		useText = "Really? OK. it's your funeral...\nThat was much nicer than you expected, and you're lucky your boss didn't come by, but you feel like it ate up even more time than usual...";
	}
	else if (itemName == "PHONE")
	{
		description = "The phone keeps ringing. Is anyone going to answer it? It's not really your job to worry about it, though...\n";
		deadlineEffect = -3; //this is the impact of using the item on the deadline. A positive number will cause the time before deadline to increase, whereas a negative number will do vice versa.
		timesUsable = 1;  //this is the number of times that the item is usable.
		useText = "You answer the phone to find a very angry customer on the line. Something about 'false advertising.' You try to appease him, to no avail.\n By the time you finally get the chance to hang up on the guy, you realize that you have spent way too long here.\n Your faith in humanity died a little during that conversation. Cynicism +10";
	}
	else if (itemName == "FOOD")
	{
		description = "Can you really call this food? The smell alone feels like it could knock you out. Maybe you should keep your distance...";
		deadlineEffect = 5; //this is the impact of using the item on the deadline. A positive number will cause the time before deadline to increase, whereas a negative number will do vice versa.
		timesUsable = 1;  //this is the number of times that the item is usable.
		useText = "Against your better judgement, you quickly order some 'food' and scarf it down.\n immediately, your head clears, and you feel like you could run a mile. What on Earth did they put in that thing?\n";
	}
	item* newItem = new item(itemName, description, deadlineEffect, timesUsable, useText);
	//cout << "item created at " << itemCount << "." << endl;
	itemList = newItem;
	//cout << "past poster" << endl;
	itemCount++;
}

int room::checkForItems(string itemName)
{
	int itemPosition = -1;
	for (int count = 0; count < itemCount; count++)
	{
		if (itemList[count].name == itemName)
			itemPosition = count;
	}
	return itemPosition;
}

void room::examineItem(string itemName, std::ostream& out)
{
	if (checkForItems(itemName) >= 0)
		out << itemList[checkForItems(itemName)].description;
	else
		out << "item could not be found.";
	return;
}

int room::useItem(string itemName)
{
	int itemPosition = checkForItems(itemName);
	if (itemPosition >= 0)
	{
		cout << itemList[itemPosition].use();
		return itemList[itemPosition].deadlineChange();
	}
	return 0;
}
//end item interface

room::~room()
{
	delete[] itemList;
}