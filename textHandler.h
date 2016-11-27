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
        virtual void execute(string command, string args)
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
class no : public textHandlerBase
{
    public:
        no():textHandlerBase("NO"){};
        ~no();
        void executeInternal(string args);
        void handle(int i);
    private:
    
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
class check : public textHandlerBase
{
    public:
        check() : textHandlerBase("CHECK") {};
        ~check();
        void executeInternal(string args);
        void handle(int i);
}; 
class showMap : public textHandlerBase
{
    public:
        showMap() : textHandlerBase("MAP") {};
        ~showMap();
        void executeInternal(string args);
        void handle(int i);
};
class quit : public textHandlerBase
{
    public:
        quit() : textHandlerBase("QUIT") {};
        ~quit() {};
        void executeInternal(string command);
        void handle(int i) {};
};
class examine : public textHandlerBase
{
public:
	examine() : textHandlerBase("EXAMINE") {};
	~examine();
	void executeInternal(string args);
	void handle(int i);
};
class use : public textHandlerBase
{
public:
	use() : textHandlerBase("USE") {};
	~use();
    void executeInternal(string args);
	void handle(int i);
};
class invalid : public textHandlerBase
{
    public:
        invalid() : textHandlerBase("") {};
        ~invalid() {};
        void execute(string command, string args);
        void executeInternal(string args) {};
        void handle(int i) {};
};