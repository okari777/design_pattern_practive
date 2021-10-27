#include <string>
#include <algorithm>
using namespace std;

class target
{
    public:
        virtual ~target(){}
        virtual string service()
        {
            return "Default service A available";
        }
};

class adaptee
{
    public:
        virtual ~adaptee(){}
        string specific_service()
        {
            return "elbaliava B ecivreS";
        }
};

class adapter: public target, public adaptee
{
    public:
        adapter() = default;
        string service() override
        {
            string origin = specific_service();
            reverse(origin.begin(), origin.end());
            return "adapter translated result: " + origin; 
        }
};
