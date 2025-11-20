#include "../include/sensor.h"

// double Sensor::read(MeasurementStorage& storage) {
//     // Random generator
//     static std::random_device rd;
//     static std::mt19937 gen(rd());
//     std::uniform_real_distribution<double> dist(minValue, maxValue);
//     double value = dist(gen);
//     //  Create measurement
//     Measurement m;
//     m.sensorName = name;
//     m.unit = unit;
//     m.value = value;
//     m.timestamp = std::time(nullptr);
//     //  Store measure
//     storage.addMeasurement(m);
//     //  Output printout
//     std::cout << name << " = " << value << " " << unit << "\n";
//     return value;
// }