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

    Product cookie("�������", false);
    Product pastry("��������", false);
    Product cake("����", false);
    model.addDessert(cookie, 20);
    model.addDessert(pastry, 20);
    model.addDessert(cake, 20);

    Ingredient coffeeBeans("�������� �����");
    Ingredient milk("������");
    Ingredient syrup("�����");

    model.addIngredient(coffeeBeans, 1000);
    model.addIngredient(milk, 200);
    model.addIngredient(syrup, 100);

    KitchenMachine coffeeMachine("���� ������");
    KitchenMachine cappuccinatore("�����������");

    model.addRecipe(
       Product("��������", true),
       Recipe().addStep(RecipeStep(coffeeBeans, 5, coffeeMachine, 120))
    );
    model.addRecipe(
        Product("��� ����", true),
        Recipe().addStep(RecipeStep(syrup, 10, KitchenMachine(), 10)).addStep(RecipeStep(coffeeBeans, 5, coffeeMachine, 120)).addStep(RecipeStep(milk, 10, cappuccinatore, 100))
    );
    model.addRecipe(
        Product("���������", true),
        Recipe().addStep(RecipeStep(coffeeBeans, 5, coffeeMachine, 120)).addStep(RecipeStep(milk, 10, KitchenMachine(), 10)).addStep(RecipeStep(milk, 10, cappuccinatore, 100))
    );


    return model;
}