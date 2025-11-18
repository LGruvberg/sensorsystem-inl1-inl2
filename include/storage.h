#pragma once
#include "measurement.h"
#include <vector>

class MeasurementStorage {  // class storing all measurements
    private:
    std::vector<Measurement> measurements;
public:
    //  Add a measurement to internal storage
    void addMeasurement(const Measurement& m);

    //  Print all stored measurements
    void printAll() const;
};