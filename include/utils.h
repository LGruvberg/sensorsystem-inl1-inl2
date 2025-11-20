#pragma once
#include <string>
#include <unordered_map>

namespace utils {
    //  Read int from user (safe)
    bool inputInt(int& out);

    //  Menus
    void printMainMenu(const std::string& hint = "");
    void printSensorMenu();
    void printStatsMenu();

    //  Clear terminal
    void clearScreen();

    //  To add: Bad input

    //  Count each different sensor measure in storage
    void printSensorBreakdown(const std::unordered_map<std::string, int>& counts);

}