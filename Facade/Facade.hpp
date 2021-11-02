#include <string>
#include <iostream>
using namespace std;
class subsystem1
{
    public:
        string Operation1()
        {
            return "link to subsystem1\n";
        }
        string Operation2()
        {
            return "subsystem1 start working\n";
        }
};

class subsystem2
{
    public:
        string Operation1()
        {
            return "link to subsystem2\n";
        }
        string Operation2()
        {
            return "subsystem2 start working\n";
        }
};

class Facade
{
    protected:
        subsystem1* _s1;
        subsystem2* _s2;
    public:
        Facade(subsystem1* s1 = nullptr, subsystem2* s2 = nullptr)
        {
            _s1 = s1? : new subsystem1();
            _s2 = s2? : new subsystem2();
        }
        string Operation()
        {
            string result = "";
            result = _s1->Operation1() + _s1->Operation2() + _s2->Operation1() + _s2->Operation2();
            return result;
        }
        ~Facade()
        {
            cout << "delete link to subsystem" << endl;
            delete _s1;
            delete _s2;
        }
};