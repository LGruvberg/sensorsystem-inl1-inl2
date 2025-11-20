#pragma once
#include "alarm.h"
#include <vector>

class AlarmStorage {
    private:
    std::vector<Alarm> alarms;

    public:
    void addAlarm(const Alarm& a) { alarms.push_back(a); }
    const std::vector<Alarm>& getAll() const { return alarms; }

    void printAll() const;
    
};