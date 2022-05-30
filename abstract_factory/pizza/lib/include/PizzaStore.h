#ifndef _PIZZA_STORE_H_
#define _PIZZA_STORE_H_

#include <iostream>
#include <string>
#include <memory>
#include "Pizza.h"
#include "PizzaIngredientFactory.h"

class PizzaStore {
    public:
        PizzaStore();
        virtual ~PizzaStore();
        virtual std::unique_ptr<Pizza> orderPizza(const char);
        virtual void createPizza(const char) = 0;

    public:
        enum PizzaChoose{
            Cheese_Pizza,
            Pepperoni_Pizza,
            Clam_Pizza,
            Veggie_Pizza
        };

    protected:
        std::unique_ptr<Pizza> _pizza;
};

class NYPizzaStore : public PizzaStore {
    public:
        NYPizzaStore();
        ~NYPizzaStore();
        void createPizza(const char);
};

class ChicagoPizzaStore : public PizzaStore {
    public:
        ChicagoPizzaStore();
        ~ChicagoPizzaStore();
        void createPizza(const char);
};

#endif
