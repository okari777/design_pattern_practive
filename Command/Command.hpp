#include<string>
#include<iostream>
using namespace std;

class Command
{
    public:
        virtual ~Command(){}
        virtual void Execute() = 0;
};

class Simple_Command:public Command
{
    private:
        string payload;
    public:
        Simple_Command(string s): payload(s){}
        void Execute()
        {
            cout << "Simple_Commnad: See, I can do simple things like printing ( " << payload << " ).\n";
        }
};

class Receiver
{
    public:
        void Do_Something(string &s1)
        {
            cout << "Receiver: Working on ( " << s1 << " ).\n";
        }
        void Do_Somethinge_else(string &s2)
        {
            cout << "Receiver: Also working on ( " << s2 << " ).\n";
        }
};

class Complex_Commnad: public Command
{
    private:
        Receiver* _receiver;
        string s1,s2;
    public:
        Complex_Commnad(Receiver* receiver, string a, string b): _receiver(receiver), s1(a), s2(b){}

        void Execute()
        {
            cout << "Complex_command: Complex stuff should be done by a receiver object.\n";
            this->_receiver->Do_Something(s1);
            this->_receiver->Do_Somethinge_else(s2);
        }
        ~Complex_Commnad()
        {
            delete _receiver;
        }
};

class Invoker
{
    private:
        Command *on_start, *on_finish;
    public:
        ~Invoker()
        {
            delete on_start;
            delete on_finish;
        }
        void SetOnStart(Command *command)
        {
            this->on_start = command;
        }
        void SetOnFinish(Command *command)
        {
            this->on_finish = command;
        }

        void Do_Something_Important()
        {
            cout << "Invoker: Does anybody want something done before I begin?\n";
            if(this->on_start)
            {
                this->on_start->Execute();
            }
            cout << "Invoker: ...doing something really important...\n";
            cout << "Invoker: Does anybody want something done after I finish?\n";
            if(this->on_finish)
            {
                this->on_finish->Execute();
            }
        }
};