#include "../include/storage.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

void MeasurementStorage::addMeasurement(const Measurement& m) {
    measurements.push_back(m);
}

//  Print all measurements to terminal
void MeasurementStorage::printAll() const {
    if (measurements.empty()) {
        std::cout << "There aren't any measurements to store ... Yet.\n";
        return;
    }
    for (const auto& m : measurements) {
        std::tm* tm_ptr = std::localtime(&m.timestamp);
        std::cout << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S")
        << m.sensorName << ":\t"
        << m.value << " " 
        << m.unit
        << "\n"
        ;
    }
}

//  Save all 'm' to .csv-file
void MeasurementStorage::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << ":: Failed to open file for writing: " << filename << "\n";
        return;
    }

    // Write .csv header
    file << "sensorName,unit,value,timestamp\n";

    // Write each measurement
    for (const auto& m : measurements) {
        file << m.sensorName << ","
             << m.unit << ","
             << m.value << ","
             << m.timestamp << "\n";
    }

    std::cout << "Saved " << measurements.size()
    << " measurements to '" << filename << "'\n";
}

//  Load measurements from .csv-file
void MeasurementStorage::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << ":: Failed opening file '" << filename << "' for reading...\n";
        return;
    }

    std::string line;
    bool skipHeader = true;
    
    while (std::getline(file, line)) {
        if (skipHeader) {
        skipHeader = false;
        continue;
        }
        if (!line.empty()) {
            measurements.push_back(parseCSVLine(line));
        }
    }
    std::cout << "Loaded '" << filename << "'\n";
}

//  Convert one .csv-line into a Measurement object
Measurement MeasurementStorage::parseCSVLine(const std::string& line) const {
    std::stringstream ss(line);
    std::string part;

    Measurement m;

    std::getline(ss, m.sensorName, ',');
    std::getline(ss, m.unit, ',');
    
    std::getline(ss, part, ',');
    m.value = std::stod(part);

    std::getline(ss, part, ',');    
    m.timestamp = static_cast<std::time_t>(std::stoll(part));
    
    return m;

}

// bas-klass-pointer