#include <iostream>
#include <string>
#include <exception>
using namespace std;
//every subclass will have what the command is and what it does
class textHandlerBase
{
    public:
        textHandlerBase(string cmdName);
        ~textHandlerBase() {};
        void execute(string command, string args)
        {
            //cout << "MEOW"; 
            if(command == cmd)
                executeInternal(args);
            else
                next->execute(command,args);
        }
        virtual void executeInternal(string args) = 0;
        textHandlerBase* getNext() {return next;}
        void setNext(textHandlerBase* n);
        
        void addNext(textHandlerBase* add)
        {
            //std::cout << "HELP ";
            if (next) 
            {
                next->addNext(add);
            } 
            else 
            {
                next = add;
            }
            //std::cout << "NOPE ";
        }
        virtual void handle(int i) = 0;
        textHandlerBase* next;
    private:
        string cmd;
        
        
};
class go : public textHandlerBase
{
    public:
        go():textHandlerBase("GO"){};
        ~go();
        void executeInternal(string args);
        void handle(int i);
    private:
};
class look : public textHandlerBase
{
public:
    look():textHandlerBase("LOOK") {};
    ~look();
    void executeInternal(string args);
    void handle(int i);

private:
    
};