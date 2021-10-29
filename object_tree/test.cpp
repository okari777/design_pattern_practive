#include <iostream>
#include "tree.hpp"

using namespace std;

int main()
{
    cout << "create simple item" << endl;
    Component* item = new Leaf();
    cout << item->Operation() << endl << endl;

    cout << "create complex box" << endl;
    Component* bigbox = new Branch();
    Component* small_box1 = new Branch();
    Component* small_box2 = new Branch();

    Component* item2 = new Leaf();
    Component* item3 = new Leaf();

    small_box1->Add(item);
    small_box1->Add(item2);
    small_box2->Add(item3);

    bigbox->Add(small_box1);
    bigbox->Add(small_box2);

    cout << bigbox->Operation() << endl << endl;

    cout << "remove one box" << endl;

    bigbox->Remove(small_box2);
    delete small_box2;
    cout << bigbox->Operation() << endl << endl;

    delete bigbox;
    delete small_box1;
    delete item;
    delete item2;
    delete item3;

    return 0;
    
}