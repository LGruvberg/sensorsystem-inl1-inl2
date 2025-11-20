#pragma once
#include "measurement.h"
#include "storage.h"
#include "alarmStorage.h"
#include <string>

class Sensor {
    public:
    virtual ~Sensor() = default;    // Important! (For polymorphism)

    //  Pure virtual interface
    virtual std::string getName() const = 0;
    virtual std::string getUnit() const = 0;

    //  Threshold interface
    virtual void setThreshold(double t) = 0;
    virtual double getThreshold() const = 0;

    //  Alarm storage is added to read()
    virtual double read(MeasurementStorage& storage, 
        AlarmStorage& alarmStorage) = 0;

};