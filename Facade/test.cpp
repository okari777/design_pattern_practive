#include <iostream>
#include "Facade.hpp"
using namespace std;

int main()
{
    subsystem1* s1 = new subsystem1();
    subsystem2* s2 = new subsystem2();
    cout << "create a facade to work with two subsystem" << endl;
    Facade* facade = new Facade(s1, s2);
    cout << facade->Operation();
    delete facade;
    delete s1;
    delete s2;
    return 0;
}