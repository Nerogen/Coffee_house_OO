#include "RecipeStep.h"


RecipeStep::RecipeStep(Ingredient ingredient, int amount, KitchenMachine machine, long time)
{
    this->ingredient = ingredient;
    this->amount = amount;
    this->machine = machine;
    this->time = time;
}

std::string RecipeStep::getIngredient()
{
    return ingredient.getName();
}

int RecipeStep::getAmount()
{
    return amount;
}

KitchenMachine RecipeStep::getMachine()
{
    return machine;
}

long RecipeStep::getTime()
{
    return time;
}