#include <iostream>
#include "Decator.hpp"
using namespace std;

int main()
{
    Concrete_component* base_component = new Concrete_component();
    cout << "create simplement component" << endl;
    cout << base_component->Operation() << endl << endl;

    cout << "create decatorA to wrap the base component" << endl;
    DecatorA* decatorA = new DecatorA(base_component);
    cout << decatorA->Operation() << endl << endl;

    cout << "create decatorB to wrap the decatorA" << endl;
    DecatorB* decatorB = new DecatorB(decatorA);
    cout << decatorB->Operation() << endl << endl;

    delete decatorB;
    delete decatorA;
    delete base_component;
    return 0;
}