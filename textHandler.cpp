#include <iostream>
using namespace std;


textHandlerBase::textHandlerBase(string command)
{
    next = 0;
    cmd = command;
}
textHandlerBase::~textHandlerBase() {};
void textHandlerBase::setNext(textHandlerBase* setN)
{
    next = setN;
}
void textHandlerBase::addNext(textHandlerBase* add)
{
            if (next) {
                next->addNext(add);
            } else {
                next = add;
            }
}
void go::execute(string com, string args)
{
    if (com == "GO")
    {
        
    }
    else
    {
        textHandlerBase::handle()
    }
}
void go::handle(int i)
{
    next->handle(i);
}