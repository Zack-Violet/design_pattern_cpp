#include <iostream>
#include <iterator>
#include <string>
#include <memory>
#include <vector>
#include "include/PizzaIngredientFactory.h"


Dough::Dough()
{
    std::cout << "Dough construct" << std::endl;
}
Dough::~Dough()
{
    std::cout << "Dough destruct" << std::endl;
}

ThinCrustDough::ThinCrustDough()
{
    std::cout << "ThinCrustDough construct" << std::endl;
}
ThinCrustDough::~ThinCrustDough()
{
    std::cout << "ThinCrustDough destruct" << std::endl;
}
std::string ThinCrustDough::getDough()
{
    return "ThinCrustDough";
}

ThickCrustDough::ThickCrustDough()
{
    std::cout << "ThickCrustDough construct" << std::endl;
}
ThickCrustDough::~ThickCrustDough()
{
    std::cout << "ThickCrustDough destruct" << std::endl;
}
std::string ThickCrustDough::getDough()
{
    return "ThickCrustDough";
}

Sauce::Sauce()
{
    std::cout << "Sauce construct" << std::endl;
}
Sauce::~Sauce()
{
    std::cout << "Sauce destruct" << std::endl;
}

MarinaraSauce::MarinaraSauce()
{
    std::cout << "MarinaraSauce construct" << std::endl;
}
MarinaraSauce::~MarinaraSauce()
{
    std::cout << "MarinaraSauce destruct" << std::endl;
}
std::string MarinaraSauce::getSauce()
{
    return "MarinaraSauce";
}

PlumTomatoSauce::PlumTomatoSauce()
{
    std::cout << "PlumTomatoSauce construct" << std::endl;
}
PlumTomatoSauce::~PlumTomatoSauce()
{
    std::cout << "PlumTomatoSauce destruct" << std::endl;
}
std::string PlumTomatoSauce::getSauce()
{
    return "PlumTomatoSauce";
}

Cheese::Cheese()
{
    std::cout << "Cheese construct" << std::endl;
}
Cheese::~Cheese()
{
    std::cout << "Cheese destruct" << std::endl;
}

ReggianoCheese::ReggianoCheese()
{
    std::cout << "ReggianoCheese construct" << std::endl;
}
ReggianoCheese::~ReggianoCheese()
{
    std::cout << "ReggianoCheese destruct" << std::endl;
}
std::string ReggianoCheese::getCheese()
{
    return "ReggianoCheese";
}

ParmesanCheese::ParmesanCheese()
{
    std::cout << "ParmesanCheese construct" << std::endl;
}
ParmesanCheese::~ParmesanCheese()
{
    std::cout << "ParmesanCheese destruct" << std::endl;
}
std::string ParmesanCheese::getCheese()
{
    return "ParmesanCheese";
}

MozzarellaCheese::MozzarellaCheese()
{
    std::cout << "MozzarellaCheese construct" << std::endl;
}
MozzarellaCheese::~MozzarellaCheese()
{
    std::cout << "MozzarellaCheese destruct" << std::endl;
}
std::string MozzarellaCheese::getCheese()
{
    return "MozzarellaCheese";
}

Clams::Clams()
{
    std::cout << "Clams construct" << std::endl;
}
Clams::~Clams()
{
    std::cout << "Clams destruct" << std::endl;
}

FreshClams::FreshClams()
{
    std::cout << "FreshClams construct" << std::endl;
}
FreshClams::~FreshClams()
{
    std::cout << "FreshClams destruct" << std::endl;
}
std::string FreshClams::getClams()
{
    return "FreshClams";
}

FrozenClams::FrozenClams()
{
    std::cout << "FrozenClams construct" << std::endl;
}
FrozenClams::~FrozenClams()
{
    std::cout << "FrozenClams destruct" << std::endl;
}
std::string FrozenClams::getClams()
{
    return "FrozenClams";
}

Pepperoni::Pepperoni()
{
    std::cout << "Pepperoni construct" << std::endl;
}
Pepperoni::~Pepperoni()
{
    std::cout << "Pepperoni destruct" << std::endl;
}

SlicePepperoni::SlicePepperoni()
{
    std::cout << "SlicePepperoni construct" << std::endl;
}
SlicePepperoni::~SlicePepperoni()
{
    std::cout << "SlicePepperoni destruct" << std::endl;
}
std::string SlicePepperoni::getPepperoni()
{
    return "SlicePepperoni";
}

Veggies::Veggies()
{
    std::cout << "Veggies construct" << std::endl;
}
Veggies::~Veggies()
{
    std::cout << "Veggies construct" << std::endl;
}

Eggplant::Eggplant()
{
    std::cout << "Eggplant construct" << std::endl;
}
Eggplant::~Eggplant()
{
    std::cout << "Eggplant destruct" << std::endl;
}
std::string Eggplant::getVeggies()
{
    return "Eggplant";
}

