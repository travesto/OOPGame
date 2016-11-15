#include <iostream>
#include <string>
using namespace std;

class game
{
    public:
        ~game(); //dtor
        void input(string in);
        // string showMap(char m) {};
        void currentLoc() {};
        void deadlineDec(bool x) {};
        void deadlineInc(bool y) {};
        int checkTime();
        static game* getter();
    private:
        game(); //ctor
        game(game const& copy) {};
        static game* instance;
        int deadline;
        textHandlerBase* commandChain;

        friend int dummy();
};
/*
    Behaviours
        - Receive input (Check t/f for valid input)
            - void input(char x) { //pass to appropriate object};
        - Map
            - string showMap(char m) {return ascii map w/ currentLoc marked}
        - Current Location
            - void currentLoc() { //changes value in map depending on movement};    
        - Decrement Deadline (If t, deadline--)
            - void deadlineDec(bool x) { t--;}
        - Increment Deadline
            - void deadlineInc(bool x) {t++;}
        - Check Time
            - int checkTime(char t) {return deadline;}
        - Variables
            - int deadline = 500;
*/
