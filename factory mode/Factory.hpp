#include <string>
using namespace std;
class Vehicle
{
    public:
        string trans_way;   //transportation way
        virtual string transportation_way() = 0;
        virtual ~Vehicle(){}
};

class ship: public Vehicle
{
    public:
        string transportation_way() override
        {
            trans_way = "on the sea";
            return trans_way;
        }
};

class car: public Vehicle
{
    public:
        string transportation_way() override
        {
            trans_way = "on road";
            return trans_way;
        }
};

class Factory
{
    public:
        
        virtual Vehicle* create_vehicle() const = 0;
        string introduce()
        {
            Vehicle* vehicle1 = this->create_vehicle();
            string result = vehicle1->transportation_way();
            delete vehicle1;
            return result;
        }
        virtual ~Factory(){}
};

class ship_factory: public Factory
{
    public:
        Vehicle* create_vehicle() const
        {
            return new ship();
        }
};

class car_factory: public Factory
{
    public:
        Vehicle* create_vehicle() const
        {
            return new car();
        }
};