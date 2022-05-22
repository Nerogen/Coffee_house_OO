#include "KitchenMachine.h"

KitchenMachine::KitchenMachine(std::string name)
{
	this->name = name;
}

std::string KitchenMachine::getName()
{
	return name;
}