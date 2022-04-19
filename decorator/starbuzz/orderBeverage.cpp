#include <iostream>
#include <string>
#include <memory>
#include "lib/Beverage.h"

int main()
{
    std::unique_ptr<Beverage> beverage (new Espresso());
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(3);
    std::cout << "\033[32m------------------------------------------------" << std::endl;
    std::cout << beverage->getDescription()
              << " $"
              << beverage->cost()
              << std::endl;
    std::cout << "------------------------------------------------\033[0m" << std::endl;

    std::unique_ptr<Beverage> beverage2 (new DarkRoast());
    beverage2.reset(new Mocha(std::move(beverage2)));
    beverage2.reset(new Mocha(std::move(beverage2)));
    beverage2.reset(new Whip(std::move(beverage2)));
    std::cout << "\033[32m------------------------------------------------" << std::endl;
    std::cout << beverage2->getDescription()
              << " $"
              << beverage2->cost()
              << std::endl;
    std::cout << "------------------------------------------------\033[0m" << std::endl;

    std::unique_ptr<Beverage> beverage3 (new HouseBlend());
    beverage3.reset(new Soy(std::move(beverage3)));
    beverage3.reset(new Mocha(std::move(beverage3)));
    beverage3.reset(new Whip(std::move(beverage3)));
    std::cout << "\033[32m------------------------------------------------" << std::endl;
    std::cout << beverage3->getDescription()
              << " $"
              << beverage3->cost()
              << std::endl;
    std::cout << "------------------------------------------------\033[0m" << std::endl;

  return 0;
}
