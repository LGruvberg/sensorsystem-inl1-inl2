#include "../include/humidiSensor.h"
#include "../include/alarm.h"
#include "../include/alarmStorage.h"
#include <iostream>
#include <ctime>

double HumiditySensor::read(MeasurementStorage& storage, 
    AlarmStorage& alarms) {
    
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

    //  Verify alarm
    if (value > threshold) {
        Alarm a;
        a.sensorName = name;
        a.value = value;
        a.threshold = threshold;
        a.timestamp = m.timestamp;
        alarms.addAlarm(a);
    }

    std::cout << name << " = " << value << "\t" << unit << "\n";
    return value;

}