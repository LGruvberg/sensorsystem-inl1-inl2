# sensorsystem-inl2

[GitHub sensorsystem-inl2](https://github.com/LGruvberg/sensorsystem-inl1-inl2.git)


#### How to compile and run
```bash
# In terminal, if 'g++ src/*.cpp -o SensorSystem' doesn't work for you...

# run:
g++ src/main.cpp src/utils.cpp src/storage.cpp src/statistics.cpp .\src\temperSensor.cpp .\src\illumiSensor.cpp .\src\humidiSensor.cpp .\src\alarmStorage.cpp -o SensorSystem

# then, run: 
.\SensorSystem.exe
```

**UML:** [sensor-system-LG-inl2-UML_TrueDark.drawio.png](https://drive.google.com/file/d/1KHXYC9Xv4IxFyxZxOrMZyvhOSwxuju6N/view?usp=sharing)

<img width="1352" height="1204" alt="sensor-system-LG-inl2-UML_TrueDark drawio" src="https://github.com/user-attachments/assets/743f5c23-28fc-4a0f-8caa-d1fa43287858" />

## Functionality
**This program simulates IoT sensor output.**

**The sensors available (so far):**
-   Temperature (C)
-   Illuminance (lx)
-   Humidity (%)

**Every time a sensor is read:**
-    A measurement object containing *name, unit, value and a timestamp* is created.
All values are stored inside MeasurementStorage.

### Additional features implemented (not required)
-	Color-coded menu output	(occationally).
-	Detailed save- and load log showing amount of measurements from each sensor.
-	Hidden variable message in main menu (std::string hint)
    -       hint = "" until the user navigates to statistics before there are any measures to od statistics on.
    -       Then, hint = "<- Select to read measurements", pointing at '1. Read new measurements from sensor(s)'.

### User Interface
*The UI consists of one main menu, and three sub menus*

#### The Main Menu
1.  **Read new measurements from sensor(s)**
    ∟   Navigate to the **Sensor sub menu**:
    -     Sensor menu
    -         1.    Read from ALL sensors
    -         2.    Read from specific sensor[0]
    -         3.    Read from specific sensor[1]
    -         4.    Read from specific sensor[2]
    -         5.    Return to main menu
2.  **Show measurements and statistics**
    *Here, all current measurements will show, you'll
    also navigate to the* **Statistics sub menu**:
    -     Statistics menu
    -         1.    Statistics from ALL sensors
    -         2.    Show statistics from specific sensor[0]
    -         3.    Show statistics from specific sensor[1]
    -         4.    Show statistics from specific sensor[2]
    -         5.    Return to main menu
3.  **Save measurements to file**
    ∟   Save measurements to .csv file.
4.  **Load measurements from file**
    ∟   Load measurements from .csv file.
5.  **Exit**
    ∟   Kill / stop running the program (like 'CTRL + c').
6.  **Threshold config**(uration)
    ∟    Set a threshold on a specific sensor value range.
    ∟    Navigate to the **Threshold sub menu**:
    -     Threshold configuration menu
    -          1.    Return to main menu
    -          2.    Temperature (current threshold: No threshold set)
    -          3.    Illuminance (current threshold: 24.00 lx)
    -          4.    Humidity    (current threshold: 57.00 %)
7.  **Show alarms**
    ∟    After setting a threshold on a specific sensor value range, 'Show alarms' provides an alarm log for each sensor measure that violated that value threshold.


# File structure
#### SensorSystemProject/
**.gitignore**
**README.md**
**data/**
        ∟    measurements.csv
*The data folder (↑) could've been .gitignored, but I like being able to [peak at it](https://github.com/LGruvberg/sensorsystem-inl1-inl2/blob/main/data/measurements.csv) in my GitHub repo for reference.*

**src/**
        ∟    main.cpp           | Program flow (main loop, menus) and polymorphic vector of Sensor objects
        ∟    storage.cpp        | MeasurementStorage: stores measurements, and save/load .csv
        ∟    utils.cpp          | Input handling and all menu content w. printing functions
        ∟    statistics.cpp     | min, max, mean, stddev (works on vector<Measurement>)
        ∟    alarmStorage.cpp   | AlarmStorage: adds and prints triggered alarms
        ∟    temperSensor.cpp   | derived sensor class: TemperatureSensor
        ∟    illumiSensor.cpp   | derived sensor class: IlluminanceSensor
        ∟    humidiSensor.cpp   | derived sensor class: HumiditySensor

**include/**
        ∟    measurement.h   | struct Measurement (sensorName, unit, value, timestamp)
        ∟    sensor.h        | ABSTRACT base class Sensor
                             |    ∟    virtual destructor ~Sensor() 
                             |    ∟    pure virtual getName(), getUnit(), getMin-/Max() 
                             |    ∟    read(storage, alarmStorage)
                             |    ∟    threshold interface (set/get)
        ∟    storage.h       | *class MeasurementStorage* (vector, saveToFile, loadToFile)
        ∟    utils.h         | Input, menu functions (and the cool stuff)
        ∟    statistics.h    | getMin-/Max, getMean, getStdDev. Works on any vector<Measurement>
        ∟    alarm.h         | struct Alarm
        ∟    alarmStorage.h  | *class AlarmStorage* (addAlarm)
        ∟    temperSensor.h  | Derived TemperatureSensor class
        ∟    illumiSensor.h  | Derived IlluminanceSensor class
        ∟    humidiSensor.h  | Derived HumiditySensor class


### measurement.h
**A struct** (like a skeleton) that consists of:
    -    sensorName
    -    unit
    -    value
    -    timestamp

#### MeasurementStorage
-	Stores all Measurement objects
-	Filters by sensor
-	saveToFile() and loadFromFile() for .csv file handling
-	Has helper methods such as getSensorCounts() (which provides a breakdown of each sensor saved and/or loaded)

#### namespace statistics
**Calculates:**
-	getMin
-	getMax
-	getMean
-	getStdDev

#### Sensor (abstract base class)
**Declares:**
-	getName(), getUnit()
-	getMin() / getMax()
-	read(storage, alarmStorage)
-	threshold interface
-	**Derived classes implement**
    -	TemperatureSensor
    -	IlluminanceSensor
    -	HumiditySensor

#### Alarm- & AlarmStorage
-    Alarm triggered when a measurement value is larger than the threshold range
-    AlarmStorage stores and prints all alarms

#### utils
-	integer input (safe)
-	Menus for 
    -   Main menu
    -   Sensor meun
    -   Statistics menu
    -   Threshold menu
-	Clear screen    (like 'clear' in the terminal) 
-   Colored text displaying amount of each sensor type loaded or saved.
