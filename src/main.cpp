#include "../include/sensor.h"
#include "../include/storage.h"
#include "../include/utils.h"
#include "../include/statistics.h"
#include "../include/temperSensor.h"
#include "../include/illumiSensor.h"
#include "../include/humidiSensor.h"

#include <iostream>
#include <vector>
#include <memory>

int main() {
    //  Create storage obj (there should be just one while running the program)
    MeasurementStorage storage;

    std::vector<std::unique_ptr<Sensor>> sensors;
    
    sensors.push_back(std::make_unique<TemperatureSensor>());
    sensors.push_back(std::make_unique<IlluminanceSensor>());
    sensors.push_back(std::make_unique<HumiditySensor>());

    int choice = 0;
    std::string hint = "";

    utils::clearScreen();

    while (true) {
        utils::printMainMenu(hint);

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
                    // s.read(storage);
                    s->read(storage);
                }
            }
            else if (sub == 2) {
                // sensors[0].read(storage);   //  Vector position for Temperature
                sensors[0]->read(storage);
            }
            else if (sub == 3) {
                sensors[1]->read(storage);   //  -||- for Light
            }
            else if (sub == 4) {
                sensors[2]->read(storage);   //  -||- for Humidity
            }
            else if (sub == 5) {
                //  Return to main menu
            }
            else {
                std::cout << ":: Invalid selection\n";
            }

            hint = "";  // Measures exist, remove hint
            break;
        }
        
        
        case 2: {// show all measurements
            std::cout << "\n.::::::: STORED MEASURES :::::::.\n";
            storage.printAll();
            utils::printStatsMenu();

            int s = 0;

            if (!utils::inputInt(s)) {  // if 'input != 0'
                std::cout << ":: Invalid input\n";
                break;
            }

            std::vector<Measurement> data;
            if (s == 1) {   // ALL sensors
                data = storage.getAll();
            }
            else if (s == 2) {
                data = storage.getBySensor("Temperature");
            }
            else if (s == 3) {
                data = storage.getBySensor("Illuminance");
            }
            else if (s == 4) {
                data = storage.getBySensor("Humidity");
            }
            else if (s == 5) {
                //  Return to main menu
            }
            else {
                std::cout << ":: Invalid selection\n";
                break;
            }

            if (data.empty()) {
                utils::clearScreen();
                std::cout << "\033[31m!! "   // (color coding)
                << "Statistics unavailable (Empty dataset)\033[0m";

                hint = "\033[1m\033[33m\t<- [Select to read measurements]\033[0m";

                break;
            }

            //  Compute statistics
            auto minM = statistics::getMin(data);
            auto maxM = statistics::getMax(data);
            double mean = statistics::getMean(data);
            double sd = statistics::getStdDev(data);

            // Print statistics header
            std::cout << "\nStatistics for: ";
            if (s == 1)         std::cout << "ALL sensors\n";
            else if (s == 2)    std::cout << "Temperature\n";
            else if (s == 3)    std::cout << "Illuminance\n";
            else if (s == 4)    std::cout << "Humidity\n";
            std::cout << ".:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.\n";
            std::cout << "Count: " << data.size() << "\n";
            std::cout << "Min:   " << minM.value << " " << minM.unit << "\n";
            std::cout << "Max:   " << maxM.value << " " << maxM.unit << "\n";
            std::cout << "Mean:  " << mean << "\n";
            std::cout << "StdDev:" << sd << "\n";

            break;
        }

        case 3:
            storage.saveToFile("data/measurements.csv");
            break;

        case 4:
            storage.loadFromFile("data/measurements.csv");
            break;

        default:
            std::cout << ":: Invalid option\n";
            break;
        }
    }
    return 0;
}