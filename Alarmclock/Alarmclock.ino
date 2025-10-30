#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD pins: RS, EN, D4, D5, D6, D7

const int buzzerPin = 8; // Digital pin for the piezo buzzer
const int button1Pin = 9; // Digital pin for Button 1
const int button2Pin = 10; // Digital pin for Button 2
const int button3Pin = 7; // Digital pin for Button 3

enum Mode { SET_CLOCK, SET_ALARM, ALARM_ON }; // Modes for setting clock, setting alarm, and alarm on
Mode mode = SET_CLOCK; // Initial mode is setting clock

int hourToSet = 0; // Hour to set in clock setting mode
int minuteToSet = 0; // Minute to set in clock setting mode
int alarmHour = 0; // Alarm hour
int alarmMinute = 0; // Alarm minute
bool alarmEnabled = false; // Alarm enabled flag
bool alarmRinging = false; // Alarm ringing flag

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

bool button1Pressed = false;
bool button2Pressed = false;
bool button3Pressed = false;

unsigned long previousMillis = 0; // Variable to store the previous time in milliseconds
const long interval = 60000; // Interval for updating the clock (1 minute)

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);

  lcd.begin(16, 2); // Initialize the LCD
  lcd.print("Alarm Clock");
  lcd.setCursor(0, 1);
  lcd.print("00:00 Alarm OFF");
}

void loop() {
  unsigned long currentMillis = millis(); // Get the current time in milliseconds

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Update previousMillis

    // Increment the time by 1 minute
    minuteToSet++;
    if (minuteToSet == 60) {
      minuteToSet = 0;
      hourToSet++;
      if (hourToSet == 24) {
        hourToSet = 0;
      }
    }

    // Update the display if the mode is SET_CLOCK
    if (mode == SET_CLOCK) {
      updateDisplay();
    }
  }

  // Button handling
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  int button3State = digitalRead(button3Pin);

  // Button 1 handling
  if (button1State == LOW) {
    if (!button1Pressed) {
      button1Pressed = true;
      delay(50); // Debounce
      if (button1State == LOW) {
        if (mode == SET_CLOCK) {
          hourToSet = (hourToSet + 1) % 24;
        } else if (mode == SET_ALARM) {
          alarmHour = (alarmHour + 1) % 24;
        }
        updateDisplay();
      }
    }
  } else {
    button1Pressed = false;
  }

  // Button 2 handling
  if (button2State == LOW) {
    if (!button2Pressed) {
      button2Pressed = true;
      delay(50); // Debounce
      if (button2State == LOW) {
        if (mode == SET_CLOCK) {
          minuteToSet = (minuteToSet + 1) % 60;
        } else if (mode == SET_ALARM) {
          alarmMinute = (alarmMinute + 1) % 60;
        }
        updateDisplay();
      }
    }
  } else {
    button2Pressed = false;
  }

  // Button 3 handling
  if (button3State == LOW) {
    if (!button3Pressed) {
      button3Pressed = true;
      delay(50); // Debounce
      if (button3State == LOW) {
        if (mode == SET_CLOCK) {
          mode = SET_ALARM; // Change mode to setting alarm
        } else if (mode == SET_ALARM) {
          mode = ALARM_ON; // Change mode to alarm on
          alarmEnabled = true; // Enable alarm
        } else if (mode == ALARM_ON) {
          mode = SET_CLOCK; // Change mode back to setting clock
          alarmEnabled = false; // Disable alarm
        }
        updateDisplay();
      }
    }
  } else {
    button3Pressed = false;
  }

  // Check if it's time for the alarm
  if (alarmEnabled && !alarmRinging && (hourToSet == alarmHour) && (minuteToSet == alarmMinute)) {
    activateAlarm();
  }
}

void updateDisplay() {
  lcd.setCursor(0, 1);
  if (mode == SET_CLOCK) {
    lcd.print((hourToSet < 10 ? "0" : ""));
    lcd.print(hourToSet);
    lcd.print(":");
    lcd.print((minuteToSet < 10 ? "0" : ""));
    lcd.print(minuteToSet);
    lcd.print(" Set Clock ");
  } else if (mode == SET_ALARM) {
    lcd.print((alarmHour < 10 ? "0" : ""));
    lcd.print(alarmHour);
    lcd.print(":");
    lcd.print((alarmMinute < 10 ? "0" : ""));
    lcd.print(alarmMinute);
    lcd.print(" Set Alarm ");
  } else if (mode == ALARM_ON) {
    lcd.print((alarmHour < 10 ? "0" : ""));
    lcd.print(alarmHour);
    lcd.print(":");
    lcd.print((alarmMinute < 10 ? "0" : ""));
    lcd.print(alarmMinute);
    lcd.print(" Alarm ON ");
  }
}

void activateAlarm() {
  alarmRinging = true;
  lcd.setCursor(0, 1);
  lcd.print("Alarm ringing!   ");

  // Pip lyd
  for (int i = 0; i < 100; i++) { // Fire pips
    tone(buzzerPin, 1000); // Pip frekvens
    delay(200); // Pip varighet
    noTone(buzzerPin); // Slå av lyden
    delay(200); // Pausen mellom pips
  }
}


void stopAlarm() {
  alarmRinging = false;
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear the alarm message
  noTone(buzzerPin); // Turn off the buzzer
}