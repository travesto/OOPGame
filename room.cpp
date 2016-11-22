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
	if (itemName == "This is the item name.")
	{
		string description = "This is where the description for the item in question goes.";
		int deadlineEffect = 0; //this is the impact of using the item on the deadline. A positive number will cause the time before deadline to increase, whereas a negative number will do vice versa.
		int timesUsable = 1;  //this is the number of times that the item is usable.
		item* newItem = new item(itemName, description, deadlineEffect, timesUsable);
		itemList[itemCount] = *newItem;
	}
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
		return itemPosition;
	return 0;
}
//end item interface

room::~room()
{
}