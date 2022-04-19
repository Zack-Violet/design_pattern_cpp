#include <iostream>
#include <string>
#include <memory>
#include "include/Pizza.h"
#include "include/PizzaIngredientFactory.h"

Pizza::Pizza()
{
    std::cout << "Pizza construct" << std::endl;
}

Pizza::~Pizza()
{
    std::cout << "Pizza destruct" << std::endl;
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
    std::cout << "CheesePizza construct" << std::endl;
}
CheesePizza::~CheesePizza()
{
    std::cout << "CheesePizza destruct" << std::endl;
}
void CheesePizza::prepare()
{
    std::cout << "Prepare CheesePizza" << std::endl;
    _dough = _ingredientFactory->createDough();
    _sauce = _ingredientFactory->createSauce();
    _cheese = _ingredientFactory->createCheese();
    _clam = _ingredientFactory->createClam();
    _pepperoni = _ingredientFactory->createPepperoni();
    _veggies = _ingredientFactory->createVeggies();
}
void CheesePizza::bake()
{
    std::cout << "Bake CheesePizza" << std::endl;
}
void CheesePizza::cut()
{
    std::cout << "Cut CheesePizza" << std::endl;
}
void CheesePizza::box()
{
    std::cout << "Box CheesePizza" << std::endl;
}

PepperoniPizza::PepperoniPizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif))
{
    std::cout << "PepperoniPizza construct" << std::endl;
}
PepperoniPizza::~PepperoniPizza()
{
    std::cout << "PepperoniPizza destruct" << std::endl;
}
void PepperoniPizza::prepare()
{
    std::cout << "Prepare PepperoniPizza" << std::endl;
    _dough = _ingredientFactory->createDough();
    _sauce = _ingredientFactory->createSauce();
    _cheese = _ingredientFactory->createCheese();
    _clam = _ingredientFactory->createClam();
    _pepperoni = _ingredientFactory->createPepperoni();
    _veggies = _ingredientFactory->createVeggies();
}
void PepperoniPizza::bake()
{
    std::cout << "Bake PepperoniPizza" << std::endl;
}
void PepperoniPizza::cut()
{
    std::cout << "Cut PepperoniPizza" << std::endl;
}
void PepperoniPizza::box()
{
    std::cout << "Box PepperoniPizza" << std::endl;
}

ClamPizza::ClamPizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif))
{
    std::cout << "ClamPizza construct" << std::endl;
}
ClamPizza::~ClamPizza()
{
    std::cout << "ClamPizza destruct" << std::endl;
}
void ClamPizza::prepare()
{
    std::cout << "Prepare ClamPizza" << std::endl;
    _dough = _ingredientFactory->createDough();
    _sauce = _ingredientFactory->createSauce();
    _cheese = _ingredientFactory->createCheese();
    _clam = _ingredientFactory->createClam();
    _pepperoni = _ingredientFactory->createPepperoni();
    _veggies = _ingredientFactory->createVeggies();
}
void ClamPizza::bake()
{
    std::cout << "Bake ClamPizza" << std::endl;
}
void ClamPizza::cut()
{
    std::cout << "Cut ClamPizza" << std::endl;
}
void ClamPizza::box()
{
    std::cout << "Box ClamPizza" << std::endl;
}

VeggiePizza::VeggiePizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif))
{
    std::cout << "VeggiePizza construct" << std::endl;
}
VeggiePizza::~VeggiePizza()
{
    std::cout << "VeggiePizza destruct" << std::endl;
}
void VeggiePizza::prepare()
{
    std::cout << "Prepare VeggiePizza" << std::endl;
    _dough = _ingredientFactory->createDough();
    _sauce = _ingredientFactory->createSauce();
    _cheese = _ingredientFactory->createCheese();
    _clam = _ingredientFactory->createClam();
    _pepperoni = _ingredientFactory->createPepperoni();
    _veggies = _ingredientFactory->createVeggies();
}
void VeggiePizza::bake()
{
    std::cout << "Bake VeggiePizza" << std::endl;
}
void VeggiePizza::cut()
{
    std::cout << "Cut VeggiePizza" << std::endl;
}
void VeggiePizza::box()
{
    std::cout << "Box VeggiePizza" << std::endl;
}
