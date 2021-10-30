#include <string>
using namespace std;

class Component
{
    public:
        virtual ~Component(){}
        virtual string Operation() = 0;
};

class Concrete_component: public Component
{
    public:
        string Operation()
        {
            return "Concrete component";
        }
};

class Decator: public Component
{
    protected:
        Component* _component;
    public:
        Decator(Component* component): _component(component){}
        string Operation()
        {
            return _component->Operation();
        }
};

class DecatorA: public Decator
{
    public:
        DecatorA(Component* component): Decator(component){}
        string Operation()
        {
            return "DecatorA( " + Decator::Operation() + " )";
        }
};

class DecatorB: public Decator
{
    public:
        DecatorB(Component* component): Decator(component){}
        string Operation()
        {
            return "DecatorB( " + Decator::Operation() + " )";
        }
};