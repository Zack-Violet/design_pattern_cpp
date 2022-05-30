#ifndef _WEATHER_DATA_H_
#define _WEATHER_DATA_H_

#include <memory>
#include <list>
#include "DisplayElement.h"

class Subject {
    public:
        Subject() {
            std::cout << "Subject construct" << std::endl;
        }
        virtual ~Subject() {
            std::cout << "Subject destruct" << std::endl;
        }
        virtual void registerObserver(Observer*) = 0;
        virtual void removeObserver(Observer*) = 0;
        virtual void notifyObservers() = 0;
};

class WeatherData : public Subject {
    public:
        WeatherData() {
            std::cout << "WeatherData construct" << std::endl;
        }
        ~WeatherData() {
            std::cout << "WeatherData destruct" << std::endl;
        }
        void registerObserver(Observer*);
        void removeObserver(Observer*);
        void notifyObservers();
        void measurementsChanged();
        void setMeasurements(float, float, float);
        float getTemperature();
        float getHumidity();
        float getPressure();

    private:
        std::list<Observer*> _observers;
        float _temperature;
        float _humidity;
        float _pressure;
};

#endif
