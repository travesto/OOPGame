#include <iostream>
#include <string>
using namespace std;

class game
{
    public:
        game(); //ctor
        ~game(); //dtor
        void input(char z) {};
        string showMap(char m) {};
        void currentLoc() {};
        void deadlineDec(bool x) {};
        void deadlineInc(bool y) {};
        int checkTime(char t) {return deadline;}
    private:
        int deadline;
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
