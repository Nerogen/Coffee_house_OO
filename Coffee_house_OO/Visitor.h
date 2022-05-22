#pragma once
#include "CoffeeHouse.h"

class Visitor
{
public: 
    static int getChoice(int number_of_products)
    {
        srand(time(NULL));
        return rand() % 3 + number_of_products;
    }
};

