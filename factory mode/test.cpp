#include <iostream>
#include "Factory.hpp"
using namespace std;

int main()
{
    cout << "creat ship" << endl;
    ship_factory* ship_factory1 = new ship_factory();
    cout << ship_factory1->introduce() << endl;

    cout << "creat car" << endl;
    car_factory* car_factory1 = new car_factory();
    cout << car_factory1->introduce() << endl;

    delete ship_factory1;
    delete car_factory1;
    return 0;
}
