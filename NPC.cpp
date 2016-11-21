#include "NPC.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

NPC::NPC(string n) {
	this->name = n;
	this->npcDialogue = "Hello I am " + this->name + ".";
}

void NPC::setDialogue() {
	srand(time(NULL));
	int randNum = rand() % 5 + 0;
	switch(randNum) {
		case 0:
			this->npcDialogue = "Konnichiwa! (Good day!/Hello!)";
			break;
		case 1:
			this->npcDialogue = "What's up pleb.";
			break;
		case 2:
			this->npcDialogue = "I think I saw the boss near your cubicle a few minutes ago.";
			break;
		case 3:
			this->npcDialogue = "I just spoke to Lumberg in the conference room.";
			break;
		case 4:
			this->npcDialogue = "...Hm. I was just resting my eyes.";
			break;
		case 5:
			this->npcDialogue = "What have you done now you donkey?!";
			break;
	}
}

string NPC::getDialogue() const {
	return this->npcDialogue;
}

