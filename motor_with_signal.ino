#include <Wire.h> 
// Define stepper motor connections and steps per revolution:
#define dirPin 5
#define stepPin 2
#define stepsPerQuarterRevolution 50

int x = 0;

void setup() {
  Wire.begin(); 
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT); 
}

void loop() {
  //send start signal 
  x = 1; 
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting 

   // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerQuarterRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(15000);
  }
  
  delay(500);
  digitalWrite(dirPin, LOW); //move whisk down

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerQuarterRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(15000);
  }

  delay(5000); 

}
