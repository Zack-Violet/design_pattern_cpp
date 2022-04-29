#ifndef _GUMBALL_MACHINE_H_
#define _GUMBALL_MACHINE_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include "State.h"

class GumballMachine
{
    public:
        GumballMachine(short _gumball_num_);
        ~GumballMachine() {}
        void startWork() const;
        void insertQuarter() const;
        void ejectQuarter() const;
        void turnCrank() const;
        void releaseBall();
        void setState(State*);
        short getCount()  const;
        void refill(short);
        State* getState() const;
        State* getSoldOutState() const;
        State* getNoQuarterState() const;
        State* getHasQuarterState() const;
        State* getSoldState() const;
        State* getWinnerState() const;
        std::string toString() const;

    private:
        State* _state;
        std::unique_ptr<State> _no_quarter_state;
        std::unique_ptr<State> _has_quarter_state;
        std::unique_ptr<State> _sold_state;
        std::unique_ptr<State> _sold_out_state;
        std::unique_ptr<State> _winner_state;

        short _gumball_num;
};

#endif
