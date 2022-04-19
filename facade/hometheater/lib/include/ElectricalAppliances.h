#ifndef _ELECTRICAL_APPLIANCES_H_
#define _ELECTRICAL_APPLIANCES_H_

#include <iostream>
#include <string>

class CDPlayer
{
    public:
        CDPlayer() {}
        ~CDPlayer() {}

        void powerOn();
        void poweroff();
        void eject();
        void play(std::string);
        void play(int);
        void stop();
        void pause();
        std::string toString();

    private:
        std::string _description;
        std::string _title;
        int _currentTrack;
};

class DvdPlayer
{
    public:
        DvdPlayer() {}
        ~DvdPlayer() {}

        void powerOn();
        void poweroff();
        void eject();
        void play(std::string);
        void play(int);
        void stop();
        void pause();
        void setTwoChannelAudio();
        void setSurroundAudio();
        std::string toString();

    private:
        std::string _description;
        std::string _movie;
        int _currentTrack;
};

class Tuner
{
    public:
        Tuner() {}
        ~Tuner() {}

        void powerOn();
        void poweroff();
        void setFrequency(double);
        void setAM();
        void setFM();
        std::string toString();

    private:
        std::string _description;
        double _frequency;
};

class PopcornPopper
{
    public:
        PopcornPopper() {}
        ~PopcornPopper() {}

        void powerOn();
        void poweroff();
        void popcorn();
        std::string toString();

    private:
        std::string _description;
};

class Projector
{
    public:
        Projector() {}
        ~Projector() {}

        void powerOn();
        void poweroff();
        void wideScreenMode();
        void tvMode();
        std::string toString();

    private:
        std::string _description;
};

class Screen
{
    public:
        Screen() {}
        ~Screen() {}

        void up();
        void down();
        std::string toString();

    private:
        std::string _description;
};

class TheaterLights
{
    public:
        TheaterLights() {}
        ~TheaterLights() {}

        void powerOn();
        void poweroff();
        void dim(int);
        std::string toString();

    private:
        std::string _description;
};

class Amplifier
{
    public:
        Amplifier() {}
        ~Amplifier() {}

        void powerOn();
        void poweroff();
        void setStereoSound();
        void setSurroundSound();
        void setVolume(int);
        void setTuner(Tuner*);
        void setDvd(DvdPlayer*);
        void setCD(CDPlayer*);
        std::string toString();

    private:
        std::string _description;
};

#endif
