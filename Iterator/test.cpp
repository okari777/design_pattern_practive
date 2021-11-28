#include<iostream>
#include<string>
#include"Iterator.hpp"
using namespace std;

void ClientCode()
{
    cout << "_________Iterator with int_____________\n";
    Container<int> cont;
    for(int i = 0; i < 10; i++)
    {
        cont.Add(i);
    }

    Iterator<int, Container<int>> *it = cont.CreateIterator();
    for(it->First(); !it->IsDone(); it->Next())
    {
        cout << *it->Current() << endl;
    }

    Container<Data> cont2;
    Data a(100), b(1000), c(10000);
    cont2.Add(a);
    cont2.Add(b);
    cont2.Add(c);

    cout << "_________Iterator with custom class_____________\n";
    Iterator<Data, Container<Data>> *it2 = cont2.CreateIterator();
    for(it2->First(); !it2->IsDone(); it2->Next())
    {
        cout << it2->Current()->data() << endl;
    }
    
    delete it;
    delete it2;
}

int main()
{
    ClientCode();
    return 0;
}