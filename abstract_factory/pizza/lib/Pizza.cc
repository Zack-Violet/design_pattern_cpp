#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
#include "include/Pizza.h"
#include "include/PizzaIngredientFactory.h"

Pizza::Pizza()
{
    std::cout << std::setw(40) << "Pizza construct" << std::endl;
}

Pizza::~Pizza()
{
    std::cout << std::setw(39) << "Pizza destruct" << std::endl;
}

std::string Pizza::getName()
{
    return this->_name + " : "
            + _dough->getDough() + " -> " + _sauce->getSauce() + " -> "
            + _cheese->getCheese() + " -> " + _clam->getClams() + " -> "
            + _pepperoni->getPepperoni() + " -> " + _veggies->getVeggies();
}

void Pizza::setName(const std::string _name_)
{
    this->_name = _name_;
}

CheesePizza::CheesePizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif))
{
    std::cout << std::setw(40) << "CheesePizza construct" << std::endl;
}
CheesePizza::~CheesePizza()
{
    std::cout << std::setw(39) << "CheesePizza destruct" << std::endl;
}
void CheesePizza::prepare()
{
    std::cout << "\033[36mPrepare CheesePizza\033[0m" << std::endl;
    _dough = _ingredientFactory->createDough();
    _sauce = _ingredientFactory->createSauce();
    _cheese = _ingredientFactory->createCheese();
    _clam = _ingredientFactory->createClam();
    _pepperoni = _ingredientFactory->createPepperoni();
    _veggies = _ingredientFactory->createVeggies();
}
void CheesePizza::bake()
{
    std::cout << "\033[36mBake CheesePizza" << std::endl;
}
void CheesePizza::cut()
{
    std::cout << "Cut CheesePizza" << std::endl;
}
void CheesePizza::box()
{
    std::cout << "Box CheesePizza\033[0m" << std::endl;
}

PepperoniPizza::PepperoniPizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif))
{
    std::cout << std::setw(40) << "PepperoniPizza construct" << std::endl;
}
PepperoniPizza::~PepperoniPizza()
{
    std::cout << std::setw(39) << "PepperoniPizza destruct" << std::endl;
}
void PepperoniPizza::prepare()
{
    std::cout << "\033[36mPrepare PepperoniPizza\033[0m" << std::endl;
    _dough = _ingredientFactory->createDough();
    _sauce = _ingredientFactory->createSauce();
    _cheese = _ingredientFactory->createCheese();
    _clam = _ingredientFactory->createClam();
    _pepperoni = _ingredientFactory->createPepperoni();
    _veggies = _ingredientFactory->createVeggies();
}
void PepperoniPizza::bake()
{
    std::cout << "\033[36mBake PepperoniPizza" << std::endl;
}
void PepperoniPizza::cut()
{
    std::cout << "Cut PepperoniPizza" << std::endl;
}
void PepperoniPizza::box()
{
    std::cout << "Box PepperoniPizza\033[0m" << std::endl;
}

ClamPizza::ClamPizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif))
{
    std::cout << std::setw(40) << "ClamPizza construct" << std::endl;
}
ClamPizza::~ClamPizza()
{
    std::cout << std::setw(39) << "ClamPizza destruct" << std::endl;
}
void ClamPizza::prepare()
{
    std::cout << "\033[36mPrepare ClamPizza\033[0m" << std::endl;
    _dough = _ingredientFactory->createDough();
    _sauce = _ingredientFactory->createSauce();
    _cheese = _ingredientFactory->createCheese();
    _clam = _ingredientFactory->createClam();
    _pepperoni = _ingredientFactory->createPepperoni();
    _veggies = _ingredientFactory->createVeggies();
}
void ClamPizza::bake()
{
    std::cout << "\033[36mBake ClamPizza" << std::endl;
}
void ClamPizza::cut()
{
    std::cout << "Cut ClamPizza" << std::endl;
}
void ClamPizza::box()
{
    std::cout << "Box ClamPizza\033[0m" << std::endl;
}

VeggiePizza::VeggiePizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif))
{
    std::cout << std::setw(40) << "VeggiePizza construct" << std::endl;
}
VeggiePizza::~VeggiePizza()
{
    std::cout << std::setw(39) << "VeggiePizza destruct" << std::endl;
}
void VeggiePizza::prepare()
{
    std::cout << "\033[36mPrepare VeggiePizza\033[0m" << std::endl;
    _dough = _ingredientFactory->createDough();
    _sauce = _ingredientFactory->createSauce();
    _cheese = _ingredientFactory->createCheese();
    _clam = _ingredientFactory->createClam();
    _pepperoni = _ingredientFactory->createPepperoni();
    _veggies = _ingredientFactory->createVeggies();
}
void VeggiePizza::bake()
{
    std::cout << "\033[36mBake VeggiePizza" << std::endl;
}
void VeggiePizza::cut()
{
    std::cout << "Cut VeggiePizza" << std::endl;
}
void VeggiePizza::box()
{
    std::cout << "Box VeggiePizza\033[0m" << std::endl;
}
