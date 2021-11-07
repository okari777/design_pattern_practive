#include <string>
#include <iostream>
using namespace std;

class Handler
{
    public:
        virtual Handler* Setnext(Handler*) = 0;
        virtual string Handle(string) = 0;
};

class Abstracthandler: public Handler
{
    private:
        Handler* _next_handler;
    public:
        Abstracthandler(): _next_handler(nullptr){}
        Handler* Setnext(Handler* handler)
        {
            this->_next_handler = handler;
            return handler;
        }
        string Handle(string request)
        {
            if(this->_next_handler)
            {
                return this->_next_handler->Handle(request);
            }
            return "";
        }
};

class Monkeyhandler: public Abstracthandler
{
    public:
        string Handle(string request)
        {
            if(request == "Banana")
            {
                return "Monkey: I'll eat the " + request +".\n";
            }
            else
            {
                return Abstracthandler::Handle(request);
            }
        }
};

class Squirrelhandler: public Abstracthandler
{
    public:
        string Handle(string request)
        {
            if(request == "Nut")
            {
                return "Squirrel: I'll eat the "+ request +".\n";
            }
            else
            {
                return Abstracthandler::Handle(request);
            }
        }
};

class Doghandler: public Abstracthandler
{
    public:
        string Handle(string request)
        {
            if(request == "MeatBall")
            {
                return "Dog: I'll eat the " + request +".\n";
            }
            else
            {
                return Abstracthandler::Handle(request);
            }
        }
};