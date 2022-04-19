#ifndef _DISPLAY_ELEMENT_H_
#define _DISPLAY_ELEMENT_H_

#include <iostream>
#include <memory>

class Subject;
class Observer
{
    protected:
        virtual ~Observer()
        {
            std::cout << "Observer desruct" << std::endl;
        }

    public:
        Observer()
        {
            std::cout << "Observer construct" << std::endl;
        }
        virtual void update(float, float, float) = 0;
};

class DisplayElement
{
    protected:
        virtual ~DisplayElement()
        {
            std::cout << "DisplayElement destruct" << std::endl;
        }

    public:
        DisplayElement()
        {
            std::cout << "DisplayElement construct" << std::endl;
        }
        virtual void display() = 0;
};

class HeatIndexDisplay : private Observer, private DisplayElement
{
    public:
        HeatIndexDisplay()
        {
            std::cout << "HeatIndexDisplay construct" << std::endl;
        }
        HeatIndexDisplay(Subject*);
        ~HeatIndexDisplay()
        {
            std::cout << "HeatIndexDisplay destruct" << std::endl;
        }
        void update(float, float, float);
        void display();
        void calculateHeatIndex(float, float);

    private:
        float _heatindex = 0;
        Subject* _weatherData;
};

class StatisticsDisplay : private Observer, private DisplayElement
{
    public:
        StatisticsDisplay()
        {
            std::cout << "StatisticsDisplay construct" << std::endl;
        }
        StatisticsDisplay(Subject*);
        ~StatisticsDisplay()
        {
            std::cout << "StatisticsDisplay destruct" << std::endl;
        }
        void update(float, float, float);
        void display();

    private:
        float _maxTemp = 0;
        float _minTemp = 9999;
        float _tempSum = 0;
        float _maxHum = 0;
        float _minHum = 9999;
        float _humSum = 0;
        float _maxPre = 0;
        float _minPre = 9999;
        float _preSum = 0;
        float _numReadings;
        Subject* _weatherData;
};

class ForecastDisplay : private Observer, private DisplayElement
{
    public:
        ForecastDisplay()
        {
            std::cout << "ForecastDisplay construct" << std::endl;
        }
        ForecastDisplay(Subject*);
        ~ForecastDisplay()
        {
            std::cout << "ForecastDisplay destruct" << std::endl;
        }
        void update(float, float, float);
        void display();

    private:
        float _currentTemperature = 0;
        float _lastTemperature = 0;
        float _currentHumidity = 0;
        float _lastHumidity = 0;
        float _currentPressure = 0;
        float _lastPressure = 0;
        Subject* _weatherData = 0;
};

class CurrentConditionDisplay : private Observer, private DisplayElement
{
    public:
        CurrentConditionDisplay()
        {
            std::cout << "CurrentConditionDisplay construct" << std::endl;
        }
        CurrentConditionDisplay(Subject*);
        ~CurrentConditionDisplay()
        {
            std::cout << "CurrentConditionDisplay destruct" << std::endl;
        }
        void update(float, float, float);
        void display();

    private:
        float _temperature;
        float _humidity;
        float _pressure;
        Subject* _weatherData;
};

#endif
