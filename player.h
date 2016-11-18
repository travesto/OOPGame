#include <iostream>
#include <string>

using namespace std;

class player
{
public:
    ~player();
private:
    player();
    player(player const& copy) {};
    static player* playerInstance;
    friend int dummy();
};