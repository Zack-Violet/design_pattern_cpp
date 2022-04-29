#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
#include "include/Pizza.h"
#include "include/PizzaIngredientFactory.h"
#include "include/PizzaStore.h"

PizzaStore::PizzaStore()
{
    std::cout << std::setw(40) << "PizzaStore construct" << std::endl;
}
PizzaStore::~PizzaStore()
{
    std::cout << std::setw(39) << "PizzaStore destruct" << std::endl;
}
std::unique_ptr<Pizza> PizzaStore::orderPizza(const char _choose)
{
    createPizza(_choose);
    _pizza->prepare();
    _pizza->bake();
    _pizza->cut();
    _pizza->box();
    //std::cout << _pizza->getName() << "\r\n";// << std::endl;;
    return std::move(_pizza);
}

NYPizzaStore::NYPizzaStore()
{
    std::cout << std::setw(40) << "NYPizzaStore construct" << std::endl;
}
NYPizzaStore::~NYPizzaStore()
{
    std::cout << std::setw(39) << "NYPizzaStore destruct" << std::endl;
}
void NYPizzaStore::createPizza(const char _choose_)
{
    std::unique_ptr<PizzaIngredientFactory> ingredientFactory(new NYPizzaIngredientFactory());
    switch(_choose_)
    {
        case Cheese_Pizza:
            _pizza = std::unique_ptr<Pizza>(new CheesePizza(std::move(ingredientFactory)));
            _pizza->setName("NYStyleCheesePizza");
            break;
        case Pepperoni_Pizza:
            _pizza = std::unique_ptr<Pizza>(new PepperoniPizza(std::move(ingredientFactory)));
            _pizza->setName("NYStylePepperoniPizza");
            break;
        case Clam_Pizza:
            _pizza = std::unique_ptr<Pizza>(new ClamPizza(std::move(ingredientFactory)));
            _pizza->setName("NYStyleClamPizza");
            break;
        case Veggie_Pizza:
            _pizza = std::unique_ptr<Pizza>(new VeggiePizza(std::move(ingredientFactory)));
            _pizza->setName("NYStyleVeggiePizza");
            break;
        default:
            std::cout << "We don't have the pizza you choose" << std::endl;
            _pizza = nullptr;
            break;
    }
}

ChicagoPizzaStore::ChicagoPizzaStore()
{
    std::cout << std::setw(40) << "ChicagoPizzaStore construct" << std::endl;
}
ChicagoPizzaStore::~ChicagoPizzaStore()
{
    std::cout << std::setw(39) << "ChicagoPizzaStore destruct" << std::endl;
}
void ChicagoPizzaStore::createPizza(const char _choose_)
{
    std::unique_ptr<PizzaIngredientFactory> ingredientFactory(new ChicagoPizzaIngredientFactory());
    switch(_choose_)
    {
        case Cheese_Pizza:
            _pizza = std::unique_ptr<Pizza>(new CheesePizza(std::move(ingredientFactory)));
            _pizza->setName("ChicagoStyleCheesePizza");
            break;
        case Pepperoni_Pizza:
            _pizza = std::unique_ptr<Pizza>(new PepperoniPizza(std::move(ingredientFactory)));
            _pizza->setName("ChicagoStylePepperoniPizza");
            break;
        case Clam_Pizza:
            _pizza = std::unique_ptr<Pizza>(new ClamPizza(std::move(ingredientFactory)));
            _pizza->setName("ChicagoStyleClamPizza");
            break;
        case Veggie_Pizza:
            _pizza = std::unique_ptr<Pizza>(new VeggiePizza(std::move(ingredientFactory)));
            _pizza->setName("ChicagoStyleVeggiePizza");
            break;
        default:
            std::cout << "We don't have the pizza you choose\r\n";// << std::endl;
            _pizza = nullptr;
            break;
    }
}
