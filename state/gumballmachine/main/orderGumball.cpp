#include <iostream>
#include <string>
#include <memory>
#include "../lib/GumballMachine.h"

static const int GUMALL_NUM = 15;
static const int BUY_TIME = 10;

int main()
{
    std::unique_ptr<GumballMachine> gumballmachine_(new GumballMachine(GUMALL_NUM));

    //for (int i = 0; i < BUY_TIME; ++i)
    //{
    //    std::cout << "-------------------------------------------------------------------" << std::endl;
    //    gumballmachine_->insertQuarter();
    //    gumballmachine_->turnCrank();
    //    std::cout << gumballmachine_->toString() << std::endl;
    //}
    //std::cout << "-------------------------------------------------------------------" << std::endl;

    gumballmachine_->startWork();

    return 0;
}
