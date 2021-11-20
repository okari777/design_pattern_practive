#include<iostream>
#include<string>
using namespace std;

class Abstract_Class
{
    protected:
        void Base_Operation1()
        {
            cout << "Abstract_Class: I am doing the bulk of the wrok.\n";
        }
        void Base_Operation2()
        {
            cout << "Abstract_Class: But I let subclasses override some operations.\n";
        }
        void Base_Operation3()
        {
            cout << "Abstract_Class: But I am doing the bulk of the work anyway.\n";
        }
        virtual void Require_Operation1() = 0;
        virtual void Require_Operation2() = 0;
        virtual void Hook1(){}
        virtual void Hook2(){}
    public:
        void Template_Method()
        {
            this->Base_Operation1();
            this->Require_Operation1();
            this->Base_Operation2();
            this->Hook1();
            this->Require_Operation2();
            this->Base_Operation3();
            this->Hook2();
        }
};

class Concrete_Class1: public Abstract_Class
{
    protected:
        void Require_Operation1()
        {
            cout << "Concrete_Class1: Implemented Operation1.\n";
        }
        void Require_Operation2()
        {
            cout << "Concrete_Class1: Implemented Operation2.\n";
        }
};

class Concrete_Class2: public Abstract_Class
{
    protected:
        void Require_Operation1()
        {
            cout << "Concrete_Class2: Implemented Operation1.\n";
        }
        void Require_Operation2()
        {
            cout << "Concrete_Class2: Implemented Operation2.\n";
        }
        void Hook1()
        {
            cout << "Concrete_Class2: Override Hook1.\n";
        }
};