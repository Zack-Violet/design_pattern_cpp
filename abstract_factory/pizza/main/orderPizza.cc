#include <iostream>
#include <memory>
#include "../lib/include/Pizza.h"
#include "../lib/include/PizzaIngredientFactory.h"
#include "../lib/include/PizzaStore.h"

int main() {
    std::unique_ptr<PizzaStore> _NY_pizzastore(new NYPizzaStore());
    std::unique_ptr<PizzaStore> _Chicago_pizzastore(new ChicagoPizzaStore());

    std::cout << "\033[32m--------------------------------------" << std::endl;
    std::cout << "first order pizaa : " << std::endl;
    std::cout << "--------------------------------------\033[0m" << std::endl;
    std::unique_ptr<Pizza> pizza_1 = _NY_pizzastore->orderPizza(PizzaStore::Cheese_Pizza);
    std::cout << "\033[33mPizza name : " << "\r\n" << pizza_1->getName() << std::endl;
    //std::cout << "\033[32m--------------------------------------\033[0m" << std::endl;
    std::cout << "\033[0m";
    std::cout << std::endl;

    std::cout << "\033[32m--------------------------------------" << std::endl;
    std::cout << "seond order pizaa : " << std::endl;
    std::cout << "--------------------------------------\033[0m" << std::endl;
    std::unique_ptr<Pizza> pizza_2 = _Chicago_pizzastore->orderPizza(PizzaStore::Pepperoni_Pizza);
    std::cout << "\033[33mPizza name : " << "\r\n" << pizza_2->getName() << std::endl;
    //std::cout << "\033[32m--------------------------------------\033[0m" << std::endl;
    std::cout << "\033[0m";
    std::cout << std::endl;

    std::cout << "\033[32m--------------------------------------" << std::endl;
    std::cout << "third order pizza : " << std::endl;
    std::cout << "--------------------------------------\033[0m" << std::endl;
    std::unique_ptr<Pizza> pizza_3 = _NY_pizzastore->orderPizza(PizzaStore::Clam_Pizza);
    std::cout << "\033[33mPizza name : " << "\r\n" << pizza_3->getName() << std::endl;
    //std::cout << "\033[32m--------------------------------------\033[0m" << std::endl;
    std::cout << "\033[0m";
    std::cout << std::endl;

    std::cout << "\033[32m--------------------------------------" << std::endl;
    std::cout << "forth order pizza : " << std::endl;
    std::cout << "--------------------------------------\033[0m" << std::endl;
    std::unique_ptr<Pizza> pizza_4 = _Chicago_pizzastore->orderPizza(PizzaStore::Veggie_Pizza);
    std::cout << "\033[33mPizza name : " << "\r\n" << pizza_4->getName() << std::endl;
    //std::cout << "\033[32m--------------------------------------\033[0m" << std::endl;
    std::cout << "\033[0m";
    std::cout << std::endl;

    return 0;
}
