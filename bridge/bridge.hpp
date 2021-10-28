#include <string>
using namespace std;
class implementation
{
    public:
        virtual ~implementation(){};
        virtual string operation() = 0;
};

class implementationA: public implementation
{
    public:
        string operation()
        {
            return "implementation A";
        }
};

class implementationB: public implementation
{
    public:
        string operation()
        {
            return "implementation B";
        }
};

class abstract
{
    protected:
        implementation* _implementation;
    public:
        virtual ~abstract(){}
        virtual string operation()
        {
            return "platform A: operation ==> " + _implementation->operation();
        }
        abstract(implementation* implementationX): _implementation(implementationX){}      
};

class abstractB: public abstract
{
    public:
        virtual ~abstractB(){}
        string operation()
        {
            return "platform B: operation ==> " + _implementation->operation();
        }
        abstractB(implementation* implementationX):abstract(implementationX){}
};