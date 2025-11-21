#include "../include/utils.h"
#include <iostream>
#include <limits>
#include <unordered_map>
#include <iomanip>

namespace utils {
    
    bool inputInt(int& out) {
        std::cin >> out;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        return true;
    }

    bool inputDouble(double& out) {
        std::cin >> out;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        return true;
    }
    
    void printMainMenu(const std::string& hint) {
        std::cout 
        << "\n.:::::::::::::: MAIN :: MENU ::::::::::::::.\n"
        << "1.\tRead new measurements from sensor(s)"<< hint <<"\n"
        << "2.\tShow measurements and statistics\n"
        << "3.\tSave measurements to file\n"
        << "4.\tLoad measurements from file\n"
        << "5.\tExit\n"
        << "6.\tThreshold config\n"
        << "7.\tShow alarms\n"
        << "Select:\t";
}
void printSensorMenu(const std::vector<std::unique_ptr<Sensor>>& sensors) {
    std::cout 
    << "\n.:::::: SENSOR :: MENU ::::::."
    << "\n:: Read new measurements from:\n"
    << "\033[1m1.\tALL sensors\033[0m\n";

    int index = 2;

    std::cout << "\033[33m";    // color yellow
    for (const auto& s : sensors) {
        std::cout << "::\t" << index << ". " << s->getName() << "\n";
        index++;
    }
    std::cout << "\033[0m";     // color reset

    std::cout << index << ".\tReturn to main menu\n";
    std::cout << "Select:\t";

}

void printStatsMenu(const std::vector<std::unique_ptr<Sensor>>& sensors) {
    std::cout
    << ":::::::: STATISTICS MENU ::::::::"
    << "\nSelect sensor:\n"
    << "1. All sensors\n";

    int index = 2;
    for (const auto& s : sensors) {
        std::cout << index << ".\t" 
        << s->getName() << "\n";
        index++;
    }

    std::cout << index << ". Return to main menu\n"; // index number becomes the last alternative's number
    std::cout << "Select:\t";
}

void printThresholdMenu(const std::vector<std::unique_ptr<Sensor>>& sensors) {
    std::cout << "\n:::: THRESHOLD CONFIGURATION ::::\n";
    std::cout << "1.\tReturn to main menu\n";

    int index = 2;
    for (const auto& s : sensors) {
        std::cout << index << ".\t"
          << s->getName()
          << " (current threshold = "
          << s->getThreshold() << " " << s->getUnit() << ")\n";
        index++;
    }
    std::cout << "Select:\t";
}

void clearScreen() {
    system("cls||clear");
}

void printSensorBreakdown(const std::unordered_map<std::string, int>& counts) {
    if (!counts.empty()) {
        std::cout << "Each measurement:\n";
        for (const auto& [sensor, count] : counts) {
            std::cout << "-\t\033[36m" << sensor << ":\033[0m\t" << count << " measures\n";
        }
    }
}
}