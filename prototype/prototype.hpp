#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

enum PN
{
    prototype_0,
    prototype_1
};

class prototype
{
    protected:
        string prototype_name;
        int number;
    public:
        virtual ~prototype(){ cout << "delete prototype: (" << prototype_name << ", " << number << ")" << endl;}
        prototype(string name, int n): prototype_name(name), number(n){}
        virtual prototype* clone() = 0;
        virtual void set_no(int n)
        {
            this->number = n;
            cout << "my prototype name is " << prototype_name << " and number is " << number << endl;
        } 
};

class concrete_prototype1: public prototype
{
    public:
        concrete_prototype1(string name, int n): prototype(name, n){}
        prototype* clone()
        {
            return new concrete_prototype1(*this);
        }
};

class concrete_prototype2: public prototype
{
    public:
        concrete_prototype2(string name, int n): prototype(name, n){}
    prototype* clone()
    {
        return new concrete_prototype2(*this);
    }
};


class prototype_factory
{
    private:
        unordered_map<PN, prototype*> prototype_registration;
    public:
        prototype_factory()
        {
            prototype_registration[prototype_0] = new concrete_prototype1("prototype_0", 0);
            prototype_registration[prototype_1] = new concrete_prototype2("prototype_1", 1);
        }

        prototype* create_prototype(PN pn)
        {
            return prototype_registration[pn]->clone();
        }

        ~prototype_factory()
        {
            delete prototype_registration[prototype_0];
            delete prototype_registration[prototype_1];
            cout << "close prototype factory" << endl;
        }
};