#pragma once
#include "sensor.h"
#include <random>

class TemperatureSensor : public Sensor {
private:
    std::string name = "Temperature";
    std::string unit = "C";
    double minV = -50.0;
    double maxV = 300.0;

public:
    TemperatureSensor() = default;

    std::string getName() const override { return name; }
    std::string getUnit() const override { return unit; }

    double read(MeasurementStorage& storage) override;
};