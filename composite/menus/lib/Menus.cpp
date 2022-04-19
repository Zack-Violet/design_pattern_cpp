#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <iomanip>
#include "include/Menus.h"

MenuComponent::MenuComponent()
{
    std::cout << "\033[34m-----------------------" << std::endl;
    std::cout << "MenuComponent construct" << std::endl;
}

MenuComponent::~MenuComponent()
{
    std::cout << std::endl;
    std::cout << "MenuComponent destruct" << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void MenuComponent::add(std::unique_ptr<MenuComponent>)
{
    std::cout << "add" << std::endl;
}

void MenuComponent::remove(MenuComponent*)
{
    std::cout << "remove" << std::endl;
}

MenuComponent* MenuComponent::getChild(const int&)
{
    return nullptr;
}

std::string MenuComponent::getName()
{
    return "";
}

std::string MenuComponent::getDescription()
{
    return "";
}

double MenuComponent::getPrice()
{
    return 0;
}

bool MenuComponent::isVegetarian()
{
    return false;
}

void MenuComponent::print()
{
    std::cout << "MenuComponent print" << std::endl;
}

Menu::Menu(const std::string& _name_, const std::string& _description_) : _name(_name_), _description(_description_)
{
    std::cout << "Menu construct" << std::endl;
    std::cout << "-----------------------\033[0m" << std::endl;
}

Menu::~Menu()
{
    std::cout << "-----------------------" << std::endl;
    std::cout << "Menu : " << this->_name << " destruct" << std::endl;
    std::cout << std::endl;
}

void Menu::add(std::unique_ptr<MenuComponent> _menu)
{
    std::cout << "add MenuComponent" << std::endl;
    this->_menuComponents.emplace_back(std::move(_menu));
}

void Menu::remove(MenuComponent* _menu)
{
    std::cout << "remove MenuComponent" << std::endl;
    //auto _pos = std::find(this->_menuComponents.begin(), this->_menuComponents.end(), _menu);
    //if (_pos != this->_menuComponents.end())
    //{
    //    this->_menuComponents.erase(_pos);
    //}
}

MenuComponent* Menu::getChild(const int& _index)
{
    return this->_menuComponents[_index].get();
}

std::string Menu::getName()
{
    return this->_name;
}

std::string Menu::getDescription()
{
    return this->_description;
}

void Menu::print()
{
    std::cout << "\033[32m-------------------------------------------------------------------------------" << std::endl;
    std::cout << this->_name << ", " << this->_description << std::endl;
    std::cout << "-------------------------------------------------------------------------------\033[0m" << std::endl;
    for (size_t i = 0; i < this->_menuComponents.size(); ++i)
    {
        this->_menuComponents[i]->print();
    }
}

MenuItem::MenuItem(const std::string& _name_, const std::string& _description_, const bool& _isvege, const double& _price_)
    : _name(_name_), _description(_description_), _vegetarian(_isvege), _price(_price_)
{
    std::cout << "MenuItem construct" << std::endl;
    std::cout << "-----------------------\033[0m" << std::endl;
}

MenuItem::~MenuItem()
{
    std::cout << "-----------------------" << std::endl;
    std::cout << "MenuItem : " << this->_name << " destruct" << std::endl;
}

std::string MenuItem::getName()
{
    return this->_name;
}

std::string MenuItem::getDescription()
{
    return this->_description;
}

double MenuItem::getPrice()
{
    return this->_price;
}

bool MenuItem::isVegetarian()
{
    return this->_vegetarian;
}

void MenuItem::print()
{
    std::cout << "\033[33m-------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(16) << "Name : " << this->_name << std::endl;
    std::cout << std::setw(16) << "Description : " << this->_description << std::endl;
    std::cout << std::setw(16) << "Price : " << this->_price << std::endl;
    std::cout << std::setw(16) << "IsVegetarian : " << (this->_vegetarian ? "Yes" : "No") << std::endl;
    std::cout << "-------------------------------------------------------------------------------\033[0m" << std::endl;
}
