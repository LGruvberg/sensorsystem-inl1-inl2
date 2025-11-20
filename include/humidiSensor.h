#pragma once
#include "sensor.h"
#include <random>

class HumiditySensor : public Sensor {
private:
    std::string name = "Humidity";
    std::string unit = "%";
    double minV = 20.0;
    double maxV = 80.0;

public:
    HumiditySensor() = default;

    std::string getName() const override { return name; }
    std::string getUnit() const override { return unit; }

    double read(MeasurementStorage& storage) override;
};