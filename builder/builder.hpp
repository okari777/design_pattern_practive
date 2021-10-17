#include <vector>
#include <string>
#include <iostream>
using namespace std;

class house
{
    public:
        vector<string> components;
        void list_components()
        {
            for(vector<string>::iterator iter = components.begin(); iter < components.end(); iter++)
            {
                if(iter != components.end()-1)
                    cout << *iter << ", ";
                else   
                    cout << *iter << endl;
            }
        }
        virtual ~house()
        {
            cout << "delete house" << endl;
        }
};

class builder
{
    public:
        virtual void gen_component1() = 0;
        virtual void gen_component2() = 0;
        virtual void gen_component3() = 0;
        ~builder()
        {
            cout << "delete base builder" << endl;
        }
};

class wood_builder: public builder
{
    private:
        house* product;
    public:
        wood_builder()
        {
            this->product_reset();
        }
        void product_reset()
        {
            this->product = new house();
        }
        house* get_product()
        {
            house* product1 = this->product;
            this->product_reset();
            return product1;
        }
        void gen_component1()
        {
            this->product->components.push_back("wood_floor");
        }
        void gen_component2()
        {
            this->product->components.push_back("wood_door");
        }
        void gen_component3()
        {
            this->product->components.push_back("wood wall");
        }
        ~wood_builder()
        {
            cout << "delete wood builder" << endl;
            delete product;
        }
};

class director
{
    private:
        builder* builder1;
    public:
        void set_builder(builder* b)
        {
            this->builder1 = b;
        }

        void simple_feature()
        {
            this->builder1->gen_component1();
        }

        void all_feature()
        {
            this->builder1->gen_component1();
            this->builder1->gen_component2();
            this->builder1->gen_component3();
        }

        void set_featureBC()
        {
            this->builder1->gen_component2();
            this->builder1->gen_component3();
        }
};
