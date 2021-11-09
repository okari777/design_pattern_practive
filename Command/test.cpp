#include<string>
#include<iostream>
#include"Command.hpp"
using namespace std;

int main()
{
    Invoker *invoker = new Invoker();
    invoker->SetOnStart(new Simple_Command("Say Hi!"));
    Receiver *receiver = new Receiver();
    invoker->SetOnFinish(new Complex_Commnad(receiver, "Send mail", "Save report"));
    invoker->Do_Something_Important();
    delete invoker;
    delete receiver;
    return 0;
}