Mushroom::Mushroom()
{
    std::cout << "Mushroom construct" << std::endl;
}
Mushroom::~Mushroom()
{
    std::cout << "Mushroom destruct" << std::endl;
}
std::string Mushroom::getVeggies()
{
    return "Mushroom";
}

Onion::Onion()
{
    std::cout << "Onion construct" << std::endl;
}
Onion::~Onion()
{
    std::cout << "Onion destruct" << std::endl;
}
std::string Onion::getVeggies()
{
    return "Onion";
}

RedPepper::RedPepper()
{
    std::cout << "RedPepper construct" << std::endl;
}
RedPepper::~RedPepper()
{
    std::cout << "RedPepper destruct" << std::endl;
}
std::string RedPepper::getVeggies()
{
    return "RedPepper";
}

BlackOlivers::BlackOlivers()
{
    std::cout << "BlackOlivers construct" << std::endl;
}
BlackOlivers::~BlackOlivers()
{
    std::cout << "BlackOlivers destruct" << std::endl;
}
std::string BlackOlivers::getVeggies()
{
    return "BlackOlivers";
}

Garlic::Garlic()
{
    std::cout << "Garlic construct" << std::endl;
}
Garlic::~Garlic()
{
    std::cout << "Garlic destruct" << std::endl;
}
std::string Garlic::getVeggies()
{
    return "Garlic";
}

Spinach::Spinach()
{
    std::cout << "Spinach construct" << std::endl;
}
Spinach::~Spinach()
{
    std::cout << "Spinach destruct" << std::endl;
}
std::string Spinach::getVeggies()
{
    return "Spinach";
}

PizzaIngredientFactory::PizzaIngredientFactory()
{
    std::cout << "PizzaIngredientFactory construct" << std::endl;
}
PizzaIngredientFactory::~PizzaIngredientFactory()
{
    std::cout << "PizzaIngredientFactory destruct" << std::endl;
}

NYPizzaIngredientFactory::NYPizzaIngredientFactory()
{
    std::cout << "NYPizzaIngredientFactory construct" << std::endl;
}
NYPizzaIngredientFactory::~NYPizzaIngredientFactory()
{
    std::cout << "NYPizzaIngredientFactory destruct" << std::endl;
}
std::unique_ptr<Dough> NYPizzaIngredientFactory::createDough()
{
    return std::unique_ptr<Dough>(new ThinCrustDough());
}
std::unique_ptr<Sauce> NYPizzaIngredientFactory::createSauce()
{
    return std::unique_ptr<Sauce>(new MarinaraSauce());
}
std::unique_ptr<Cheese> NYPizzaIngredientFactory::createCheese()
{
    return std::unique_ptr<Cheese>(new ReggianoCheese());
}
std::unique_ptr<Veggies> NYPizzaIngredientFactory::createVeggies()
{
    return std::unique_ptr<Veggies>(new Mushroom());
}
std::unique_ptr<Clams> NYPizzaIngredientFactory::createClam()
{
    return std::unique_ptr<Clams>(new FreshClams());
}
std::unique_ptr<Pepperoni> NYPizzaIngredientFactory::createPepperoni()
{
    return std::unique_ptr<Pepperoni>(new SlicePepperoni());
}

ChicagoPizzaIngredientFactory::ChicagoPizzaIngredientFactory()
{
    std::cout << "ChicagoPizzaIngredientFactory construct" << std::endl;
}
ChicagoPizzaIngredientFactory::~ChicagoPizzaIngredientFactory()
{
    std::cout << "ChicagoPizzaIngredientFactory destruct" << std::endl;
}
std::unique_ptr<Dough> ChicagoPizzaIngredientFactory::createDough()
{
    return std::unique_ptr<Dough>(new ThickCrustDough());
}
std::unique_ptr<Sauce> ChicagoPizzaIngredientFactory::createSauce()
{
    return std::unique_ptr<Sauce>(new PlumTomatoSauce());
}
std::unique_ptr<Cheese> ChicagoPizzaIngredientFactory::createCheese()
{
    return std::unique_ptr<Cheese>(new MozzarellaCheese());
}
std::unique_ptr<Veggies> ChicagoPizzaIngredientFactory::createVeggies()
{
    return std::unique_ptr<Veggies>(new Eggplant());
}
std::unique_ptr<Clams> ChicagoPizzaIngredientFactory::createClam()
{
    return std::unique_ptr<Clams>(new FrozenClams());
}
std::unique_ptr<Pepperoni> ChicagoPizzaIngredientFactory::createPepperoni()
{
    return std::unique_ptr<Pepperoni>(new SlicePepperoni());
}
