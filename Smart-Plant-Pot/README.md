### Smart Plant Pot 🌱 

**Arduino Code Example for an Automated Watering System**  
Developed by Jørgen A. Fjellstad - May 2024  

___________________________________________________________________________________________________________________________________________

### 🔧 Overview

This repository contains the **source code** for an exam project where the task was to design an automated plant watering system.  
The physical prototype is **not included**, but the code demonstrates how multiple sensors can be integrated and controlled via Arduino.

___________________________________________________________________________________________________________________________________________

### 🧠 Functionality

- Reads simulated data from:
  - **ENS160** air quality sensor (CO₂, TVOC, AQI)
  - **Soil moisture sensor**
  - **Light sensor (photoresistor)**
  - **Temperature sensor**
- Uses conditional logic to control a **water pump** through a transistor.  
- Outputs all readings to the Serial Monitor for testing.

___________________________________________________________________________________________________________________________________________

### 💻 Code Purpose

The code focuses on:
- **Sensor data acquisition** via analog and I²C interfaces.  
- **Decision logic** for triggering a water pump under given conditions.  
- **Clean structure and clear serial output** for debugging.

This project is **educational** and demonstrates understanding of embedded systems and sensor integration rather than a finished IoT build.

___________________________________________________________________________________________________________________________________________

### ⚙️ How to Test

1. Open the file `smart_plant_pot.ino` in **Arduino IDE**.  
2. Install the required libraries:
   - `SparkFun_ENS160`
   - `Wire`
3. Connect any available analog sensors (optional), or run with simulated values.  
4. Upload the sketch to an Arduino board.  
5. Open Serial Monitor at **115200 baud** to view readings.

___________________________________________________________________________________________________________________________________________

### 🧩 Notes

- Designed for **Arduino UNO**.  
- Prototype hardware not included in this repository.
  

