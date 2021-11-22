#include<string>
#include<iostream>
using namespace std;

class ConcreteComponentA;
class ConcreteComponentB;
class Visitor
{
    public:
        virtual void VisitConcreteComponentA(ConcreteComponentA *componentA) = 0;
        virtual void VisitConcreteComponentB(ConcreteComponentB *componentB) = 0;
};

class Component
{
    public:
        virtual ~Component(){}
        virtual void Accept(Visitor *visitor) = 0;
};

class ConcreteComponentA: public Component
{
    public:
        void Accept(Visitor *visitor)
        {
            visitor->VisitConcreteComponentA(this);
        }
        string ExclusiveMethodOfConcreteComponentA()
        {
            return "A";
        }
};

class ConcreteComponentB: public Component
{
    public:
        void Accept(Visitor *visitor)
        {
            visitor->VisitConcreteComponentB(this);
        }
        string ExclusiveMethodOfConcreteComponentB()
        {
            return "B";
        }
};

class ConcreteVisitor1: public Visitor
{
    public:
        void VisitConcreteComponentA(ConcreteComponentA *componentA)
        {
            cout << componentA->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1\n";
        }
        void VisitConcreteComponentB(ConcreteComponentB *componentB)
        {
            cout << componentB->ExclusiveMethodOfConcreteComponentB() << " + ConcreteVisitor1\n";
        }
};

class ConcreteVisitor2: public Visitor
{
    public:
        void VisitConcreteComponentA(ConcreteComponentA *componentA)
        {
            cout << componentA->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2\n";
        }
        void VisitConcreteComponentB(ConcreteComponentB *componentB)
        {
            cout << componentB->ExclusiveMethodOfConcreteComponentB() << " + ConcreteVisitor2\n";
        }
};
