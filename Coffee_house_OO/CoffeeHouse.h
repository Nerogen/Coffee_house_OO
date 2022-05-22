#pragma once
#include <map>
#include <deque>
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

class CoffeeHouse
{
public:
    CoffeeHouse() {}

    void run() {

       while (currentTime < Settings::CLOSING_TIME) {
            std::cout << "Current rating sum: " << ratingSum << std::endl;
            std::cout << "Current rating amount" << ratingAmount << std::endl;
            if (Settings::VISITOR_GENERATE_TIME_PERIOD % currentTime == 0) {
                for (int i = 0; i < 3; ++i) {
                    srand(time(NULL));
                    queue.push_back(rand() % 3 + menuList.size());
                }
            }

            ratingSum += work();
            ratingSum += work();
            
            if (Settings::VISITOR_WAITING_TIME % currentTime == 0) {
                queue.pop_front();
            }

            ratingAmount += 2;

            currentTime += Settings::TICK_TIME;
        }
    }

    int work() {
        if (!queue.empty()) {
            int num = queue[0];
            auto it = dessertMap.begin();
            for (; it != dessertMap.end(); it++)
                if (((*it).first == menuList[num]) && it->second >= 1) {
                    it->second -= 1;
                    currentTime += Settings::TICK_TIME;
                    return 5;
                }

            auto ite = recipeMap.begin();
            for (; ite != recipeMap.end(); ite++)
                if (((*ite).first == menuList[num])) {
                    auto steps = ite->second.getStepList();
                    if (makeStep(steps) == 1) {
                        return 5;
                        currentTime += Settings::TICK_TIME;
                    }
                    else {
                        return 1;
                    }
                }
            return 1;
        }
        else {
            return 0;
        }
    }

    int makeStep(std::deque<RecipeStep>& steps) {
        for (int i = 0; i < steps.size(); ++i) {
            if (takeIngredients(steps[i].getIngredient(), steps[i].getAmount())) {
                currentTime += steps[i].getTime();
                return 1;
            }
            else{
                return 0;
            }
        }
    }

    float getAvgRating() {
        return (float)ratingSum / (float)ratingAmount;
    }

    void addDessert(Product dessert, int amount) {
        dessertMap[dessert.getName()] = amount;
        menuList.push_back(dessert.getName());
    }

    void addRecipe(Product product, Recipe recipe) {
        recipeMap[product.getName()] = recipe;
        menuList.push_back(product.getName());
    }

    void addIngredient(Ingredient ingredient, int amount) {
         ingredientMap[ingredient.getName()] = amount;
    }

    std::deque<std::string> getMenu() {
        return menuList;
    }

    std::map<std::string, int> getDeserts() {
        return dessertMap;
    }

    std::map<std::string, Recipe> getRecipeMap() {
        return recipeMap;
    }

    std::map<std::string, int> getIngredients() {
        return ingredientMap;
    }

    bool takeIngredients(std::string name, int number_of) {
        auto it = ingredientMap.begin();
        for (; it != ingredientMap.end(); it++)
            if (((*it).first == name) && it->second >= number_of) {
                it->second -= number_of;
                return true;
            }
        return false;
    }

private:
    std::deque<int> queue;
    std::map<std::string, int> dessertMap;
    std::map<std::string, Recipe> recipeMap;
    std::deque<std::string> menuList;
    std::map<std::string, int> ingredientMap;
    long currentTime = 1;
    long ratingSum = 0;
    long ratingAmount = 0;
};

