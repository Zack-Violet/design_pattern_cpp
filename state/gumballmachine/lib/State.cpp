#include <iostream>
#include <memory>
#include <string>
#include <cassert>
#include <ctime>
#include "State.h"
#include "GumballMachine.h"

void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted Quarter, then you can TurnCrank or EjecetQuarter!" << std::endl;
    _gumball_machine->setState(_gumball_machine->getHasQuarterState());
}
void NoQuarterState::ejectQuarter()
{
    std::cout << "You can't eject Quarter when there is no Quarter!" << std::endl;
}
void NoQuarterState::turnCrank()
{
    std::cout << "Please insert Quarter first of all." << std::endl;
}
void NoQuarterState::dispense()
{
    std::cout << "NO gumball dispense!" << std::endl;
}
std::string NoQuarterState::toString()
{
    return "NoQuarterState";
}

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter!" << std::endl;
}
void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned!" << std::endl;
    _gumball_machine->setState(_gumball_machine->getNoQuarterState());
}
void HasQuarterState::turnCrank()
{
    std::cout << "You turned... Please wait!" << std::endl;
    //srand((short)time(NULL));
    short winner = rand() % 10;
    std::cout << "winner = " << winner << std::endl;
    if (winner == 5 && _gumball_machine->getCount() > 1)
        _gumball_machine->setState(_gumball_machine->getWinnerState());
    else
        _gumball_machine->setState(_gumball_machine->getSoldState());
}
void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed!" << std::endl;
}
std::string HasQuarterState::toString()
{
    return "HasQuarterState";
}

void SoldState::insertQuarter()
{
    std::cout << "Please wait, we're already giving you a gumball!" << std::endl;
}
void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank, so you can't get your quarter returned!" << std::endl;
}
void SoldState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
}
void SoldState::dispense()
{
    _gumball_machine->releaseBall();
    if (_gumball_machine->getCount() > 0)
    {
        _gumball_machine->setState(_gumball_machine->getNoQuarterState());
    }
    else
    {
        std::cout << "Oops, out of gumballs!" << std::endl;
        _gumball_machine->setState(_gumball_machine->getSoldOutState());
    }
}
std::string SoldState::toString()
{
    return "SoldState";
}

void SoldOutState::insertQuarter()
{
    std::cout << "You can't insert a quarter, the machine is sold out!" << std::endl;
}
void SoldOutState::ejectQuarter()
{
    std::cout << "You can't eject, you haven't inserted a quarter yet!" << std::endl;
}
void SoldOutState::turnCrank()
{
    std::cout << "You turned, but there are no gumballs!" << std::endl;
}
void SoldOutState::dispense()
{
    std::cout << "No gumball dispensed!" << std::endl;
}
std::string SoldOutState::toString()
{
    return "SoldOutState";
}

void WinnerState::insertQuarter()
{
    std::cout << "Please wait! We're already giving you a gumball!" << std::endl;
}

void WinnerState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the Crank, so you can't get your quarter back!" << std::endl;
}

void WinnerState::turnCrank()
{
    std::cout << "Turning twice doesn't give you more gumball!" << std::endl;
}

void WinnerState::dispense()
{
    std::cout << "YOU ARE WINNER! You can get two gumballs for your quarter!" << std::endl;
    _gumball_machine->releaseBall();
    if (_gumball_machine->getCount() > 0)
    {
        _gumball_machine->releaseBall();
        if (_gumball_machine->getCount() > 0)
        {
            _gumball_machine->setState(_gumball_machine->getNoQuarterState());
        }
        else
        {
            _gumball_machine->setState(_gumball_machine->getSoldOutState());
        }
    }
    else
    {
        _gumball_machine->setState(_gumball_machine->getSoldOutState());
        std::cout << "But there is no another gumball!" << std::endl;
    }
}
std::string WinnerState::toString()
{
    return "YOU ARE WINNER! Get your two gumballs!";
}
