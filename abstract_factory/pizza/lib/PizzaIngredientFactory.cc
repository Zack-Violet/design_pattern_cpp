#include <iostream>
#include <iterator>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include "include/PizzaIngredientFactory.h"


Dough::Dough() {
    std::cout << std::setw(40) << "Dough construct" << std::endl;
}
Dough::~Dough() {
    std::cout << std::setw(39)<< "Dough destruct" << std::endl;
}

ThinCrustDough::ThinCrustDough() {
    std::cout << std::setw(40)<< "ThinCrustDough construct" << std::endl;
}
ThinCrustDough::~ThinCrustDough() {
    std::cout << std::setw(39)<< "ThinCrustDough destruct" << std::endl;
}
std::string ThinCrustDough::getDough() {
    return "ThinCrustDough";
}

ThickCrustDough::ThickCrustDough() {
    std::cout << std::setw(40)<< "ThickCrustDough construct" << std::endl;
}
ThickCrustDough::~ThickCrustDough() {
    std::cout << std::setw(39)<< "ThickCrustDough destruct" << std::endl;
}
std::string ThickCrustDough::getDough() {
    return "ThickCrustDough";
}

Sauce::Sauce() {
    std::cout << std::setw(40)<< "Sauce construct" << std::endl;
}
Sauce::~Sauce() {
    std::cout << std::setw(39)<< "Sauce destruct" << std::endl;
}

MarinaraSauce::MarinaraSauce() {
    std::cout << std::setw(40)<< "MarinaraSauce construct" << std::endl;
}
MarinaraSauce::~MarinaraSauce() {
    std::cout << std::setw(39)<< "MarinaraSauce destruct" << std::endl;
}
std::string MarinaraSauce::getSauce() {
    return "MarinaraSauce";
}

PlumTomatoSauce::PlumTomatoSauce() {
    std::cout << std::setw(40)<< "PlumTomatoSauce construct" << std::endl;
}
PlumTomatoSauce::~PlumTomatoSauce() {
    std::cout << std::setw(39)<< "PlumTomatoSauce destruct" << std::endl;
}
std::string PlumTomatoSauce::getSauce() {
    return "PlumTomatoSauce";
}

Cheese::Cheese() {
    std::cout << std::setw(40)<< "Cheese construct" << std::endl;
}
Cheese::~Cheese() {
    std::cout << std::setw(39)<< "Cheese destruct" << std::endl;
}

ReggianoCheese::ReggianoCheese() {
    std::cout << std::setw(40)<< "ReggianoCheese construct" << std::endl;
}
ReggianoCheese::~ReggianoCheese() {
    std::cout << std::setw(39)<< "ReggianoCheese destruct" << std::endl;
}
std::string ReggianoCheese::getCheese() {
    return "ReggianoCheese";
}

ParmesanCheese::ParmesanCheese() {
    std::cout << std::setw(40)<< "ParmesanCheese construct" << std::endl;
}
ParmesanCheese::~ParmesanCheese() {
    std::cout << std::setw(39)<< "ParmesanCheese destruct" << std::endl;
}
std::string ParmesanCheese::getCheese() {
    return "ParmesanCheese";
}

MozzarellaCheese::MozzarellaCheese() {
    std::cout << std::setw(40)<< "MozzarellaCheese construct" << std::endl;
}
MozzarellaCheese::~MozzarellaCheese() {
    std::cout << std::setw(39)<< "MozzarellaCheese destruct" << std::endl;
}
std::string MozzarellaCheese::getCheese() {
    return "MozzarellaCheese";
}

Clams::Clams() {
    std::cout << std::setw(40)<< "Clams construct" << std::endl;
}
Clams::~Clams() {
    std::cout << std::setw(39)<< "Clams destruct" << std::endl;
}

FreshClams::FreshClams() {
    std::cout << std::setw(40)<< "FreshClams construct" << std::endl;
}
FreshClams::~FreshClams() {
    std::cout << std::setw(39)<< "FreshClams destruct" << std::endl;
}
std::string FreshClams::getClams() {
    return "FreshClams";
}

FrozenClams::FrozenClams() {
    std::cout << std::setw(40)<< "FrozenClams construct" << std::endl;
}
FrozenClams::~FrozenClams() {
    std::cout << std::setw(39)<< "FrozenClams destruct" << std::endl;
}
std::string FrozenClams::getClams() {
    return "FrozenClams";
}

Pepperoni::Pepperoni() {
    std::cout << std::setw(40)<< "Pepperoni construct" << std::endl;
}
Pepperoni::~Pepperoni() {
    std::cout << std::setw(39)<< "Pepperoni destruct" << std::endl;
}

SlicePepperoni::SlicePepperoni() {
    std::cout << std::setw(40)<< "SlicePepperoni construct" << std::endl;
}
SlicePepperoni::~SlicePepperoni() {
    std::cout << std::setw(39)<< "SlicePepperoni destruct" << std::endl;
}
std::string SlicePepperoni::getPepperoni() {
    return "SlicePepperoni";
}

Veggies::Veggies() {
    std::cout << std::setw(40)<< "Veggies construct" << std::endl;
}
Veggies::~Veggies() {
    std::cout << std::setw(39)<< "Veggies destruct" << std::endl;
}

