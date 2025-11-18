#pragma once
#include <string>

namespace utils {
    //  read int from user (safe)
    bool inputInt(int& out);

    //  main menu print
    void printMainMenu();

    //  clear terminal
    void clearScreen();
}