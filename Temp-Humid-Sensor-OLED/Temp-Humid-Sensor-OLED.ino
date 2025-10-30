// Et enkelt program som skriver ut temperatur og fuktighet til OLED skjermen

#include<dht.h>     // DHT sensor, må endres ut i fra hvilken sensor som brukes
#define dht_apin 7
dht DHT;


#include  <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define  SCREEN_WIDTH 128     // Definerer skjermstørrelsen i piksler
#define SCREEN_HEIGHT 64 

// Deklarerer at en SSD1306 OLED skjerm er koblet til I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH,  SCREEN_HEIGHT, &Wire, -1);


void setup(){
 
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT11 Humidity & temperature Sensor\\");
  delay(1000);
}
 
// Skriver ut verdier fra sensoren på skjermen med 2 sekunders pause
void loop(){
 
    DHT.read11(dht_apin);   // Leser av sensoren
    
    Serial.print("Current humidity = ");  // Skriver ut fuktighet og temperatur
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature);  
    Serial.println("C  ");
    
    delay(2000);
    Temp_and_Humidity();    // Kaller på funksjonen
}

// Funksjon for å initialisere OLED skjerm
void Temp_and_Humidity(){
  if (!oled.begin(SSD1306_SWITCHCAPVCC,  0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);        
  oled.clearDisplay();              // Clear skjermen
  oled.setTextSize(2);              // Tekststørrelse
  oled.setTextColor(WHITE);         // Tekstfarge
  oled.setCursor(0, 10);            // Setter posisjonen
  oled.print("Temp  & Humidity ");  // Skriver ut

  oled.clearDisplay(); 
  
  oled.setTextSize(1);          
  oled.setTextColor(WHITE);    
  oled.setCursor(0, 10); 
  oled.println("Temp(C)  : ");
  
  oled.setTextSize(2);          
  oled.setTextColor(WHITE);    
  oled.setCursor(50, 20); 
  oled.println(DHT.temperature);

  oled.setTextSize(1);          
  oled.setTextColor(WHITE);    
  oled.setCursor(0, 40);       
  oled.println("Humidity(%) : ");
  oled.setTextSize(2);          
  oled.setTextColor(WHITE);    
  oled.setCursor(50, 50); 
  oled.println(DHT.humidity);
  oled.setCursor(60,  90);
  oled.println("%");
  oled.display(); 
  
}






  