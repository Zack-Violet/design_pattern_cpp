#include <iostream>
#include <vector>
#include <cassert>
#include "include/WeatherData.h"
#include "include/DisplayElement.h"

void WeatherData::registerObserver(Observer* _obs) {
    assert(_obs);
    std::cout << "registerObserver" << std::endl;
    this->_observers.push_back(_obs);
}

void WeatherData::removeObserver(Observer* _obs) {
    assert(_obs);
    std::cout << "removeObserver" << std::endl;
    this->_observers.remove(_obs);
}

void WeatherData::notifyObservers() {
    std::cout << "notifyObservers update data" << std::endl;
    if (!this->_observers.empty())
        for (auto it = this->_observers.begin(); it != this->_observers.end(); it++)
        {
            (*it)->update(this->_temperature, this->_humidity, this->_pressure);
        }
}

void WeatherData::measurementsChanged() {
    std::cout << "measurementsChanged" << std::endl;
    this->notifyObservers();
}

void WeatherData::setMeasurements(float _temp, float _hum, float _pre) {
    assert(_temp);
    assert(_hum);
    assert(_pre);
    std::cout << "\033[32m---------------------------setMeasurements---------------------------" << std::endl;
    std::cout << "setMeasurements" << std::endl;
    std::cout << "Temperature : " << _temp << std::endl;
    std::cout << "Humidity : " << _hum << std::endl;
    std::cout << "Pressure : " << _pre << std::endl;
    std::cout << "---------------------------setMeasurements---------------------------\033[0m" << std::endl;
    this->_temperature = _temp;
    this->_humidity = _hum;
    this->_pressure = _pre;
    this->measurementsChanged();
}

float WeatherData::getTemperature() {
    assert(this->_temperature);
    return this->_temperature;
}

float WeatherData::getHumidity() {
    assert(this->_humidity);
    return this->_humidity;
}

float WeatherData::getPressure() {
    assert(this->_pressure);
    return this->_pressure;
}
