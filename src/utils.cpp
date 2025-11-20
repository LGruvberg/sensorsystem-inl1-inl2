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
    
    void printMainMenu(const std::string& hint) {
        std::cout 
        << "\n.:::::::::::::: MAIN :: MENU ::::::::::::::.\n"
        << "1.\tRead new measurements from sensor(s)"<< hint <<"\n"
        << "2.\tShow measurements and statistics\n"
        << "3.\tSave measurements to file\n"
        << "4.\tLoad measurements from file\n"
        << "5.\tExit\n"
        << "Select:\t";
}
void printSensorMenu() {
    std::cout 
    << "\n.:::::: SENSOR :: MENU ::::::."
    << "\n:: Read new measurements from:\n"
    << "\033[36m1.\tALL sensors\033[0m\n"
    << "\033[33m"
    << "\t2. Temperature\n"
    << "\t3. Illuminance (light)\n"
    << "\t4. Humidity\033[0m\n"
    << "5.\tReturn to main menu\n"
    << "Select:\t";
}

void printStatsMenu() {
    std::cout
    << ":::::::: STATISTICS MENU ::::::::"
    << "\nSelect sensor:\n"
    << "1. All sensors\n"
    << ":: 2.\tTemperature\n"
    << ":: 3.\tIlluminance\n"
    << ":: 4.\tHumidity\033[0m\n"
    << "5. Return to main menu\n"
    << "Select: ";
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