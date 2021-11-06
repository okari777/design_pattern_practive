#include <iostream>
#include <string>
#include "Flyweight.hpp"

using namespace std;

void AddCarDataBase(FlyweightFactory &ff, string plates, string owner, string brand, string model, string color)
{
    cout << "\nClient: Adding a car to database\n";
    Flyweight &flyweight = ff.GetFlyweight({brand, model, color});
    flyweight.Operation({owner, plates});
}

int main()
{
    FlyweightFactory *factory = new FlyweightFactory({{"Chevrolet", "Camaro2018", "pink"}, {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"}});
    factory->ListFlyweights();

    AddCarDataBase(*factory,"CL234IR","James Doe","BMW","M5","red");

    AddCarDataBase(*factory,
                            "CL234IR",
                            "James Doe",
                            "BMW",
                            "X1",
                            "red");
    factory->ListFlyweights();
    delete factory;

    return 0;
}