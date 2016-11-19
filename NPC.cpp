#include "NPC.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

NPC::NPC(string n) {
	this->name = n;
	this->npcDialogue = "Hello I am " + this->name + ".";
	cout << this->npcDialogue << endl;
}

void NPC::setDialogue() {
	srand(time(NULL));
	int randNum = rand() % 5 + 1;
	switch(randNum) {
		case 0:
			this->npcDialogue = "Konnichiwa! (Good day!/Hello!)";
		case 1:
			this->npcDialogue = "What's up pleb.";
		case 2:
			this->npcDialogue = "I think I saw the boss near your cubicle a few minutes ago.";
		case 3:
			this->npcDialogue = "I just spoke to Lumberg in the conference room.";
		case 4:
			this->npcDialogue = "...Hm. I was just resting my eyes.";
		case 5:
			this->npcDialogue = "What have you done now you donkey?!";
	}
}

string NPC::getDialogue() {
	return this->npcDialogue;
}

