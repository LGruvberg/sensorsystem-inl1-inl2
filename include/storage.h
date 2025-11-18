#pragma once
#include "measurement.h"
#include <vector>
#include <string>

class MeasurementStorage {     
private:
    std::vector<Measurement> measurements;  // store all measurements in memory
    // std::vector<Measurement> getBySensor(const std::string& sensorName) const;  // Get all measurements belonging to one sensor name

public:

    //  Return all measurements for a sensor (used by main + statistics)
    std::vector<Measurement> getBySensor(
        const std::string& sensorName) const;

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