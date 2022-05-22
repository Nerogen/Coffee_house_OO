#include "Recipe.h"


Recipe Recipe::addStep(RecipeStep step)
{
	stepList.push_back(step);
	return *this;
}

std::deque<RecipeStep> Recipe::getStepList()
{
	return stepList;
}
