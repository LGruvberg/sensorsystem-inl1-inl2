#pragma once
#include "sensor.h"
#include "alarmStorage.h"
#include <random>
#include <limits>

class HumiditySensor : public Sensor {
private:
    std::string name = "Humidity";
    std::string unit = "%";
    double minV = 20.0;
    double maxV = 80.0;

    double threshold = std::numeric_limits<double>::max(); // default: disables alarm

public:
    HumiditySensor() = default;

    std::string getName() const override { return name; }
    std::string getUnit() const override { return unit; }

    double read(MeasurementStorage& storage,
        AlarmStorage& alarmStorage) override;

    void setThreshold(double t) override { threshold = t; }
    double getThreshold() const override { return threshold; }
};