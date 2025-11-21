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

        std::cout << "\033[31m:: " 
            << "[ALARM!] - " << a.sensorName << "\t"
            << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S\033[0m") 
            << "\n-\tValue:\t\t" << a.value
            << "\n-\tThreshold:\t" << a.threshold
            << "\n";
    }
}
