#pragma once
#include "sensor.h"
#include <random>

class IlluminanceSensor : public Sensor {
private:
    std::string name = "Illuminance";
    std::string unit = "lx";
    double minV = 0.0;
    double maxV = 1000.0;

public:
    IlluminanceSensor() = default;

    std::string getName() const override { return name; }
    std::string getUnit() const override { return unit; }

    double read(MeasurementStorage& storage) override;
};