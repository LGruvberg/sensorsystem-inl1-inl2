#include "../include/sensor.h"
#include "../include/storage.h"
#include "../include/utils.h"
#include "../include/statistics.h"

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

(Note-to-self: commita i "presens", istället för "Added". skriv "Add")
*/

int main() {
    //  Create storage obj (there should be just one while running the program)
    MeasurementStorage storage;

    //  Create sensors
    Sensor temperature("Temperature", "C", -50.0, 300.0);
    Sensor light("Light", "lx", 0.0, 1000.0);
    Sensor humidity("Humidity", "%", 20.0, 80.0);

    //  put sensors in vector container
    std::vector<Sensor> sensors = { temperature, light, humidity };

    int choice = 0;

    while (true) {
        utils::printMainMenu();

        if (!utils::inputInt(choice)) {
            std::cout << ":: Invalid input\n";
            continue;
        }

        utils::clearScreen();

        if (choice == 5) {
            std::cout << ":: Shutting down...\n";
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
            case 2: {// show all measurements
                // storage.printAll();
                std::cout
                << "\n.:::::::: STATISTICS ::::::::."
                << "\nSelect sensor:\n"
                << "1. Temperature\n"
                << "2. Light\n"
                << "3. Humidity\n"
                << "Select: ";

                int s = 0;

                if (!utils::inputInt(s)) {  // if 'input != 0'
                    std::cout << ":: Invalid input\n";
                    break;
                }

                std::string selectedSensor;

                if (s == 1) {
                    selectedSensor = "Temperature"; 
                }
                else if (s == 2) {
                    selectedSensor = "Light"; 
                } 
                else if (s == 3) {
                    selectedSensor = "Humidity";
                }
                else {
                    std::cout << ":: Invalid selection\n";
                    break;
                }

                // Get all measurements for THIS sensor
                auto data = storage.getBySensor(selectedSensor);

                if (data.empty()) {
                    std::cout << ":: No measurements found for '"
                    << selectedSensor << "'\n";
                    break;
                }

                //  Compute statistics
                auto minM   = statistics::getMin(data);
                auto maxM   = statistics::getMax(data);
                double mean = statistics::getMean(data); 
                double sd = statistics::getStdDev(data);
                
                    std::cout << "\nStatistics for sensor: " << selectedSensor << "\n";
                    std::cout << "--------------------------------\n";
                    std::cout << "Count: " << data.size() << "\n";
                    std::cout << "Min:   " << minM.value << " " << minM.unit << "\n";
                    std::cout << "Max:   " << maxM.value << " " << maxM.unit << "\n";
                    std::cout << "Mean:  " << mean << "\n";
                    std::cout << "StdDev:" << sd << "\n";
                

                break;
            }

            case 3:
            storage.saveToFile("data/measurements.csv");
            std::cout << ":: Saved measurements to 'data/measurements.csv'\n";
                break;

            case 4:
            storage.loadFromFile("data/measurements.csv");
            std::cout << ":: Loaded measurements from 'data/measurements.csv'\n";
                break;

            default:
                std::cout << ":: Invalid option\n";
                break;
            }
        }
        return 0;
    }
    
//  C:\repo\NewRepo\PyProj\Lavalamp_proj
//  När du har joinat en thread, så vill du inte joina igen
//  Automic is a thread-safe bool,