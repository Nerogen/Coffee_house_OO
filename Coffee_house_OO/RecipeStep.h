#pragma once
#include "Ingredient.h"
#include "KitchenMachine.h"

class RecipeStep
{
public:
    RecipeStep(Ingredient ingredient, int amount, KitchenMachine machine, long time);
    std::string getIngredient();
    int getAmount();
    KitchenMachine getMachine();
    long getTime();

private:
    Ingredient ingredient;
    int amount;
    KitchenMachine machine;
    long time;
};

