#include <iostream>
#include <string>
#include <cassert>
#include "GumballMachine.h"
#include "State.h"

GumballMachine::GumballMachine(short _gumball_num_)
{
    _no_quarter_state = std::unique_ptr<State>(new NoQuarterState(this));
    _has_quarter_state = std::unique_ptr<State>(new HasQuarterState(this));
    _sold_state = std::unique_ptr<State>(new SoldState(this));
    _sold_out_state = std::unique_ptr<State>(new SoldOutState(this));
    _winner_state = std::unique_ptr<State>(new WinnerState(this));

    _gumball_num = _gumball_num_;
    if (_gumball_num > 0)
    {
        _state = _no_quarter_state.get();
    }
    else
    {
        _state = _sold_out_state.get();
    }
}

void GumballMachine::insertQuarter() const
{
    assert(_state);
    _state->insertQuarter();
}

void GumballMachine::ejectQuarter() const
{
    assert(_state);
    _state->ejectQuarter();
}

void GumballMachine::turnCrank() const
{
    assert(_state);
    _state->turnCrank();
    _state->dispense();
}

void GumballMachine::releaseBall()
{
    std::cout << "GumballMachine release a gumball!" << std::endl;
    if (_gumball_num > 0)
        _gumball_num--;
}

void GumballMachine::setState(State* _state_)
{
    assert(_state_);
    this->_state = _state_;
}

short GumballMachine::getCount() const
{
    return this->_gumball_num;
}

void GumballMachine::refill(short _count_)
{
    assert(_state);
    assert(_count_ > 0);
    std::cout << "Refill gumballs!" << std::endl;
    _gumball_num = _count_;
    _state = _no_quarter_state.get();
}

State* GumballMachine::getState() const
{
    assert(_state);
    return this->_state;
}

State* GumballMachine::getNoQuarterState() const
{
    assert(_no_quarter_state);
    return this->_no_quarter_state.get();
}

State* GumballMachine::getHasQuarterState() const
{
    assert(_has_quarter_state);
    return this->_has_quarter_state.get();
}

State* GumballMachine::getSoldState() const
{
    assert(_sold_state);
    return this->_sold_state.get();
}

State* GumballMachine::getSoldOutState() const
{
    assert(_sold_out_state);
    return this->_sold_out_state.get();
}

State* GumballMachine::getWinnerState() const
{
    assert(_winner_state);
    return this->_winner_state.get();
}

std::string GumballMachine::toString() const
{
    assert(_state);
    return _state->toString();
}
