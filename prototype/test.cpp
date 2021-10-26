#include "prototype.hpp"
#include <iostream>
#include <mutex>
using namespace std;


int main()
{
    prototype_factory* PF = new prototype_factory();
    cout << "123" << endl;
    cout << "create new object from type 1" << endl;
    prototype* new_p = PF->create_prototype(prototype_0);
    new_p->set_no(10);
    delete new_p;

    cout << "create new object from type 2" << endl;
    new_p = PF->create_prototype(prototype_1);
    new_p->set_no(20);
    delete new_p;

    delete PF;
    return 0;

}