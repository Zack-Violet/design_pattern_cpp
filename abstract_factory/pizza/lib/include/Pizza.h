#ifndef _PIZZA_H_
#define _PIZZA_H_

#include <iostream>
#include <string>
#include <memory>
#include "PizzaIngredientFactory.h"

class Pizza {
    public:
        Pizza();
        virtual ~Pizza();
        virtual void prepare() = 0;
        virtual void bake() = 0;
        virtual void cut() = 0;
        virtual void box() = 0;
        std::string getName();
        void setName(const std::string);

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

class CheesePizza : public Pizza {
    public:
        CheesePizza(std::unique_ptr<PizzaIngredientFactory>);
        ~CheesePizza();
        void prepare();
        void bake();
        void cut();
        void box();

    private:
        std::unique_ptr<PizzaIngredientFactory> _ingredientFactory;
};

class PepperoniPizza : public Pizza {
    public:
        PepperoniPizza(std::unique_ptr<PizzaIngredientFactory>);
        ~PepperoniPizza();
        void prepare();
        void bake();
        void cut();
        void box();
    private:
        std::unique_ptr<PizzaIngredientFactory> _ingredientFactory;
};

class ClamPizza : public Pizza {
    public:
        ClamPizza(std::unique_ptr<PizzaIngredientFactory>);
        ~ClamPizza();
        void prepare();
        void bake();
        void cut();
        void box();
    private:
        std::unique_ptr<PizzaIngredientFactory> _ingredientFactory;
};

class VeggiePizza : public Pizza {
    public:
        VeggiePizza(std::unique_ptr<PizzaIngredientFactory>);
        ~VeggiePizza();
        void prepare();
        void bake();
        void cut();
        void box();
    private:
        std::unique_ptr<PizzaIngredientFactory> _ingredientFactory;
};

#endif
