#include <iostream>
#include "singleton.hpp"
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

mutex log_mutex;
void test_10()
{
    this_thread::sleep_for(chrono::seconds(1));
    Singleton* singleton = Singleton::get_instance(10);
    lock_guard<mutex> lck(log_mutex);
    cout << "object address " << singleton << endl;
    cout << "object value " << singleton->get_value() << endl;
    return;
}

void test_20()
{
    this_thread::sleep_for(chrono::seconds(1));
    Singleton* singleton = Singleton::get_instance(20);
    lock_guard<mutex> lck(log_mutex);
    cout << "object address " << singleton << endl;
    cout << "object value " << singleton->get_value() << endl;
    return;
}

int main()
{
    thread t1(test_10);
    thread t2(test_20);

    t1.join();
    t2.join();
    return 0;
}