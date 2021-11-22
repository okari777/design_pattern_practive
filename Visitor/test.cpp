#include<string>
#include<vector>
#include"Visitor.hpp"
using namespace std;

void ClientCode(vector<Component*> components, Visitor *visitor)
{
    for(Component *component: components)
    {
        component->Accept(visitor);
    }
}

int main()
{
    vector<Component*> components = {new ConcreteComponentA(), new ConcreteComponentB()};
    cout << "The clinet code works with all visitors via the base visitor interface\n";
    ConcreteVisitor1* visitor1 = new ConcreteVisitor1();
    ClientCode(components, visitor1);
    cout << endl;
    cout << "It allows the same client code to work with different types of visitors\n";
    ConcreteVisitor2* visitor2 = new ConcreteVisitor2();
    ClientCode(components, visitor2);
    for(Component* component: components)
        delete component;
    delete visitor1;
    delete visitor2;
    return 0;
}