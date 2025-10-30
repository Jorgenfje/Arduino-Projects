/*
*
* Lesing av 12 knappers keypad
* ved bruk av 3 analoge innganger
*
*/
// Grenseverdier
const int NADCm100[4] = {898,644,387,113};
const int NADCp100[4] = {1123,894,637,363}; //{1123,869,612,338}

// Knapper fra øvre venstre hjørne og nedover
const char key[12] = {'1','4','7','*','2','5','8','0','3','6','9','#'};

// Innleste verdier fra de tre analoge inngangene
int keyval[3];
int i,colp,val;


void setup(){
  Serial.begin(9600); // used with serial monitor
}

void loop() {
  char k;
  k = KeyPad(); // les keypad
  if (k != 'N'){ // en knapp var trykket
    Serial.print("Knapp = ");
    Serial.println(k);
    delay(500);
  }
}

/******** Funksjoner brukt i programmet ********/
char KeyPad(){

// Les knappepanelet og returner verdien
// Returner 'N' hvis ikke noe er trykket
  KeyScan(); // Les knappepanelet
  if (keyval[0]+keyval[1]+keyval[2] < 40) {
    return 'N';
  }
  else { // en knapp var trykket
    delay(100); // antibounce
    KeyScan(); // Les igjen
    for (i=0; i < 3; i++){ //finn riktig kolonne
      if (keyval[i] > 40){
        colp = i;
        val = keyval[i]; // Dette er verdien
        for (int j=0; j < 4; j++){ // Finn riktig rad
          if (val >= NADCm100[j] && keyval <= NADCp100[j]){
            return key[colp*4+j]; // Returner trykket knapp
            break;
          }
        }
      }
    }
  }
}

void KeyScan(){// Les de tre analoge inngangene
  keyval[0] = analogRead(A0);
  delay(1);
  keyval[1] = analogRead(A1);
  delay(1);
  keyval[2] = analogRead(A2);
  delay(1);
}
