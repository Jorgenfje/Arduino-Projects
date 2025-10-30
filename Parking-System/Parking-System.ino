const int trig = 12;
const int echo = 13;

const int redPin = 3;
const int greenPin = 2;
const int bluePin = 1;

const int LED1 = 11;
const int LED2 = 10;
const int LED3 = 9;
const int LED4 = 8;
const int LED5 = 7;
const int LED6 = 6;
const int LED7 = 5;
const int LED8 = 4;

float duration;
float distance;
bool withinRange = false;
unsigned long withinRangeTimer = 0;
const int rangeThreshold = 90;
const unsigned long offDelay = 5000;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(LED6 , OUTPUT);
  pinMode(LED7 , OUTPUT);
  pinMode(LED8 , OUTPUT);
  
  Serial.begin(9600);

}

 void setColor(int R, int G, int B) {
  analogWrite(redPin,   R);
  analogWrite(greenPin, G);
  analogWrite(bluePin,  B);
  }

void loop()
{
  digitalWrite(trig, LOW);      
  delayMicroseconds(2);         
  digitalWrite(trig, HIGH);     
  delayMicroseconds(10);                                   
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);    
  distance = (duration * 0.0343) / 2; 
                                                       
  Serial.print("Avstand: ");
  Serial.println(distance);
  delay(200);
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);
  
  
  if ( distance <= 5 ) {
    digitalWrite(LED5, HIGH);
    digitalWrite(LED4, HIGH);
  }
  else {
    digitalWrite(LED5, LOW);
    digitalWrite(LED4, LOW);
  }
  
  
  if ( distance <= 15 ) {
    digitalWrite(LED6, HIGH);
    digitalWrite(LED3, HIGH);
  }
  else {
    digitalWrite(LED6, LOW);
    digitalWrite(LED3, LOW);
  }
  
  
  if ( distance <= 30 ){
    digitalWrite(LED7, HIGH);
    digitalWrite(LED2, HIGH);
  }
  else {
    digitalWrite(LED7, LOW);
    digitalWrite(LED2, LOW);
  }
  
  
  if ( distance <= 40 ) {
    digitalWrite(LED8, HIGH);
    digitalWrite(LED1, HIGH);
  }
  else {
    digitalWrite(LED8, LOW);
    digitalWrite(LED1, LOW);
  }
  
  
  
  if (distance <=5) {
    setColor(255, 0, 0);
  } 
  else if (distance >= 40) {
    setColor(0, 255, 0);
  } 
  
}