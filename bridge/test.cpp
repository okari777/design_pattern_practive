#include <iostream>
#include "bridge.hpp"
using namespace std;

int main()
{
    implementation* _implementation = new implementationA();
    abstract* _abstract = new abstract(_implementation);
    cout << _abstract->operation() << endl;

    delete _implementation;
    delete _abstract;

    _implementation = new implementationB();
    _abstract = new abstractB(_implementation);
    cout << _abstract->operation() << endl;
    return 0;
}