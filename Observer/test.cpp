#include<iostream>
#include"Observer.hpp"
using namespace std;

int Observer::static_number_ = 0;

void ClientCode()
{
    Subject *subject = new Subject();
    Observer *observer1 = new Observer(subject);
    Observer *observer2 = new Observer(subject);
    Observer *observer3 = new Observer(subject);
    Observer *observer4;
    Observer *observer5;

    subject->CreateMessage("Hello World!");
    observer3->RemoveMeFromList();

    subject->CreateMessage("The weather is hot today!");
    observer4 = new Observer(subject);

    observer2->RemoveMeFromList();
    observer5 = new Observer(subject);

    subject->CreateMessage("My new car is great!");
    observer5->RemoveMeFromList();

    observer4->RemoveMeFromList();
    observer1->RemoveMeFromList();

    delete observer1;
    delete observer2;
    delete observer3;
    delete observer4;
    delete observer5;
}

int main()
{
    ClientCode();
    return 0;
}