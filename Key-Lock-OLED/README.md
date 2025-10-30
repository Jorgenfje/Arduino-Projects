### 🔐 Key-Lock-OLED
Developed by Jørgen A. Fjellstad - May 2024

An Arduino-based digital keypad lock with OLED display, LED indicators, and buzzer alerts.  
Users can enter a 4-digit code, verify access, and update the PIN using a button.  
Built with Adafruit SSD1306 OLED and Keypad libraries for a compact, interactive security demo.

_______________________________________________________________________________________________

### ⚙️ Components
-  **Arduino Uno** (or compatible)
-  **4x3 Keypad**
-  **Adafruit SSD1306 OLED display (I2C)**
-  **Piezo buzzer**
-  **Green LED** – success indicator  
-  **Red LED** – access denied  
-  **Push button** – enter PIN setup mode  
-  **Resistors & jumper wires**

_______________________________________________________________________________________________

### 📚 Required Libraries
Install via **Arduino IDE → Sketch → Include Library → Manage Libraries**:
- `Keypad` by Mark Stanley & Alexander Brevig  
- `Adafruit GFX` by Adafruit  
- `Adafruit SSD1306` by Adafruit  
- `Wire` (built-in)

_______________________________________________________________________________________________

### 🧩 How It Works
1. Enter a **4-digit PIN** on the keypad.  
2. Each key appears on the **OLED display**.  
3.  If the PIN matches:  
   - Green LED lights up  
4.  If incorrect:  
   - Red LED blinks and buzzer sounds  
5.  Press the **button** to enter setup mode and define a new PIN.  

_______________________________________________________________________________________________

### 🪛 Pin Configuration
| Component | Pin(s) |
|------------|--------|
| Keypad Rows | 2, 3, 5, 7 |
| Keypad Columns | 4, 6, 8 |
| Green LED | 11 |
| Red LED | 10 |
| Buzzer | 13 |
| Button | 12 |
| OLED (SDA/SCL) | A4 / A5 (I2C default) |

_______________________________________________________________________________________________

### 🚀 Getting Started
1. Connect components as shown above.  
2. Open project in **Arduino IDE**.  
3. Upload `Key-Lock-OLED.ino` to your board.  
4. Open **Serial Monitor** (9600 baud) for debugging.  
5. Interact with the keypad and OLED to test lock functionality.

_______________________________________________________________________________________________

### 🧠 Notes
- Default PIN: `0000`  
- The buzzer provides tone feedback for each keypress.  
- Red LED + alarm sequence = incorrect attempt.  
- Long-press button → set new PIN mode.


