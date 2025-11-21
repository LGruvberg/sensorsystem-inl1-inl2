#include "../include/sensor.h"
#include "../include/storage.h"
#include "../include/utils.h"
#include "../include/statistics.h"
#include "../include/temperSensor.h"
#include "../include/illumiSensor.h"
#include "../include/humidiSensor.h"
#include "../include/alarm.h"
#include "../include/alarmStorage.h"

#include <iostream>
#include <vector>
#include <memory>

int main() {
    MeasurementStorage storage;
    AlarmStorage alarmStorage;

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
            utils::printSensorMenu(sensors);

            if (!utils::inputInt(sub)) {
                std::cout << ":: Invalid input\n";
                break;
            }

            utils::clearScreen();

            //  Sensor menu
            if (sub == 1) { // option 1. Read ALL sensors (element 1)
                for (auto& s : sensors)
                    s->read(storage, alarmStorage);
            }
            else if (sub >= 2 && sub <= (int)sensors.size() + 1) { 
                sensors[sub - 2]->read(storage, alarmStorage);    
                // 'sub -2' converts user's choice to the sensors's vector index position
                //  Say we've added a fourth sensor (sub = 5)...
                //  ...in that case, 'sensors[sub -2]' translates to 'sensors[3]', 
            }
            else if (sub == (int)sensors.size() + 2) { // positioned at index for 'return to main menu'
                //  Return to main menu
            }
            else {
                std::cout << ":: Invalid selection\n";
            }

            hint = "";  // Measures exist, remove hint
            break;
        }
        
        
        case 2: {   // show all measurements, statistics menu
            std::cout << ".::::::: STORED MEASURES :::::::." << std::endl;
            storage.printAll();

            utils::printStatsMenu(sensors);
            int s = 0;
            if (!utils::inputInt(s)) {  // if 'input != 0'
                std::cout << ":: Invalid input\n";
                break;
            }

            std::vector<Measurement> data;
            
            if (s == 1) {   // ALL sensors
                data = storage.getAll();
            }
            else if (s >= 2 && s <= (int)sensors.size() + 1) {
                std::string sensorName = sensors[s - 2]->getName();
                data = storage.getBySensor(sensorName);
            }
            else if (s == (int)sensors.size() + 2) { // Return to main meun
                break;
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

            // Print statistics header (brief)
            std::cout << "\nStatistics for: ";
            if (s == 1) {
                std::cout << "All sensors\n";
            } else {
                std::cout << sensors[s - 2]->getName()
                << " (" << sensors[s - 2]->getUnit() << ")\n";
            }
            
            std::cout << ".:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.\n";
            std::cout << "Occurrances: " << data.size() << "\n";
            std::cout << "Min:\n-\t" << minM.value << " " << minM.unit << "\n";
            std::cout << "Max:\n-\t" << maxM.value << " " << maxM.unit << "\n";
            std::cout << "Mean:\n-\t" << mean << "\n";
            std::cout << "StdDev:\n-\t" << sd << "\n";

            break;
        }

        case 3:
            storage.saveToFile("data/measurements.csv");
            break;

        case 4:
            storage.loadFromFile("data/measurements.csv");
            break;

        case 6: {
            utils::printThresholdMenu(sensors);
            int choice = 0;

            if (!utils::inputInt(choice)) break;

            if (choice == 1) break; // Back to main meun

            if (choice >= 2 && choice <= sensors.size() + 1) {
                int index = choice -2;
                auto& sensor = sensors[index];

                //  display min/max
                std::cout << "Enter new threshold for "
                << sensor->getName()
                << " (" << sensor->getMin()
                << " to " << sensor->getMax()
                << "): ";

                double t;
                if (!utils::inputDouble(t)) {
                    std::cout << ":: Invalid input\n";
                    break;
                }

                //  Validate input
                if (t < sensor->getMin() || t > sensor->getMax()) {
                    std::cout << ":: Threshold outside valid range\n";
                    break;
                }
                sensor->setThreshold(t);
                std::cout << "Threshold updated.\n";
            }
            break;
        }
        case 7:
            alarmStorage.printAll();
            break;

        default:
            std::cout << ":: Invalid option\n";
            break;
        }
    }
    return 0;
}