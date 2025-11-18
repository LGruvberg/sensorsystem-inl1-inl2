# IoT25_LovGru-oop-assignment1

#### How to compile and run
```bash
# Compile in terminal:
g++ src/main.cpp src/utils.cpp src/sensor.cpp src/analytics.cpp src/storage.cpp src/measurement.cpp -o SensorSystem
# if 'g++ src/*.cpp -o SensorSystem' doesn't work for you:

# then run: 
.\SensorSystem.exe
```

## main.cpp
-	Shows the main menu
-	Handles user input
-	Creates sensors
-	Calls storage functions
-	Runs the app loop
-	Delegates actual work to other classes
##### Think of it as the user interface logic.

## sensor.cpp / .hpp 
Each sensor has:
-	name
-	unit
-	ID
-	min/max value range
The 'read()':
-	Generates a random value between min/max
-	Creates a Measurement
-	Stores it in MeasurementStorage
-	Prints the colored reading (based on value extremeties)
-	Returns the numeric value
##### Sensors are the data producers.

## measurement.cpp / .cpp 
Represents one reading:
-   value
-   sensor name
-   unit
-   timestamp

## storage.cpp / .hpp
-   addMeasurement() — store new reading
-   printAll() — print all stored readings
-   getMeasurementsBySensor() — filter by sensor
-   printSensorAnalytics() — min/max/mean/stdev
##### Acts like a database.

## statistics.cpp / .hpp 
Math helpers for storage:
-   Minimum value
-   Maximum value
-   Average
-   Standard deviation
