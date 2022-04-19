#include <iostream>
#include <string>
#include <memory>
#include "../lib/GumballMachine.h"

int main()
{
    std::unique_ptr<GumballMachine> gumballmachine_(new GumballMachine(10));

    std::cout << "---------------------------------------" << std::endl;
    gumballmachine_->insertQuarter();
    gumballmachine_->turnCrank();
    std::cout << gumballmachine_->toString() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    gumballmachine_->insertQuarter();
    gumballmachine_->turnCrank();
    std::cout << gumballmachine_->toString() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    gumballmachine_->insertQuarter();
    gumballmachine_->turnCrank();
    std::cout << gumballmachine_->toString() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    gumballmachine_->insertQuarter();
    gumballmachine_->turnCrank();
    std::cout << gumballmachine_->toString() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    gumballmachine_->insertQuarter();
    gumballmachine_->turnCrank();
    std::cout << gumballmachine_->toString() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    gumballmachine_->insertQuarter();
    gumballmachine_->turnCrank();
    std::cout << gumballmachine_->toString() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    gumballmachine_->insertQuarter();
    gumballmachine_->turnCrank();
    std::cout << gumballmachine_->toString() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    return 0;
}
