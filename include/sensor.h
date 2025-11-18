#pragma once;
#include "measurement.h"
#include "storage.h"
#include <string>
#include <random>

class Sensor {
    private:
    std::string name;
    std::string unit;
    double minValue;
    double maxValue;

    public:
    Sensor(
        const std::string& n,
        const std::string& u,
        double minV,
        double maxV)
        : name(n), unit(u), minValue(minV), maxValue(maxV) {}

        std::string getName() const { return name; }
        std::string getUnit() const { return unit; }

        //  Readin simulation and return measurement value
        double read(MeasurementStorage& storage);
};