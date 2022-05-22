#pragma once
#pragma once
#include <iostream>
#include "CoffeeHouse.h"
#include "Ingredient.h"
#include "KitchenMachine.h"
#include "Product.h"
#include "Recipe.h"
#include "RecipeStep.h"
#include "Settings.h"
#include "Visitor.h"
#include "VisitorGenerator.h"
#include "VisitorRequestStatus.h"

class Application
{
public:
	Application();
protected:
	CoffeeHouse build();
};

