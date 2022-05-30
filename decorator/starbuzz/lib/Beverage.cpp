#include <iostream>
#include <memory>
#include <string>
#include "Beverage.h"

std::string Beverage::getDescription() {
    return _description;
}

double HouseBlend::cost() {
    return 0.89;
}

double Espresso::cost() {
    return 1.99;
}

double Decaf::cost() {
    return 1.05;
}

double DarkRoast::cost() {
    return 0.99;
}

Soy::Soy(std::unique_ptr<Beverage> _ber) {
    std::cout << "Soy construct" << std::endl;
    this->_beverage = std::move(_ber);
}

std::string Soy::getDescription() {
    return _beverage->getDescription() + " with Soy";
}

double Soy::cost() {
    return _beverage->cost() + 0.15;
}

Milk::Milk(std::unique_ptr<Beverage> _ber) {
    std::cout << "Milk construct" << std::endl;
    this->_beverage = std::move(_ber);
}

std::string Milk::getDescription() {
    return _beverage->getDescription() + " with Milk";
}

double Milk::cost() {
    return _beverage->cost() + 0.10;
}

Mocha::Mocha(std::unique_ptr<Beverage> _ber) {
    std::cout << "Mocha construct" << std::endl;
    this->_beverage = std::move(_ber);
}

std::string Mocha::getDescription() {
    return _beverage->getDescription() + " with Mocha";
}

double Mocha::cost() {
    return _beverage->cost() + 0.20;
}

Whip::Whip(std::unique_ptr<Beverage> _ber) {
    std::cout << "Whip construct" << std::endl;
    this->_beverage = std::move(_ber);
}

std::string Whip::getDescription() {
    return _beverage->getDescription() + " with Whip";
}

double Whip::cost() {
    return _beverage->cost() + 0.10;
}
