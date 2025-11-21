#pragma once
#include "sensor.h"
#include "alarmStorage.h"
#include <random>
#include <limits>

class IlluminanceSensor : public Sensor {
private:
    std::string name = "Illuminance";
    std::string unit = "lx";
    double minV = 0.0;
    double maxV = 1000.0;

    double threshold = std::numeric_limits<double>::max(); // default: disables alarm

public:
    IlluminanceSensor() = default;

    std::string getName() const override { return name; }
    std::string getUnit() const override { return unit; }

    double getMax() const override { return maxV; }
    double getMin() const override { return minV; }

    double read(MeasurementStorage& storage,
        AlarmStorage& alarmStorage) override;

    void setThreshold(double t) override { threshold = t; }
    double getThreshold() const override { return threshold; }
};