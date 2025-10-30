### 🚗 Parking Distance Indicator System
Developed by Jørgen A. Fjellstad - April 2024

____________________________________________________________________________________________________________________________________________________

An Arduino-based parking assist system using an **ultrasonic sensor**, **RGB LED**, and **8 status LEDs** to visualize distance to nearby obstacles.  
Designed to simulate a real car parking sensor — showing distance with color and LED intensity.

____________________________________________________________________________________________________________________________________________________

### ⚙️ Components
-  **Arduino Uno** (or similar)  
-  **HC-SR04 Ultrasonic Sensor** (Trig + Echo)  
-  **RGB LED** for color distance indication  
-  **8 individual LEDs** for proximity levels  
-  **Resistors & jumper wires**

____________________________________________________________________________________________________________________________________________________

### 📚 Features
- Measures distance in real-time using **ultrasonic pulses**  
- Lights up LED segments depending on distance  
- RGB LED changes color:
  -  Red = very close  
  -  Green = safe distance  
- Displays readings in **Serial Monitor**

____________________________________________________________________________________________________________________________________________________

### 🪛 Pin Configuration
| Component | Pin(s) |
|------------|--------|
| Ultrasonic Trig | 12 |
| Ultrasonic Echo | 13 |
| RGB LED (R, G, B) | 3, 2, 1 |
| LEDs (1–8) | 11 → 4 |
| Serial Output | 9600 baud |

____________________________________________________________________________________________________________________________________________________

### 🚀 How It Works
1. The **ultrasonic sensor** emits a pulse and measures the echo time.  
2. Distance is calculated with:  
   ```
   distance = (duration * 0.0343) / 2;
   ```
3. Depending on distance:  
   - 40+ cm → Only green light  
   - 15–40 cm → Yellow LEDs illuminate progressively  
   - 5 cm or less → Red light and multiple LEDs activated  
4. Distance readings are continuously displayed in the Serial Monitor.

____________________________________________________________________________________________________________________________________________________

### 🧠 Usage
1. Wire components according to pin mapping above.  
2. Upload the `.ino` file via **Arduino IDE**.  
3. Open **Serial Monitor** (9600 baud).  
4. Move an object toward the sensor and observe LEDs and RGB light reacting in real-time.

____________________________________________________________________________________________________________________________________________________

### ⚡ Notes
- Adjustable thresholds:
  - `<= 40 cm` → first LED pair  
  - `<= 30 cm`, `<= 15 cm`, `<= 5 cm` → subsequent LED activations  
- To invert LED logic, swap `HIGH`/`LOW` states if needed.  
- Add resistors to protect LEDs and RGB module.

