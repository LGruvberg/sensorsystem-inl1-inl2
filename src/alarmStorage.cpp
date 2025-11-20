#include "../include/alarmStorage.h"
#include <iostream>
#include <iomanip>

void AlarmStorage::printAll() const {
    if (alarms.empty()) {
        std::cout << "No alarms triggered... ...yet.\n";
        return;
    }

    for (const auto& a : alarms) {
        std::tm* tm_ptr = std::localtime(&a.timestamp);

        std::cout << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S")
                  << "::\t[ALARM]\t"    // works?
                  << a.sensorName
                  << " value=" << a.value
                  << " threshold=" << a.threshold
                  << "\n";
    }
}
