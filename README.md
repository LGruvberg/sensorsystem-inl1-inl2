# IoT25_LovGru-oop-assignment1

#### How to compile and run
```bash
# In terminal, if 'g++ src/*.cpp -o SensorSystem' doesn't work for you...

# run:
g++ src/main.cpp src/utils.cpp src/sensor.cpp src/storage.cpp src/statistics.cpp -o SensorSystem.exe

# then, run: 
.\SensorSystem.exe
```

## Functionality
##### This program simulates IoT sensor output
**so far, it uses three sensors:**
-   Temperature (C)
-   Illuminance (lx)
-   Humidity (%)

**Every time a sensor is read, a measurement object is created**
**it consists of:**
-   Sensor name
-   Unit
-   Value
-   Timestamp
All values are stored in a vector, inside MeasurementStorage.

### Additional features implemented (not required)
-	Color-coded menu output	(occationally).
-	Detailed save/load log showing amount of measurements from each sensor.
-	Hidden variable message in main menu (std::string hint) 
    -   is empty until the user navigates to statistics without there being data.

### User Interface
*The UI consists of one main menu, and two sub menus*

#### The Main Menu
1.  **Read new measurements from sensor(s)**
    ∟   Navigate to the Sensor sub menu, where you can:
        1.  *Read from ALL sensors*
        2.  *Read from one specific sensor*
        3.  *-||-*
        4.  *-||-*
        5.  *Return to the main menu*
2.  **Show measurements and statistics**
    Here, all of your current measurements will show.
    ∟   You will also navigate to the Statistics sub menu,
        Where you can:
        1.  *Show statistics for ALL sensors*
        2.  *Show statistics from one specific sensor*
        3.  *-||-*
        4.  *-||-*
        5.  *Return to the main menu*
3.  **Save measurements to file**
    ∟   Save measurements to .csv file.
4.  **Load measurements from file**
    ∟   Load measurements from .csv file.
5.  **Exit**
    ∟   Kill / stop running the program (like 'CTRL + c').

### File structure

#### SensorSystemProject/
###### - .gitignore
###### - README.md
##### - data/
        ∟   measurements.csv
*I could've excluded the data folder (↑) in .gitignore, but I think it's good to be able to peak at it in my GitHub repo.*

##### - src/
        ∟   main.cpp
        ∟   sensor.cpp
        ∟   storage.cpp
        ∟   utils.cpp
        ∟   statistics.cpp

##### - include/
        ∟   measurement.h   |   struct Measurement
        ∟   sensor.h        |   *class Sensor* (reading and measurement creation)
        ∟   storage.h       |   *class Storage* (vector + save/load)
        ∟   utils.h         |   Input, menu functions (and some cool stuff)
        ∟   statistics.h    |   Max, Min, Mean, Standard Deviation

### measurement.h
**A simple struct** (like a skeleton)
that consists of the following variables:
    **string sensorName**
    **string unit**
    **double value**
    **std::time_t timestamp**

#### MeasurementStorage
-	Stores all measurements in a std::vector<Measurement>
-	Can filter measurements by sensor
-	saveToFile() and loadFromFile() for saving .csv file
-	Has helper methods such as getSensorCounts()

#### namespace statistics
**Calculates:**
-	minimun value
-	maximum value
-	mean
-	standard deviation

#### utils
-	integer input (safe)
-	Menus for 
    -   Main menu
    -   Sensor meun
    -   Statistics menu
-	Clear screen    (like 'clear' in the terminal) 
-   Colored text displaying amount of each sensor type loaded or saved.

~~To do~~:
-   Menu, interface
-   Struct for measurement values
-   Multiple .h/.cpp files
-   Simulate multiple sensors
-   input handling
-   Storage in vector
-   Statistics - min/max/mean/stddev
-   File handling, save/load