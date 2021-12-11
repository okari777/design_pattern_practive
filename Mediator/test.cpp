#include<iostream>
#include<string>
#include"Mediator.hpp"
using namespace std;

void ClientCode()
{
    Component1 *c1 = new Component1();
    Component2 *c2 = new Component2();
    ConcreteMediator *mediator = new ConcreteMediator(c1, c2);
    cout << "Client triggers operation A.\n";
    c1->DoA();
    cout << endl;

    cout << "Client triggers operation D.\n";
    c2->DoD();

    delete c1;delete c2;delete mediator;
}

int main()
{
    ClientCode();
    return 0;
}