#include "../include/storage.h"
#include "../include/utils.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <unordered_map>

void MeasurementStorage::addMeasurement(const Measurement& m) {
    measurements.push_back(m);
}

//  Print all measurements to terminal
void MeasurementStorage::printAll() const {
    if (measurements.empty()) {
        std::cout << "\033[31m!! \033[4m"  //  Print it in blood RED!
        << "No measurements stored\033[0m\033[31m... Yet.\n\033[0m";
        return;
    }
    for (const auto& m : measurements) {
        std::tm* tm_ptr = std::localtime(&m.timestamp);
        std::cout << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S") << "\t"
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

    //  Write .csv header in csv format
    file << "sensorName,unit,value,timestamp\n";
    //  Write each measurement  (in .csv format)
    for (const auto& m : measurements) {
        file << m.sensorName << ","
             << m.unit << ","
             << m.value << ","
             << m.timestamp << "\n";
            }

    //  If measurements exist, print a breakdown of featured measures
    auto counts = getSensorCounts();
    if (!measurements.empty()) {
        std::cout << "::\033[1m\033[32m Saved " << measurements.size() 
        << " measurements to '" << filename << "'\033[0m\n";
        utils::printSensorBreakdown(counts);
    } else {
        std::cout << "\033[31m!!\t'\033[4m"
        << measurements.size() << "\033[0m\033[31m"
        << " measures', there's nothing to save..."
        << "\033[0m\n";
        }
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
    //  Loaded measurements message
    auto counts = getSensorCounts();
    if (measurements.size() != 0) {
        std::cout << "::\033[1m\033[34m Loaded from '" << filename << "', there are now " << measurements.size() 
        << " measurements.\n\033[0m";
        utils::printSensorBreakdown(counts);
    } else {
        std::cout << "\033[31m!!\t'\033[4m"<< measurements.size() 
        << "\033[0m\033[31m measures', there's nothing to load.\033[0m\n";
    }
}

// Function: count each different sensor measure in storage
std::unordered_map<std::string, int> MeasurementStorage::getSensorCounts() const {
    std::unordered_map<std::string, int> counts;
    for (const auto& m : measurements) {
        counts[m.sensorName]++;
    }
    return counts;
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

std::vector<Measurement> MeasurementStorage::getBySensor(
    const std::string& sensorName) const {
    std::vector<Measurement> filtered;

    for (const auto& m : measurements) {
        if (m.sensorName == sensorName) {
            filtered.push_back(m);
        }
    }
    return filtered;
}

// kika på bas-klass-pointer