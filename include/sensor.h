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

};