#include<string>
#include<iostream>
#include"Memento.hpp"
using namespace std;

void ClientCode()
{
    Originator *originator = new Originator("ad1$#@$-VDFGDASD-4865423.");
    Caretaker *caretaker = new Caretaker(originator);
    caretaker->Backup();
    originator->Dosomething();
    caretaker->Backup();
    originator->Dosomething();
    caretaker->Backup();
    originator->Dosomething();
    cout << endl;
    caretaker->Showhistory();
    cout << "\nClient: Now, let's rollback!\n\n";
    caretaker->Undo();
    cout << "\nClient: Once more!\n\n";
    caretaker->Undo();
    
    delete caretaker;
    delete originator;
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    ClientCode();
    return 0;
}