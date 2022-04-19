#include <iostream>
#include <memory>
#include <string>
#include "include/Waitress.h"
#include "include/Menus.h"

Waitress::Waitress(std::unique_ptr<MenuComponent> _menu)
{
    std::cout << "Waitress construct" << std::endl;
    this->_allMenus = std::move(_menu);
}

Waitress::~Waitress()
{
    std::cout << "Waitress destruct" << std::endl;
}

void Waitress::printMenu()
{
    _allMenus->print();
}
