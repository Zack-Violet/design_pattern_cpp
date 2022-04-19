#include <iostream>
#include <string>
#include <memory>
#include "include/HomeTheaterFacade.h"
#include "include/ElectricalAppliances.h"

HomeTheaterFacade::HomeTheaterFacade()
{
    _cd = std::unique_ptr<CDPlayer>(new CDPlayer());
    _dvd = std::unique_ptr<DvdPlayer>(new DvdPlayer());
    _tuner = std::unique_ptr<Tuner>(new Tuner());
    _popcorn = std::unique_ptr<PopcornPopper>(new PopcornPopper());
    _projector = std::unique_ptr<Projector>(new Projector());
    _screen = std::unique_ptr<Screen>(new Screen());
    _amplifier = std::unique_ptr<Amplifier>(new Amplifier());
    _lights = std::unique_ptr<TheaterLights>(new TheaterLights());
}

void HomeTheaterFacade::watchMovie(std::string _movie)
{
    std::cout << "Ready to enjoy movie..." << std::endl;
    _popcorn->powerOn();
    _popcorn->popcorn();
    _lights->dim(10);
    _screen->down();
    _projector->powerOn();
    _projector->wideScreenMode();
    _amplifier->powerOn();
    _amplifier->setDvd(_dvd.get());
    _amplifier->setSurroundSound();
    _amplifier->setVolume(5);
    _dvd->powerOn();
    _dvd->play(_movie);
    std::cout << "Now enjoying your movie" << std::endl;
}

void HomeTheaterFacade::endMovie()
{
    std::cout << "Shutting movie theater down..." << std::endl;
    _popcorn->poweroff();
    _lights->powerOn();
    _screen->up();
    _projector->poweroff();
    _amplifier->poweroff();
    _dvd->stop();
    _dvd->eject();
    _dvd->poweroff();
    std::cout << "Movie theater shutted" << std::endl;
}
