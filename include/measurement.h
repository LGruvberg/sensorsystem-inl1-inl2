#pragma once
#include <string>
#include <ctime>

struct Measurement {
    std::string sensorName; // Temperature, Illuminance, Humidity
    std::string unit;       // '%'
    double values;          // sensor values
    std::time_t timestamp;
};