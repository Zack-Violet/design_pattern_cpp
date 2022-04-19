#ifndef _PIZZA_H_
#define _PIZZA_H_

#include <iostream>
#include <string>
#include <memory>
#include "PizzaIngredientFactory.h"

class Pizza
{
    public:
        Pizza() {}
        virtual ~Pizza() {}
        virtual void prepare() = 0;
        virtual void bake() = 0;
        virtual void cut() = 0;
        virtual void box() = 0;
        std::string getName()
        {
            return this->_name + " : "
                    + _dough->getDough() + " -> " + _sauce->getSauce() + " -> "
                    + _cheese->getCheese() + " -> " + _clam->getClams() + " -> "
                    + _pepperoni->getPepperoni() + " -> " + _veggies->getVeggies();
        }
        void setName(const std::string _name_)
        {
            this->_name = _name_;
        }

    protected:
        std::unique_ptr<Dough> _dough;
        std::unique_ptr<Sauce> _sauce;
        std::unique_ptr<Cheese> _cheese;
        std::unique_ptr<Clams> _clam;
        std::unique_ptr<Pepperoni> _pepperoni;
        std::unique_ptr<Veggies> _veggies;

    private:
        std::string _name;
};

class CheesePizza : public Pizza
{
    public:
        CheesePizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif)) {}
        ~CheesePizza() {}
        void prepare()
        {
            std::cout << "Prepare CheesePizza\r\n";// << std::endl;
            _dough = _ingredientFactory->createDough();
            _sauce = _ingredientFactory->createSauce();
            _cheese = _ingredientFactory->createCheese();
            _clam = _ingredientFactory->createClam();
            _pepperoni = _ingredientFactory->createPepperoni();
            _veggies = _ingredientFactory->createVeggies();
        }
        void bake()
        {
            std::cout << "Bake CheesePizza\r\n";// << std::endl;
        }
        void cut()
        {
            std::cout << "Cut CheesePizza\r\n";// << std::endl;
        }
        void box()
        {
            std::cout << "Box CheesePizza\r\n";// << std::endl;
        }

    private:
        std::unique_ptr<PizzaIngredientFactory> _ingredientFactory;
};

class PepperoniPizza : public Pizza
{
    public:
        PepperoniPizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif)) {}
        ~PepperoniPizza() {}
        void prepare()
        {
            std::cout << "Prepare PepperoniPizza" << std::endl;
            _dough = _ingredientFactory->createDough();
            _sauce = _ingredientFactory->createSauce();
            _cheese = _ingredientFactory->createCheese();
            _clam = _ingredientFactory->createClam();
            _pepperoni = _ingredientFactory->createPepperoni();
            _veggies = _ingredientFactory->createVeggies();
        }
        void bake()
        {
            std::cout << "Bake PepperoniPizza" << std::endl;
        }
        void cut()
        {
            std::cout << "Cut PepperoniPizza" << std::endl;
        }
        void box()
        {
            std::cout << "Box PepperoniPizza" << std::endl;
        }
    private:
        std::unique_ptr<PizzaIngredientFactory> _ingredientFactory;
};

class ClamPizza : public Pizza
{
    public:
        ClamPizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif)) {}
        ~ClamPizza() {}
        void prepare()
        {
            std::cout << "Prepare ClamPizza" << std::endl;
            _dough = _ingredientFactory->createDough();
            _sauce = _ingredientFactory->createSauce();
            _cheese = _ingredientFactory->createCheese();
            _clam = _ingredientFactory->createClam();
            _pepperoni = _ingredientFactory->createPepperoni();
            _veggies = _ingredientFactory->createVeggies();
        }
        void bake()
        {
            std::cout << "Bake ClamPizza" << std::endl;
        }
        void cut()
        {
            std::cout << "Cut ClamPizza" << std::endl;
        }
        void box()
        {
            std::cout << "Box ClamPizza" << std::endl;
        }
    private:
        std::unique_ptr<PizzaIngredientFactory> _ingredientFactory;
};

class VeggiePizza : public Pizza
{
    public:
        VeggiePizza(std::unique_ptr<PizzaIngredientFactory> _pif) : _ingredientFactory(std::move(_pif)) {}
        ~VeggiePizza() {}
        void prepare()
        {
            std::cout << "Prepare VeggiePizza" << std::endl;
            _dough = _ingredientFactory->createDough();
            _sauce = _ingredientFactory->createSauce();
            _cheese = _ingredientFactory->createCheese();
            _clam = _ingredientFactory->createClam();
            _pepperoni = _ingredientFactory->createPepperoni();
            _veggies = _ingredientFactory->createVeggies();
        }
        void bake()
        {
            std::cout << "Bake VeggiePizza" << std::endl;
        }
        void cut()
        {
            std::cout << "Cut VeggiePizza" << std::endl;
        }
        void box()
        {
            std::cout << "Box VeggiePizza" << std::endl;
        }
    private:
        std::unique_ptr<PizzaIngredientFactory> _ingredientFactory;
};

#endif
