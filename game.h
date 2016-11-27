#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "room.h"
using namespace std;

class game
{
    public:
        ~game(); //dtor
        void input(string in);
        // string showMap(char m) {};
        void init() const;
        void deadlineDec();
		void changeDeadline(int deadlineChange);
        //void deadlineInc();
        void checkTime() const;
        int deadlineGetter() {return deadline;}
        static game* getter();
    private:
        game(); //ctor
        game(game const& copy) {};
        static game* instance;
        int deadline;
        textHandlerBase* commandChain;


        friend int dummy();
};
#endif
