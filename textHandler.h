#include <iostream>
#include <string>
using namespace std;
//every subclass will have what the command is and what it does
class textHandlerBase
{
    public:
        textHandlerBase(){};
        ~textHandlerBase(){};
        void execute(string command, string args)
        {
            if(command == cmd)
                executeInternal(args);
            else
                next->execute(command,args);
        }
        virtual void executeInternal(string args) = 0;
        void setNext(textHandlerBase* n);
        void addNext(textHandlerBase* n);
        virtual void handle(int i) = 0;
    private:
        string cmd;
        textHandlerBase* next;
};
class go : public textHandlerBase
{
public:
    go(){};
    ~go() {};
    void executeInternal(string args) {};
    void handle(int i) {};
private:
};
