/* Example sketch to control a stepper motor with 
   A4988/DRV8825 stepper motor driver and 
   Arduino without a library. 
   More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
#define WdirPin 5
#define WstepPin 2
#define WstepsPerQuarterRevolution 70

void setup() {
  // Declare pins as output:
  pinMode(WstepPin, OUTPUT);
  pinMode(WdirPin, OUTPUT);
}

void loop() {
  // Set the spinning direction clockwise:
  digitalWrite(WdirPin, LOW);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < WstepsPerQuarterRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(WstepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(WstepPin, LOW);
    delayMicroseconds(15000);
  }

  delay(500);
  digitalWrite(WdirPin, HIGH);
  delay(500);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < WstepsPerQuarterRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(WstepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(WstepPin, LOW);
    delayMicroseconds(15000);
  }
  delay(5000);
}