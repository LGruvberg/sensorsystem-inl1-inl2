#include "../include/utils.hpp"
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
    std::cout << "\n===== MAIN MENU =====\n"
              << "1. Read new measurements from all sensors\n"
              << "2. Show statistics per sensor\n"
              << "3. Show all measurements\n"
              << "4. Save measurements to file\n"
              << "5. Load measurements from file\n"
              << "6. Exit\n"
              << "Select option: ";
}

void clearScreen() {
// #ifdef _WIN32
    system("cls||clear");
// #endif
}
}