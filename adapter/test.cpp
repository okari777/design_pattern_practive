#include <iostream>
#include "adapter.hpp"
using namespace std;

int main()
{
    cout << "default target service" << endl;
    target* object = new target();
    cout << object->service() << endl;

    cout << "An adaptee has weird service" << endl;
    adaptee* _adaptee = new adaptee();
    cout << _adaptee->specific_service() << endl;

    cout << "use adapter to translate" << endl;
    adapter* _adapter = new adapter();
    cout << _adapter->service() << endl;

    delete object;
    delete _adaptee;
    delete _adapter;
    return 0;
}