#include <iostream>
#include <memory>
#include "DisplayElement.h"
#include "WeatherData.h"

int main() {
    std::shared_ptr<WeatherData> _weatherData(new WeatherData());

    std::unique_ptr<HeatIndexDisplay> _heat(new HeatIndexDisplay(_weatherData.get()));
    std::unique_ptr<StatisticsDisplay> _statistic(new StatisticsDisplay(_weatherData.get()));
    std::unique_ptr<ForecastDisplay> _forecast(new ForecastDisplay(_weatherData.get()));
    std::unique_ptr<CurrentConditionDisplay> _current(new CurrentConditionDisplay(_weatherData.get()));

    //_weatherData->registerObserver(_heat.get());
    //_weatherData->registerObserver(_statistic.get());
    //_weatherData->registerObserver(_forecast.get());
    //_weatherData->registerObserver(_current.get());

    _weatherData->setMeasurements(80, 65, 30.4f);
    _weatherData->setMeasurements(82, 70, 29.2f);
    _weatherData->setMeasurements(78, 90, 29.2f);
    _weatherData->setMeasurements(81, 72, 30.9f);

    return 0;
}
