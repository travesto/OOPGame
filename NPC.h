#ifndef NPC_h
#define NPC_h
#include <iostream>

class NPC {
	public:
		NPC(std::string); //Give an NPC a name
		~NPC() {}
		std::string getDialogue() const;
		void setDialogue();
		
		
	private:
		std::string name;
		std::string npcDialogue;
};

#endif
