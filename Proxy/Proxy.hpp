#include <iostream>
using namespace std;

class Subject
{
    public:
        virtual void Request() = 0;
};

class Realsubject: public Subject
{
    public:
        void Request()
        {
            cout << "Realsubject: Handling request.\n";
        }
};

class Proxy: public Subject
{
    private:
        Realsubject* _realsubject;

        bool Chkaccess()
        {
            cout << "Proxy: Checking access prior to firing a real request.\n";
            return true;
        }
        void Logaccess()
        {
            cout << "Proxy: Logging the time of request.\n";
        }
    public:
        Proxy(Realsubject* realsubject): _realsubject(new Realsubject(*realsubject)){}
        ~Proxy()
        {
            delete _realsubject;
        }
        void Request()
        {
            if(this->Chkaccess())
            {
                this->_realsubject->Request();
                this->Logaccess();
            }
        }
};