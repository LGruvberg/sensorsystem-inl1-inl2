#pragma once
#include "measurement.h"
#include <vector>
#include <string>

class MeasurementStorage {     
private:
    std::vector<Measurement> measurements;  // store all measurements in memory

public:
    //  Add a measurement to internal storage
    void addMeasurement(const Measurement& m);

    //  Print all stored measurements
    void printAll() const;

    void saveToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename);

private:
    //  Convert "name, unit, value, timestamp" into a Measurement object
    Measurement parseCSVLine(const std::string& line) const;
};