Eggplant::Eggplant() {
    std::cout << std::setw(40)<< "Eggplant construct" << std::endl;
}
Eggplant::~Eggplant() {
    std::cout << std::setw(39)<< "Eggplant destruct" << std::endl;
}
std::string Eggplant::getVeggies() {
    return "Eggplant";
}

Mushroom::Mushroom() {
    std::cout << std::setw(40)<< "Mushroom construct" << std::endl;
}
Mushroom::~Mushroom() {
    std::cout << std::setw(39)<< "Mushroom destruct" << std::endl;
}
std::string Mushroom::getVeggies() {
    return "Mushroom";
}

Onion::Onion() {
    std::cout << std::setw(40)<< "Onion construct" << std::endl;
}
Onion::~Onion() {
    std::cout << std::setw(39)<< "Onion destruct" << std::endl;
}
std::string Onion::getVeggies() {
    return "Onion";
}

RedPepper::RedPepper() {
    std::cout << std::setw(40)<< "RedPepper construct" << std::endl;
}
RedPepper::~RedPepper() {
    std::cout << std::setw(39)<< "RedPepper destruct" << std::endl;
}
std::string RedPepper::getVeggies() {
    return "RedPepper";
}

BlackOlivers::BlackOlivers() {
    std::cout << std::setw(40)<< "BlackOlivers construct" << std::endl;
}
BlackOlivers::~BlackOlivers() {
    std::cout << std::setw(39)<< "BlackOlivers destruct" << std::endl;
}
std::string BlackOlivers::getVeggies() {
    return "BlackOlivers";
}

Garlic::Garlic() {
    std::cout << std::setw(40)<< "Garlic construct" << std::endl;
}
Garlic::~Garlic() {
    std::cout << std::setw(39)<< "Garlic destruct" << std::endl;
}
std::string Garlic::getVeggies() {
    return "Garlic";
}

Spinach::Spinach() {
    std::cout << std::setw(40)<< "Spinach construct" << std::endl;
}
Spinach::~Spinach() {
    std::cout << std::setw(39)<< "Spinach destruct" << std::endl;
}
std::string Spinach::getVeggies() {
    return "Spinach";
}

PizzaIngredientFactory::PizzaIngredientFactory() {
    std::cout << std::setw(40)<< "PizzaIngredientFactory construct" << std::endl;
}
PizzaIngredientFactory::~PizzaIngredientFactory() {
    std::cout << std::setw(39)<< "PizzaIngredientFactory destruct" << std::endl;
}

NYPizzaIngredientFactory::NYPizzaIngredientFactory() {
    std::cout << std::setw(40)<< "NYPizzaIngredientFactory construct" << std::endl;
}
NYPizzaIngredientFactory::~NYPizzaIngredientFactory() {
    std::cout << std::setw(39)<< "NYPizzaIngredientFactory destruct" << std::endl;
}
std::unique_ptr<Dough> NYPizzaIngredientFactory::createDough() {
    return std::unique_ptr<Dough>(new ThinCrustDough());
}
std::unique_ptr<Sauce> NYPizzaIngredientFactory::createSauce() {
    return std::unique_ptr<Sauce>(new MarinaraSauce());
}
std::unique_ptr<Cheese> NYPizzaIngredientFactory::createCheese() {
    return std::unique_ptr<Cheese>(new ReggianoCheese());
}
std::unique_ptr<Veggies> NYPizzaIngredientFactory::createVeggies() {
    return std::unique_ptr<Veggies>(new Mushroom());
}
std::unique_ptr<Clams> NYPizzaIngredientFactory::createClam() {
    return std::unique_ptr<Clams>(new FreshClams());
}
std::unique_ptr<Pepperoni> NYPizzaIngredientFactory::createPepperoni() {
    return std::unique_ptr<Pepperoni>(new SlicePepperoni());
}

ChicagoPizzaIngredientFactory::ChicagoPizzaIngredientFactory() {
    std::cout << std::setw(40)<< "ChicagoPizzaIngredientFactory construct" << std::endl;
}
ChicagoPizzaIngredientFactory::~ChicagoPizzaIngredientFactory() {
    std::cout << std::setw(39)<< "ChicagoPizzaIngredientFactory destruct" << std::endl;
}
std::unique_ptr<Dough> ChicagoPizzaIngredientFactory::createDough() {
    return std::unique_ptr<Dough>(new ThickCrustDough());
}
std::unique_ptr<Sauce> ChicagoPizzaIngredientFactory::createSauce() {
    return std::unique_ptr<Sauce>(new PlumTomatoSauce());
}
std::unique_ptr<Cheese> ChicagoPizzaIngredientFactory::createCheese() {
    return std::unique_ptr<Cheese>(new MozzarellaCheese());
}
std::unique_ptr<Veggies> ChicagoPizzaIngredientFactory::createVeggies() {
    return std::unique_ptr<Veggies>(new Eggplant());
}
std::unique_ptr<Clams> ChicagoPizzaIngredientFactory::createClam() {
    return std::unique_ptr<Clams>(new FrozenClams());
}
std::unique_ptr<Pepperoni> ChicagoPizzaIngredientFactory::createPepperoni() {
    return std::unique_ptr<Pepperoni>(new SlicePepperoni());
}
