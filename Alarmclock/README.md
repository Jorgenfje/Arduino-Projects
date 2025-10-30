### Digital Alarm Clock ⏰  
Developed by Jørgen A. Fjellstad - April 2024

_______________________________________________________________________________________________________________________________________________

### 🔧 Overview
This project demonstrates a **digital alarm clock** built with Arduino, featuring an LCD display, piezo buzzer, and three-button control system.  
It allows setting the current time and alarm, switching between modes, and includes sound feedback when the alarm is triggered.

_______________________________________________________________________________________________________________________________________________

### 🧠 Features
- **Three-button interface** for setting hour, minute, and switching modes  
- **16x2 LCD display** showing current time and alarm status  
- **Piezo buzzer alarm** with short beeps when activated  
- **Button debounce** for reliable user input  
- **Clean structure and readable code** with comments

_______________________________________________________________________________________________________________________________________________

### 💻 Components
- Arduino Uno (or compatible board)  
- 16x2 LCD display  
- 3 push buttons  
- 1 piezo buzzer  
- Resistors (for button pull-downs if not using internal pull-ups)  
- Jumper wires and breadboard  

_______________________________________________________________________________________________________________________________________________

### ⚙️ How to Run
1. Open the file `alarm_clock.ino` in **Arduino IDE**.  
2. Connect components according to pin assignments in the code:  
   - LCD: pins 12, 11, 5, 4, 3, 2  
   - Buzzer: pin 8  
   - Buttons: pins 7, 9, 10  
3. Upload the sketch to your Arduino board.  
4. Use the buttons to:  
   - Increase **hour** and **minute** values  
   - Switch between **clock**, **alarm**, and **alarm on/off** modes  

_______________________________________________________________________________________________________________________________________________

### 🧩 Behavior
- In `SET_CLOCK` mode, adjust the time.  
- In `SET_ALARM` mode, set the alarm.  
- In `ALARM_ON` mode, the alarm activates when current time matches alarm time.  
- The buzzer will beep four short tones when triggered.
