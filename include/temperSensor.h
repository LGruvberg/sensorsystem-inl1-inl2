#pragma once
#include "sensor.h"
#include "alarmStorage.h"
#include <random>
#include <limits>

class TemperatureSensor : public Sensor {
private:
    std::string name = "Temperature";
    std::string unit = "C";
    double minV = -50.0;
    double maxV = 300.0;

    double threshold = std::numeric_limits<double>::max(); // default: disables alarm

public:
    TemperatureSensor() = default;

    std::string getName() const override { return name; }
    std::string getUnit() const override { return unit; }

    double getMax() const override { return maxV; }
    double getMin() const override { return minV; }

    double read(MeasurementStorage& storage,
        AlarmStorage& alarmStorage) override;

    void setThreshold(double t) override { threshold = t; }
    double getThreshold() const override { return threshold; }
};