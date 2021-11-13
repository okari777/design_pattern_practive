#include<string>
#include<ctime>
#include<iostream>
#include<vector>
using namespace std;

class Memento
{
    public:
        virtual string Getname() = 0;
        virtual string date() = 0;
        virtual string state() = 0;
};

class ConcreteMemento: public Memento
{
    private:
        string state_;
        string date_;

    public:
        ConcreteMemento(string state)
        {
            this->state_ = state;
            time_t now = time(NULL);
            this->date_ = ctime(&now);
        }
        string state()
        {
            return this->state_;
        }
        string Getname()
        {
            return this->date_ + "/ (" + this->state_.substr(0,9) + "...)";
        }
        string date()
        {
            return this->date_;
        }
};

class Originator
{
    private:
        string state_;
        string GenerateRandomString(int length = 10)
        {
            const char alphanum[] = 
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUWXYZ"
                "abcdefghijklmnopqrstuwxyz";
            int string_len = sizeof(alphanum)-1;
            string random_string;
            for(int i = 0; i < length; i++)
                random_string += alphanum[rand()%string_len];
            return random_string;
        }
    public:
        Originator(string state):state_(state)
        {
            cout << "Originator: My initial state is: " << this->state_ << endl;
        }
        void Dosomething()
        {
            cout << "Originator: I'm doing something important.\n";
            this->state_ = this->GenerateRandomString(30);
            cout << "Originator: and my state has changed to : " << this->state_ << endl;
        }

        Memento* Save()
        {
            return new ConcreteMemento(this->state_);
        }
        void Restore(Memento *memento)
        {
            this->state_ = memento->state();
            cout << "Originator: My state has changed to : " << this->state_ << endl;
        }
};

class Caretaker
{
    private:
        vector<Memento*> mementos;
        Originator *originator_;
    public:
        Caretaker(Originator* originator): originator_(originator){}
    
    void Backup()
    {
        cout << "\nCaretaker: Saving Originator's state...\n";
        this->mementos.push_back(this->originator_->Save());
    }
    void Undo()
    {
        if(this->mementos.empty())
            return;
        Memento *memento = this->mementos.back();
        this->mementos.pop_back();
        cout << "Caretaker: Restoring state to: " << memento->Getname() << endl;
        try{
            this->originator_->Restore(memento);
        }catch(...){
            this->Undo();
        }
    }

    void Showhistory()
    {
        cout << "Caretaker: Here's the list of mementos:\n";
        for(Memento *memento:this->mementos)
        {
            cout << memento->Getname() << endl;
        }
    }
};