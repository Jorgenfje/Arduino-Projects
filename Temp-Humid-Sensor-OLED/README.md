### 🌡️ DHT11 Temperature & Humidity Display (OLED)
Developed by Jørgen A. Fjellstad - April 2024

_______________________________________________________________________________________________________________________________________

An Arduino project that reads **temperature** and **humidity** from a DHT11 sensor and displays the values on a **128×64 OLED screen**.  
Ideal for basic IoT or environmental monitoring setups.

_______________________________________________________________________________________________________________________________________

### ⚙️ Components
-  **Arduino Uno** (or compatible board)  
-  **DHT11 Sensor** (for temperature & humidity)  
-  **SSD1306 OLED Display** (I2C, 128×64 pixels)  
-  **Jumper wires**

_______________________________________________________________________________________________________________________________________

### 📚 Features
- Reads real-time **temperature** and **humidity**.  
- Displays live readings on **OLED** and **Serial Monitor**.  
- Refreshes every **2 seconds**.  
- Built using `Adafruit_GFX` and `Adafruit_SSD1306` libraries.

_______________________________________________________________________________________________________________________________________

### 🪛 Pin Configuration
| Component | Pin(s) |
|------------|--------|
| DHT11 Signal | 7 |
| OLED SDA/SCL | A4 / A5 |
| Serial Output | 9600 baud |

_______________________________________________________________________________________________________________________________________

### 🚀 How It Works
1. The **DHT11 sensor** measures humidity and temperature.  
2. Values are printed to the **Serial Monitor** and rendered on the **OLED display**.  
3. The screen updates every 2 seconds with new data:
   ```
   Temp(C): 22
   Humidity(%): 41
   ```

_______________________________________________________________________________________________________________________________________

### 🧠 Usage
1. Connect DHT11 and OLED display according to pin mapping above.  
2. Install libraries:
   - `dht.h`
   - `Adafruit_GFX.h`
   - `Adafruit_SSD1306.h`
3. Upload the `.ino` sketch using Arduino IDE.  
4. Open **Serial Monitor** at `9600 baud` to verify readings.

_______________________________________________________________________________________________________________________________________

### ⚡ Notes
- Modify line `DHT.read11(dht_apin)` if using **DHT22** (use `read22()` instead).  
- OLED address defaults to `0x3C`; change if using another module.  
- Ensure `SSD1306_SWITCHCAPVCC` power mode matches your display wiring.  
- Delay between updates can be adjusted in `delay(2000)`.

