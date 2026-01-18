/* Example sketch to control a stepper motor with 
   A4988/DRV8825 stepper motor driver and 
   Arduino without a library. 
   More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
#define LSdirPin 6
#define LSstepPin 3
#define LSstepsPerQuarterRevolution 50

void setup() {
  // Declare pins as output:
  pinMode(LSstepPin, OUTPUT);
  pinMode(LSdirPin, OUTPUT);
}

void loop() {
  // Set the spinning direction clockwise:
  digitalWrite(LSdirPin, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < LSstepsPerQuarterRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(LSstepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(LSstepPin, LOW);
    delayMicroseconds(15000);
  }
  delay(5000);
}