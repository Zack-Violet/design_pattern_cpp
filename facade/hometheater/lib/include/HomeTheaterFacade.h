#ifndef _HOMETHEATERFACADE_H_
#define _HOMETHEATERFACADE_H_

#include <string>
#include <memory>
#include "ElectricalAppliances.h"

class HomeTheaterFacade {
    public:
        HomeTheaterFacade();
        ~HomeTheaterFacade() {}

        void watchMovie(std::string);
        void endMovie();

        void listenToCD(std::string);
        void endCD();

        void listenToRadio(double);
        void endRadio();

    private:
        std::unique_ptr<CDPlayer> _cd;
        std::unique_ptr<DvdPlayer> _dvd;
        std::unique_ptr<Tuner> _tuner;
        std::unique_ptr<PopcornPopper> _popcorn;
        std::unique_ptr<Projector> _projector;
        std::unique_ptr<Screen> _screen;
        std::unique_ptr<Amplifier> _amplifier;
        std::unique_ptr<TheaterLights> _lights;

};

#endif
