#pragma once
#include "sensor.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

namespace utils {
    //  Read int from user (safe)
    bool inputInt(int& out);

    //  Menus
    void printMainMenu(const std::string& hint = "");
    void printSensorMenu(const std::vector<std::unique_ptr<Sensor>>& sensors);
    void printStatsMenu(const std::vector<std::unique_ptr<Sensor>>& sensors);

    //  Clear terminal
    void clearScreen();

    //  Count each different sensor measure in storage
    void printSensorBreakdown(const std::unordered_map<std::string, int>& counts);

}