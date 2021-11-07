#include <iostream>
#include "Proxy.hpp"

using namespace std;

void Clientcode(Subject &subject)
{
    subject.Request();
}
int main()
{
    cout << "Client: Executing the client code with a real subject.\n";
    Realsubject* realsubject = new Realsubject();
    Clientcode(*realsubject);
    cout << "\nClient: Executing the client code with a proxy.\n";
    Proxy* proxy = new Proxy(realsubject);
    Clientcode(*proxy);

    delete proxy;
    delete realsubject;
    return 0;
}