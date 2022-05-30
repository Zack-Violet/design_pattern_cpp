#ifndef _WAITRESS_H_
#define _WAITRESS_H_

#include <iostream>
#include <memory>
#include "Menus.h"

class Waitress {
    public:
        Waitress(std::unique_ptr<MenuComponent>);
        ~Waitress();

        void printMenu();

    private:
        std::unique_ptr<MenuComponent> _allMenus;
};

#endif
