#include "../include/utils.h"
#include <iostream>
#include <limits>

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

void printMainMenu() {
    std::cout 
    << "\n.:::::::::::::: MAIN :: MENU ::::::::::::::.\n"
    << "1.\tRead new measurements from sensor(s)\n"
    << "2.\tShow all measurements\n"
    << "3.\tSave measurements to file\n"
    << "4.\tLoad measurements from file\n"
    << "5.\tExit\n"
    << "Select:\t";
}

void printSensorMenu() {
    std::cout 
    << "\n.:::::: SENSOR :: MENU ::::::."
    << "\n:: Read new measurements from:\n"
    << "1.\tALL sensors\n"
    << "2.\tSensor:\tTemperature\n"
    << "3.\tSensor:\tLight\n"
    << "4.\tSensor:\tHumidity\n"
    << "5.\tReturn to main menu\n"
    << "Select:\t";
}

void clearScreen() {
// #ifdef _WIN32
    system("cls||clear");
// #endif
}
}