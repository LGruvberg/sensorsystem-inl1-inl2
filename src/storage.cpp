#include "../include/storage.hpp"
#include <iostream>
#include <iomanip>

void MeasurementStorage::addMeasurement(const Measurement& m) {
    measurements.push_back(m);
}

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