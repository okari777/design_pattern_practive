#include <iostream>
#include <string>
#include "Chain.hpp"
#include <vector>
using namespace std;

void ClientCode(Handler &handler)
{
    vector<string> food = {"Nut", "Banana", "Cup of coffee"};
    for(const string &f:food)
    {
        cout << "Client: Who wants a " << f << "?\n";
        string result = handler.Handle(f);
        if(!result.empty())
        {
            cout << " " << result;
        }
        else
        {
            cout << " " << f << " wat left untouched.\n";
        }
    }
}

int main()
{
    Monkeyhandler* monkey = new Monkeyhandler();
    Squirrelhandler* squirrel = new Squirrelhandler();
    Doghandler* dog = new Doghandler();
    monkey->Setnext(squirrel)->Setnext(dog);

    cout << "Chain: Monkey -> Squirrel -> Dog.\n";
    ClientCode(*monkey);
    cout << endl;
    cout << "SubChain: Squirrel -> Dog.\n";
    ClientCode(*squirrel);

    delete monkey;
    delete squirrel;
    delete dog;
    return 0;
}