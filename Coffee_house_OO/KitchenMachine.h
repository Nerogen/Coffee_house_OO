#pragma once
#include <string>

class KitchenMachine
{
public:
    KitchenMachine() {}
    KitchenMachine(std::string name);
    std::string getName();

private:
    std::string name;
};

