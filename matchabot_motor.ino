/* Example sketch to control a stepper motor with 
   A4988/DRV8825 stepper motor driver and 
   Arduino without a library. 
   More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
#define dirPin 5
#define stepPin 2
#define stepsPerQuarterRevolution 100

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerQuarterRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(8000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(8000);
  }
  delay(8000);
}