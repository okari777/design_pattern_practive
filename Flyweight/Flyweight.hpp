#include <string>
#include <iostream>
#include <unordered_map>
#include <initializer_list>

using namespace std;

struct SharedState
{
    string _brand;
    string _model;
    string _color;

    SharedState(string &brand, string &model, string &color): _brand(brand), _model(model), _color(color){}

    friend ostream& operator<<(ostream& os, SharedState &ss)
    {
        return os << "[ " << ss._brand << ", " << ss._model << ", " << ss._color << " ]";
    }
};

struct UniqueState
{
    string _owner;
    string _plates;

    UniqueState(string &owner, string plates): _owner(owner), _plates(plates){}

    friend ostream& operator<<(ostream& os, UniqueState& us)
    {
        return os << "[ " << us._owner << ", " << us._plates << " ]";
    }
};

class Flyweight
{
    private:
        SharedState* _shared_state;
    public:
        Flyweight(SharedState *sharedstate): _shared_state(new SharedState(*sharedstate)){}
        Flyweight(Flyweight& flyweight): _shared_state(new SharedState(*(flyweight._shared_state))){}
        ~Flyweight()
        {
            delete _shared_state;
        }
        const SharedState* shared_state()
        {
            return _shared_state;
        }
        void Operation(UniqueState& unique_state)
        {
            cout << "Flyweight: Displaying shared (" << *_shared_state << ") and unique (" << unique_state << ") state.\n";
        }
};

class FlyweightFactory
{
    private:
        unordered_map<string, Flyweight> _flyweights;
        
        string Getkey(SharedState ss)
        {
            return ss._brand + "_" + ss._model + "_" + ss._color;
        }
    
    public:
        FlyweightFactory(initializer_list<SharedState> shared_states)
        {
            for(SharedState ss:shared_states)
            {
                this->_flyweights.insert(make_pair<string, Flyweight>(this->Getkey(ss), Flyweight(&ss)));
            }
        }
        Flyweight GetFlyweight(SharedState shared_state)
        {
            string key = this->Getkey(shared_state);
            if(this->_flyweights.find(key) == this->_flyweights.end())
            {
                cout << "FlyweightFactory: can't find a flyweight, creating new one.\n";
            }
            else
            {
                cout << "flyweightFactory: Reusing existing flyweight.\n";
            }
            return this->_flyweights[key];
        }

        void ListFlyweights()
        {
            int length = this->_flyweights.size();
            cout << "\nFlyweightFactory: I have " << length << " flyweight\n";
            for(auto p: this->_flyweights)
            {
                cout << p.first << endl;
            }
        }
};

