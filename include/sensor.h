#pragma once
#include "measurement.h"
#include "storage.h"
#include <string>

class Sensor {
    public:
    virtual ~Sensor() = default;    // For polymorphism

    //  Pure virtual interface
    virtual std::string getName() const = 0;
    virtual std::string getUnit() const = 0;

    //  Reads a value, creates Measurement, and stores it
    virtual double read(MeasurementStorage& storage) = 0;

    // private:
    // std::string name;    // member variable
    // std::string unit;
    // double minValue;
    // double maxValue;
    // public:
    // Sensor(
    //     const std::string& n,
    //     const std::string& u,
    //     double minV,
    //     double maxV)
    //     : name(n), unit(u), minValue(minV), maxValue(maxV) {}
    //     std::string getName() const { return name; }
    //     std::string getUnit() const { return unit; }
    //     //  Readin simulation and return measurement value
    //     double read(MeasurementStorage& storage);
};