#include<string>
#include<iostream>
#include"Template.hpp"
using namespace std;

void ClientCode(Abstract_Class *abstract_class)
{
    abstract_class->Template_Method();
}

int main()
{
    cout << "Same client code can work with different subclass.\n";
    Concrete_Class1 *concrete_class1 = new Concrete_Class1();
    ClientCode(concrete_class1);
    cout << endl;
    cout << "Same client code can work with different subclass.\n";
    Concrete_Class2 *concrete_class2 = new Concrete_Class2();
    ClientCode(concrete_class2);
    delete concrete_class1;
    delete concrete_class2;
    return 0;
}