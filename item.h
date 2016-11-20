#include <iostream>

class item //this class contains the data on the items present in the game. This data is accessed through the room class;
{
	friend class room;
	private:
		std::string name;
		std::string description;
		int deadlineEffect;
		int timesUsable;
		bool doesDisappear;

	public:
		item() //used when creating empty items in the itemList.
			{name = "empty"; description = "empty"; deadlineEffect = 0; timesUsable = 0; doesDisappear = false;}
		item(std::string startName, std::string startDescription, int change, int startAmount)
			{name = startName; description = startDescription; deadlineEffect = change; timesUsable = startAmount; doesDisappear = false;}
		~item() {};
};