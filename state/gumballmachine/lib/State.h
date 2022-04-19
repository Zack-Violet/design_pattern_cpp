#ifndef _STATE_H_
#define _STATE_H_

#include <iostream>
#include <memory>
#include <string>

class GumballMachine;
class State
{
    public:
        State() {}
        virtual ~State() {}
        virtual void insertQuarter() = 0;
        virtual void ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void dispense() = 0;
        virtual std::string toString() = 0;
};

class NoQuarterState : public State
{
    public:
        NoQuarterState(GumballMachine* _gumball_machine_) : _gumball_machine(_gumball_machine_) {}
        ~NoQuarterState() {}

        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        std::string toString();

    private:
        GumballMachine* _gumball_machine;
};

class HasQuarterState : public State
{
    public:
        HasQuarterState(GumballMachine* _gumball_machine_) : _gumball_machine(_gumball_machine_) {}
        ~HasQuarterState() {}

        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        std::string toString();

    private:
        GumballMachine* _gumball_machine;
};

class SoldState : public State
{
    public:
        SoldState(GumballMachine* _gumball_machine_) : _gumball_machine(_gumball_machine_) {}
        ~SoldState() {}

        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        std::string toString();

    private:
        GumballMachine* _gumball_machine;
};

class SoldOutState : public State
{
    public:
        SoldOutState(GumballMachine* _gumball_machine_) : _gumball_machine(_gumball_machine_) {}
        ~SoldOutState() {}

        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        std::string toString();

    private:
        GumballMachine* _gumball_machine;
};

class WinnerState : public State
{
    public:
        WinnerState(GumballMachine* _gumball_machine_) : _gumball_machine(_gumball_machine_) {}
        ~WinnerState() {}

        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        std::string toString();

    private:
        GumballMachine* _gumball_machine;
};

#endif
