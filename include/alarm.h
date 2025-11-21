#pragma once
#include <ctime>
#include <string>

struct Alarm {
    std::string sensorName;
    double value;
    double threshold;
    std::time_t timestamp;
};