#pragma once
#include <string>

class Ingredient
{
public:
    Ingredient();
    Ingredient(std::string name);
    std::string getName();

private:
    std::string name;
};

