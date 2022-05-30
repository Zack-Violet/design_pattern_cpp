#ifndef _PIZZA_INGREDIENT_FACTORY_H_
#define _PIZZA_INGREDIENT_FACTORY_H_

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Dough {
    public:
        Dough();
        virtual ~Dough();
        virtual std::string getDough() = 0;
};

class ThinCrustDough : public Dough {
    public:
        ThinCrustDough();
        ~ThinCrustDough();
        std::string getDough();
};

class ThickCrustDough : public Dough {
    public:
        ThickCrustDough();
        ~ThickCrustDough();
        std::string getDough();
};

class Sauce {
    public:
        Sauce();
        virtual ~Sauce();
        virtual std::string getSauce() = 0;
};

class MarinaraSauce : public Sauce {
    public:
        MarinaraSauce();
        ~MarinaraSauce();
        std::string getSauce();
};

class PlumTomatoSauce : public Sauce {
    public:
        PlumTomatoSauce();
        ~PlumTomatoSauce();
        std::string getSauce();
};

class Cheese {
    public:
        Cheese();
        virtual ~Cheese();
        virtual std::string getCheese() = 0;
};

class ReggianoCheese : public Cheese {
    public:
        ReggianoCheese();
        ~ReggianoCheese();
        std::string getCheese();
};

class ParmesanCheese : public Cheese {
    public:
        ParmesanCheese();
        ~ParmesanCheese();
        std::string getCheese();
};

class MozzarellaCheese : public Cheese {
    public:
        MozzarellaCheese();
        ~MozzarellaCheese();
        std::string getCheese();
};

class Clams {
    public:
        Clams();
        virtual ~Clams();
        virtual std::string getClams() = 0;
};

class FreshClams : public Clams {
    public:
        FreshClams();
        ~FreshClams();
        std::string getClams();
};

class FrozenClams : public Clams {
    public:
        FrozenClams();
        ~FrozenClams();
        std::string getClams();
};

class Pepperoni {
    public:
        Pepperoni();
        virtual ~Pepperoni();
        virtual std::string getPepperoni() = 0;
};

class SlicePepperoni : public Pepperoni {
    public:
        SlicePepperoni();
        ~SlicePepperoni();
        std::string getPepperoni();
};

class Veggies {
    public:
        Veggies();
        virtual ~Veggies();
        virtual std::string getVeggies() = 0;

    protected:
        std::vector<std::string> _veggies;
};

class Eggplant : public Veggies {
    public:
        Eggplant();
        ~Eggplant();
        std::string getVeggies();
};

class Mushroom : public Veggies {
    public:
        Mushroom();
        ~Mushroom();
        std::string getVeggies();
};

class Onion : public Veggies {
    public:
        Onion();
        ~Onion();
        std::string getVeggies();
};

class RedPepper : public Veggies {
    public:
        RedPepper();
        ~RedPepper();
        std::string getVeggies();
};

class BlackOlivers : public Veggies {
    public:
        BlackOlivers();
        ~BlackOlivers();
        std::string getVeggies();
};

class Garlic : public Veggies {
    public:
        Garlic();
        ~Garlic();
        std::string getVeggies();
};

class Spinach : public Veggies {
    public:
        Spinach();
        ~Spinach();
        std::string getVeggies();
};

class PizzaIngredientFactory {
    public:
        PizzaIngredientFactory();
        virtual ~PizzaIngredientFactory();
        virtual std::unique_ptr<Dough> createDough() = 0;
        virtual std::unique_ptr<Sauce> createSauce() = 0;
        virtual std::unique_ptr<Cheese> createCheese() = 0;
        virtual std::unique_ptr<Veggies> createVeggies() = 0;
        virtual std::unique_ptr<Pepperoni> createPepperoni() = 0;
        virtual std::unique_ptr<Clams> createClam() = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
    public:
        NYPizzaIngredientFactory();
        ~NYPizzaIngredientFactory();
        std::unique_ptr<Dough> createDough();
        std::unique_ptr<Sauce> createSauce();
        std::unique_ptr<Cheese> createCheese();
        std::unique_ptr<Veggies> createVeggies();
        std::unique_ptr<Clams> createClam();
        std::unique_ptr<Pepperoni> createPepperoni();
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
    public:
        ChicagoPizzaIngredientFactory();
        ~ChicagoPizzaIngredientFactory();
        std::unique_ptr<Dough> createDough();
        std::unique_ptr<Sauce> createSauce();
        std::unique_ptr<Cheese> createCheese();
        std::unique_ptr<Veggies> createVeggies();
        std::unique_ptr<Clams> createClam();
        std::unique_ptr<Pepperoni> createPepperoni();
};

#endif
