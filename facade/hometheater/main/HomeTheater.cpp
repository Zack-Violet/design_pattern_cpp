#include <iostream>
#include <memory>
#include "../lib/include/HomeTheaterFacade.h"

int main()
{
    std::unique_ptr<HomeTheaterFacade> movie(new HomeTheaterFacade());

    std::cout << "-----------------------------" << std::endl;
    movie->watchMovie("Star Trek");
    std::cout << "-----------------------------" << std::endl;
    movie->endMovie();
    std::cout << "-----------------------------" << std::endl;

    return 0;
}
