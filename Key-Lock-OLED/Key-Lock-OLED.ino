#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definerer keypad pins
const int row2 = 2;
const int row3 = 3;
const int col3 = 4;
const int row4 = 5;
const int col1 = 6;
const int row1 = 7;
const int col2 = 8;

// Definerer andre pins
const int btnPin = 12;
const int piezo = 13;
const int greLed = 11;
const int redLed = 10;

// Definerer variabler til keypad
const byte ROWS = 4;
const byte COLS = 3;
const int passLen = 4;

char crntCode[passLen] = {'0', '0', '0', '0'};
char attempt[passLen];
int attemptKeysPressed = 0;
int setKeysPressed = 0;

char numKeys[ROWS][COLS] = { // Definerer taster og dems plasseringer
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Definerer variabler til OLED
const int SCREEN_WIDTH = 128; // Skjermbredde i piksler
const int SCREEN_HEIGHT = 64; // Skjermhøyde i piksler
const int SCREEN_ADDRESS = 0x3C; // Setter addressen OLED bruker for I2C kommunikasjon

// Definerer hvem arduino pins som hører til hvem keypad pins
byte rowPins[ROWS] = {row1, row2, row3, row4};
byte colPins[COLS] = {col1, col2, col3};

// Initialiserer keypad & OLED
Keypad keypad = Keypad( makeKeymap(numKeys), rowPins, colPins, ROWS, COLS);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

// Definerer andre variabler
int i = 0; // For bruk i for-loops
int attemptFail = 0; // 0 betyr at forsøk ikke er feil, 1 betyr feil

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); // Starter OLED med parametere for å bruke OLED sin interne krets som strømkilde og I2C kommunikasjonsaddresse

  // Sette pinMode
  pinMode(btnPin, INPUT);
  pinMode(greLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  display.clearDisplay();

  char key = keypad.getKey();
  if (key) {
    tone(piezo, 750);
    delay(10);
    noTone(piezo);

    attempt[attemptKeysPressed] = key;

    attemptKeysPressed++;
  }
  display.setCursor(0, 16);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  for (i = 0; i<attemptKeysPressed; i++) {
    display.print(attempt[i]);
  }
  display.display();

  if (attemptKeysPressed == passLen) {
    for (i = 0; i<attemptKeysPressed; i++) {
      if (attempt[i] != crntCode[i]) {
        attemptFail = 1;
        Serial.print(attempt[i]);
        Serial.print(" - ");
        Serial.println(crntCode[i]);
        Serial.println("Failed");
      }
    }
    if (attemptFail == 0) {
      digitalWrite(greLed, HIGH);
    }
    else {
      digitalWrite(redLed, HIGH);
      tone(piezo, 1500);
      delay(20);
      tone(piezo, 2400);
      delay(20);
      tone(piezo, 1500);
      delay(20);
      tone(piezo, 2400);
      delay(20);
      tone(piezo, 1500);
      delay(20);
      tone(piezo, 2400);
      delay(20);
      tone(piezo, 1500);
      delay(20);
      tone(piezo, 2400);
      delay(20);
      tone(piezo, 1500);
      delay(20);
      tone(piezo, 2400);
      delay(20);
      tone(piezo, 1500);
      delay(20);
      tone(piezo, 2400);
      delay(20);
      tone(piezo, 1500);
      delay(20);
      tone(piezo, 2400);
      delay(20);
      tone(piezo, 1500);
      delay(20);
      tone(piezo, 2400);
      delay(20);
      tone(piezo, 1500);
      delay(20);
      tone(piezo, 2400);
      delay(20);
      noTone(piezo);
    }
    attemptFail = 0;
    attemptKeysPressed = 0;

    delay(500);
    digitalWrite(greLed, LOW);
    digitalWrite(redLed, LOW);
  }

  int btnPressed = digitalRead(btnPin);
  Serial.println(btnPressed);
  if (btnPressed == HIGH) {
    bool run = 0;
    while (run == 0) {
      display.clearDisplay();

      char key = keypad.getKey();
      if (key) {
        crntCode[setKeysPressed] = key;

        setKeysPressed++;

        display.setCursor(0, 16);
        display.setTextSize(3);
        display.setTextColor(WHITE);
        for (i = 0; i<setKeysPressed; i++) {
          display.print(crntCode[i]);
        }
        display.display();
      }
      if (setKeysPressed == passLen) run = 1;
    }
    setKeysPressed = 0;
  }
}