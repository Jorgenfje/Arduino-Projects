### 🔢 Analog Keypad Reader (3-Input)
Developed by Jørgen A. Fjellstad - 2025

______________________________________________________________________________________________________________________

A simple Arduino project that reads a **12-button keypad** using only **three analog inputs** instead of digital pins.  
Each key is uniquely identified by voltage ranges (analog thresholds) and displayed in the **Serial Monitor**.  

______________________________________________________________________________________________________________________

## ⚙️ Components
-  **Arduino Uno** (or similar board)  
-  **3×4 membrane keypad**  
-  **Voltage divider resistors** (to encode key values)  
-  **Jumper wires**

______________________________________________________________________________________________________________________

## 📚 Features
- Reads a **12-button keypad** using analog voltage levels.  
- Reduces I/O usage to only **three analog pins**.  
- Displays pressed key in Serial Monitor.  
- Includes **debounce delay** for stable readings.  

______________________________________________________________________________________________________________________

## 🪛 Pin Configuration
| Component | Pin(s) |
|------------|--------|
| Keypad Column 1 | A0 |
| Keypad Column 2 | A1 |
| Keypad Column 3 | A2 |

______________________________________________________________________________________________________________________

## 🚀 How It Works
Each button in the keypad is part of a voltage divider network.  
When a key is pressed, a specific voltage level is detected on one of the analog inputs.  
The program compares this reading against defined threshold ranges to determine which button was pressed.

______________________________________________________________________________________________________________________

## 🧠 Usage
1. Connect keypad outputs to **A0–A2** as per your wiring diagram.  
2. Upload the `.ino` sketch using **Arduino IDE**.  
3. Open the **Serial Monitor** at `9600 baud`.  
4. Press any key and observe output, e.g.:  
   ```
   Knapp = 7
   Knapp = *
   ```

______________________________________________________________________________________________________________________

## ⚡ Notes
- Debounce delay: `100 ms`  
- Threshold values (`NADCm100` / `NADCp100`) can be fine-tuned if your keypad produces different readings.  
- Returns `'N'` when no button is pressed.

