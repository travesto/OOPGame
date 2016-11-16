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
        void init();
        void deadlineDec();
        //void deadlineInc();
        int checkTime();
        static game* getter();
        room* gamePlayerGet();
    private:
        game(); //ctor
        game(game const& copy) {};
        static game* instance;
        int deadline;
        textHandlerBase* commandChain;


        friend int dummy();
};
#endif
