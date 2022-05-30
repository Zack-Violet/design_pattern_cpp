#ifndef _MENUS_H_
#define _MENUS_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class MenuComponent {
    public:
        MenuComponent();
        virtual ~MenuComponent();

        virtual void add(std::unique_ptr<MenuComponent>);
        virtual void remove(MenuComponent*);
        virtual MenuComponent* getChild(const int&);
        virtual std::string getName();
        virtual std::string getDescription();
        virtual double getPrice();
        virtual bool isVegetarian();
        virtual void print();
};

class Menu : public MenuComponent {
    public:
        Menu(const std::string&, const std::string&);
        ~Menu();

        void add(std::unique_ptr<MenuComponent>);
        void remove(MenuComponent*);
        MenuComponent* getChild(const int&);
        std::string getName();
        std::string getDescription();
        void print();

    private:
        std::vector<std::unique_ptr<MenuComponent> > _menuComponents;
        std::string _name;
        std::string _description;
};

class MenuItem : public MenuComponent {
    public:
        MenuItem(const std::string&, const std::string&, const bool&, const double&);
        ~MenuItem();

        std::string getName();
        std::string getDescription();
        double getPrice();
        bool isVegetarian();
        void print();

    private:
        std::string _name;
        std::string _description;
        bool _vegetarian;
        double _price;
};

#endif
