#pragma once
#include "RecipeStep.h"
#include <deque>

class Recipe
{
public:
    Recipe addStep(RecipeStep step);
    std::deque<RecipeStep> getStepList();

private:
    std::deque<RecipeStep> stepList;
};

