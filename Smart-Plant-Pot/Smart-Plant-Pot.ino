// Eksamen i Datateknikk
// Smart plantepotte - av Jørgen A. Fjellstad 02.05.2024


// # INCLUDE
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <SparkFun_ENS160.h>               // Inkluderer ENS160 library
#include <Wire.h>                          // Inkluderer Wire library for kommunikasjon med I2C enheter
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



SparkFun_ENS160 myENS;                     // Initialiserer luftkvalitetssensoren



// VARIABLER
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int fuktighet;	                           // Variabel til lagring av fuktighetsnivå
int lys;                                   // Variabel til lagring av lysnivå
int fart;                                  // Variabel til lagring av pumpefart
double temp;                               // Variabel til lagring av temperatur

const int pumpe = 8;                       // Vannpumpen har inngang 8 via en transistor, jeg bruker transistor for å kunne kontrollere strømmen til pumpa                                        
const int lysPin = A0;                     // Fototransistoren som fungerer som lyssensor har inngang A0
const int soilPin = A1;                    // Fuktmåleren har inngang A1
const int tmpPin = A2;                     // Temperatursensoren har inngang A2
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/




// SETUP
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void setup() {
  
  Serial.begin(115200);                    // Starter seriell kommunikasjon på 115200 for høyere hastighet
  Wire.begin();                            // Starter Wire for kommunikasjon med I2C enheter

  if( !myENS.begin() )                     // Sjekker om vi IKKE får kontakt med ENS160 sensoren, i så fall skriver ut feilmelding
  {
		Serial.println("Fikk ikke kontakt med ENS160.");
		while(1);
	}
  
  myENS.setOperatingMode(SFE_ENS160_STANDARD);  // Setter ENS160 til standard modus

  pinMode(soilPin, INPUT);                 // Fukt, lys og temp er alle input
  pinMode(lysPin, INPUT);
  pinMode(tmpPin, INPUT);
  
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/




// HOVEDLOOP
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void loop() {
  
  // ENS160 luftkvalitetssensor
  /*----------------------------------------------*/
  if(myENS.checkDataStatus()) {                     // Sjekker statusen på ENS160 (egne funksjoner) og skriver ut lutftkvalitet
    Serial.print("Luftkvalitetsindeks (1-5): ");
    Serial.println(myENS.getAQI());

    Serial.print("TVOC: ");                         // Skriver ut TVOC
    Serial.print(myENS.getTVOC());
    Serial.println(" ppb (parts per billion)");

    Serial.print("CO2 nivå: ");                     // Skriver ut CO2
    Serial.print(myENS.getECO2());
		Serial.println(" ppm (parts per million)");
  }
  /*-----------------------------------------------*/


  // Fuktighetsnivå
  /*-----------------------------------------------*/
  fuktighet = analogRead(soilPin);	                // Leser av fuktighetsnivå og lagrer det i variabelen fuktighet
  Serial.print("Fuktighetsnivå: ");                 // Skriver ut fuktighet til serial monitor
  Serial.println(fuktighet);	
  /*-----------------------------------------------*/


  // Temperatur
  /*-----------------------------------------------*/
  temp = analogRead(tmpPin);                        // Leser av fuktighetsnivå og lagrer det i variabelen temp
  float voltageOut = temp * (5.0 / 1024.0);           // Konverterer temp til volt for å få ut Celsius
  temp = (voltageOut - 0.5) * 100;                  // Skriver ut det vi får av temperatur i grader Celsius
  Serial.print("Temperatur: ");
  Serial.print(temp);
  Serial.println(" Grader Celsius"); 
  /*-----------------------------------------------*/
  

  // Lysnivå
  /*-----------------------------------------------*/
  lys = analogRead(lysPin);                         // Leser av lysnivå og lagrer det i variabelen lys
  Serial.print("Lysverdi: ");                       // Skriver ut lysverdien
  Serial.println(lys);
  /*-----------------------------------------------*/

  
  // Vannpumpe
  /*-----------------------------------------------*/
  analogWrite(pumpe,fart);                          // Bruker funksjonen analogWrite for å skrive ut verdi i fart til pinnen pumpe
  Serial.print("Pumpefart: ");                      
  Serial.println(fart);
  Serial.println();
  /*-----------------------------------------------*/
  
  
  // If-setninger 
  /*-----------------------------------------------*/
  if (fuktighet < 100) {                            // Hvis fuktighetsnivå er under 100 setter vi pumpen til maks fart
    fart = 255;                                     // Setter farten her, som brukes under
    analogWrite(pumpe, fart);                       
  } 
 
  else {                                            // Ellers skal pumpa være av
    fart = 0;
    analogWrite(pumpe, fart);
  }
  
  if (temp > 27 && fuktighet < 100) {               // Pumpa starter også hvis temp er over 27 grader OG fuktigheten er under 100
    fart = 255;
    analogWrite(pumpe, fart);
  } 
  /*-----------------------------------------------*/


  delay(2000); // Forsinkelse på 2 sekunder for lettere lesbarhet

}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// SLUTT