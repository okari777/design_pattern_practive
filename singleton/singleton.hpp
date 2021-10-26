#include <string>
#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
    private:
        static Singleton* singleton;
        static mutex _mutex;
        int _value;
        Singleton(int value): _value(value){}
    public:
        ~Singleton(){}
        Singleton(const Singleton &) = delete;
        Singleton& operator=(const Singleton &) = delete;

        static Singleton* get_instance(int value);
        int get_value()
        {
            return _value;
        }
};

Singleton* Singleton::singleton = nullptr;
mutex Singleton::_mutex;


Singleton* Singleton::get_instance(int value)
{
    lock_guard<mutex> lck(_mutex);
    if(singleton == nullptr)
    {
        singleton = new Singleton(value);
    }
    return singleton;
}

