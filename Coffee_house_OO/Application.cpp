#include "Application.h"

Application::Application() {
    CoffeeHouse model;
    std::cout << "Start modeling" << std::endl;
    model.run();
    std::cout << "Finish rating: " << model.getAvgRating() << std::endl;
}

CoffeeHouse Application::build()
{
    CoffeeHouse model;

    Product cookie("Печенье", false);
    Product pastry("Пирожное", false);
    Product cake("Торт", false);
    model.addDessert(cookie, 20);
    model.addDessert(pastry, 20);
    model.addDessert(cake, 20);

    Ingredient coffeeBeans("Кофейные зерна");
    Ingredient milk("Молоко");
    Ingredient syrup("Сироп");

    model.addIngredient(coffeeBeans, 1000);
    model.addIngredient(milk, 200);
    model.addIngredient(syrup, 100);

    KitchenMachine coffeeMachine("Кофе машина");
    KitchenMachine cappuccinatore("Капучинатор");

    model.addRecipe(
       Product("Эспрессо", true),
       Recipe().addStep(RecipeStep(coffeeBeans, 5, coffeeMachine, 120))
    );
    model.addRecipe(
        Product("Раф кофе", true),
        Recipe().addStep(RecipeStep(syrup, 10, KitchenMachine(), 10)).addStep(RecipeStep(coffeeBeans, 5, coffeeMachine, 120)).addStep(RecipeStep(milk, 10, cappuccinatore, 100))
    );
    model.addRecipe(
        Product("Каппучино", true),
        Recipe().addStep(RecipeStep(coffeeBeans, 5, coffeeMachine, 120)).addStep(RecipeStep(milk, 10, KitchenMachine(), 10)).addStep(RecipeStep(milk, 10, cappuccinatore, 100))
    );


    return model;
}