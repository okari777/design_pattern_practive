#include <iostream>
#include "builder.hpp"
using namespace std;

int main()
{
    director *director1 = new director();
    wood_builder* builder1 = new wood_builder();
    director1->set_builder(builder1);
    cout << "gen simple house component" << endl;
    director1->simple_feature();
    house* h = builder1->get_product();
    h->list_components();
    delete h;
    
    cout << "gen all feature house" << endl;
    director1->all_feature();
    h = builder1->get_product();
    h->list_components();

    cout << "gen feature BC house" << endl;
    director1->set_featureBC();
    h = builder1->get_product();
    h->list_components();
    delete builder1;
    delete director1;
    return 0;
}