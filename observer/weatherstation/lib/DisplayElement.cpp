#include <iostream>
#include <cassert>
#include <memory>
#include "include/DisplayElement.h"
#include "include/WeatherData.h"

HeatIndexDisplay::HeatIndexDisplay(Subject* _data)
{
    assert(_data);
    this->_weatherData = _data;
    _weatherData->registerObserver(this);
}

void HeatIndexDisplay::update(float _temp, float _hum, float _pre)
{
    assert(_temp);
    assert(_hum);
    assert(_pre);
    this->calculateHeatIndex(_temp, _hum);
    this->display();
}

void HeatIndexDisplay::calculateHeatIndex(float t, float rh)
{
    assert(t);
    assert(rh);
    this->_heatindex = (float)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh)
            + (0.00941695 * (t * t)) + (0.00728898 * (rh * rh))
            + (0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
            (0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 *
            (rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) +
            (0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +
            0.000000000843296 * (t * t * rh * rh * rh)) -
            (0.0000000000481975 * (t * t * t * rh * rh * rh)));
}

void HeatIndexDisplay::display()
{
    std::cout << "\033[31m--------------------------HeatIndexDisplay---------------------------\033[0m" << std::endl;
    std::cout << "HeatIndex is " << this->_heatindex << std::endl;
    std::cout << "--------------------------HeatIndexDisplay---------------------------" << std::endl;
}

StatisticsDisplay::StatisticsDisplay(Subject* _data)
{
    assert(_data);
    this->_weatherData = _data;
    _weatherData->registerObserver(this);
}

void StatisticsDisplay::update(float _temp, float _hum, float _pre)
{
    assert(_temp);
    assert(_hum);
    assert(_pre);
    this->_maxTemp = std::max(_temp, this->_maxTemp);
    this->_minTemp = std::min(_temp, this->_minTemp);
    this->_tempSum += _temp;

    this->_maxHum = std::max(_hum, this->_maxHum);
    this->_minHum = std::min(_hum, this->_minHum);
    this->_humSum += _hum;

    this->_maxPre = std::max(_pre, this->_maxPre);
    this->_minPre = std::min(_pre, this->_minPre);
    this->_preSum += _pre;

    this->display();
}

void StatisticsDisplay::display()
{
    std::cout << "\033[31m--------------------------StatisticsDisplay--------------------------\033[0m" << std::endl;
    std::cout << "Max temperature is " << this->_maxTemp << ", Min temperature is " << this->_minTemp << std::endl;
    std::cout << "Temperature sum is " << this->_tempSum << std::endl;
    std::cout << "Max humidity is " << this->_maxHum << ", Min humidity is " << this->_minHum << std::endl;
    std::cout << "Humidity sum is " << this->_humSum << std::endl;
    std::cout << "Max pressure is " << this->_maxPre << ", Min pressure is " << this->_minPre << std::endl;
    std::cout << "Pressure sum is " << this->_preSum << std::endl;
    std::cout << "--------------------------StatisticsDisplay--------------------------" << std::endl;
}

ForecastDisplay::ForecastDisplay(Subject* _data)
{
    assert(_data);
    this->_weatherData = _data;
    _weatherData->registerObserver(this);
}

void ForecastDisplay::update(float _temp, float _hum, float _pre)
{
    assert(_temp);
    assert(_hum);
    assert(_pre);
    this->_lastTemperature = this->_currentTemperature;
    this->_currentTemperature = _temp;
    this->_lastHumidity = this->_currentHumidity;
    this->_currentHumidity = _hum;
    this->_lastPressure = this->_currentPressure;
    this->_currentPressure = _pre;

    this->display();
}

void ForecastDisplay::display()
{
    std::cout << "\033[31m---------------------------ForecastDisplay---------------------------\033[0m" << std::endl;
    std::cout << "Last temperature is " << this->_lastTemperature << ", Current temperature is " << this->_currentTemperature << std::endl;
    std::cout << "Last humidity is " << this->_lastHumidity << ", Current humidity is " << this->_currentHumidity << std::endl;
    std::cout << "Last pressure is " << this->_lastPressure << ", Current pressure is " << this->_currentPressure << std::endl;
    std::cout << "---------------------------ForecastDisplay---------------------------" << std::endl;
}

CurrentConditionDisplay::CurrentConditionDisplay(Subject* _data)
{
    assert(_data);

    this->_weatherData = _data;
    _weatherData->registerObserver(this);
}

void CurrentConditionDisplay::update(float _temp, float _hum, float _pre)
{
    assert(_temp);
    assert(_hum);
    assert(_pre);
    this->_temperature = _temp;
    this->_humidity = _hum;
    this->_pressure = _pre;

    this->display();
}

void CurrentConditionDisplay::display()
{
    std::cout << "\033[31m-----------------------CurrentConditionDisplay-----------------------\033[0m" << std::endl;
    std::cout << "Temperature is " << this->_temperature << std::endl;
    std::cout << "Humidity is " << this->_humidity << std::endl;
    std::cout << "Pressure is " << this->_pressure << std::endl;
    std::cout << "-----------------------CurrentConditionDisplay-----------------------" << std::endl;
}
