#include "../include/illumiSensor.h"
#include <iostream>
#include <ctime>

double IlluminanceSensor::read(MeasurementStorage& storage) {
    
    //  Randomizer
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(minV, maxV);
    double value = dist(gen);

    //  Create measurement
    Measurement m;
    m.sensorName = name;
    m.unit = unit;
    m.value = value;
    m.timestamp = std::time(nullptr);
    storage.addMeasurement(m);

    std::cout << name << " = " << value << "\t" << unit << "\n";
    return value;

}