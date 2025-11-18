#include "../include/sensor.h"
#include "../include/storage.h"
#include "../include/utils.h"

#include <iostream>
#include <vector>

/*
-   Create 3 sensors
-   Create one storage object
-   Show your main menu
-   Handle choices
-   Use your sensor submenu
-   Read measurements from all or one sensor
-   Print stored measurements
*/

int main() {
    //  Create storage
    MeasurementStorage storage;

    //  Create sensors
    Sensor temperature("Temperature", "C", -200.0, 200.0);
    Sensor light("Light", "lx", 0.0, 1000.0);
    Sensor humidity("Humidity", "%", 20.0, 80.0);

    //  put sensors in vector container
    std::vector<Sensor> sensors = { temperature, light, humidity };

    int choice = 0;

    while (true) {
        utils::printMainMenu();

        if (!utils::inputInt(choice)) {
            std::cout << ":: Invalid input\n";
            continue;   // back to top of loop
        }

        utils::clearScreen();

        if (choice == 5) {
            std::cout << "Shutting down program!\n";
            break;
        }

        switch (choice) {
            case 1: { // Read new measurements
                int sub = 0;
                utils::printSensorMenu();

                if (!utils::inputInt(sub)) {
                    std::cout << ":: Invalid input\n";
                    break;
                }

                utils::clearScreen();

                if (sub == 1) { //  Read ALL sensors
                    for (auto& s : sensors) {
                        s.read(storage);
                    }
                } else if (sub == 2) {
                    sensors[0].read(storage);   //  Vector position for Temperature
                } else if (sub == 3) {
                    sensors[1].read(storage);   //  -||- for Light
                } else if (sub == 4) {
                    sensors[2].read(storage);   //  -||- for Humidity
                } else if (sub == 5) {
                    //  Return to main menu
                } else {
                    std::cout << ":: Invalid selection\n";
                }

                break;
            }
            case 2: // show all measurements
            storage.printAll();
            break;

            case 3: // save (wip)
            std::cout << "Saving to file [WIP]\n";
            break;

            case 4: // load (wip)
            std::cout << "Loading to file [WIP]\n";
            break;

            default:
            std::cout << ":: Invalid option\n";
            break;
        }
        return 0;
    }
}