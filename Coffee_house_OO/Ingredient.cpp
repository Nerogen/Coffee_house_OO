#include "Ingredient.h"

Ingredient::Ingredient()
{
}

Ingredient::Ingredient(std::string name)
{
	this->name = name;
}

std::string Ingredient::getName()
{
	return name;
}

