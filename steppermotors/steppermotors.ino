/* Example sketch to control a stepper motor with 
   A4988/DRV8825 stepper motor driver and 
   Arduino without a library. 
   More info: https://www.makerguides.com */

// Define lazy susan stepper motor connections and steps per revolution:
#define LSdirPin 6
#define LSstepPin 3
#define LSstepsPerQuarterRevolution 50
// Define whisk stepper motor connections and steps per revolution:
#define WdirPin 5
#define WstepPin 2
#define WstepsdownPerQuarterRevolution 70
#define WstepsupPerQuarterRevolution 75

void setup() {
  // Declare pins as output:
  pinMode(LSstepPin, OUTPUT);
  pinMode(LSdirPin, OUTPUT);
  pinMode(WstepPin, OUTPUT);
  pinMode(WdirPin, OUTPUT);

    // Set the spinning direction clockwise:
  digitalWrite(LSdirPin, LOW);

  delay(1250); //matcha dispensing step
  // move from matcha dispensing to water dispensing
  for (int i = 0; i < LSstepsPerQuarterRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(LSstepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(LSstepPin, LOW);
    delayMicroseconds(15000);
  }

  delay(5000); //water dispensing time
  // move from water dispensing to whisking
  for (int i = 0; i < LSstepsPerQuarterRevolution; i++) {
    digitalWrite(LSstepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(LSstepPin, LOW);
    delayMicroseconds(15000);
  }

  //WHISKING CODE START
  digitalWrite(WdirPin, LOW);

  //move whisk down
  for (int i = 0; i < WstepsdownPerQuarterRevolution; i++) {
    digitalWrite(WstepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(WstepPin, LOW);
    delayMicroseconds(15000);
  }

  digitalWrite(WdirPin, HIGH);
  delay(15000); //whisking time

  //move whisk back up
  for (int i = 0; i < WstepsupPerQuarterRevolution; i++) {
    
    digitalWrite(WstepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(WstepPin, LOW);
    delayMicroseconds(15000);
  }
  delay(500);
  //WHISKING CODE END

  //move from whisking to milk
  for (int i = 0; i < LSstepsPerQuarterRevolution; i++) {
    
    digitalWrite(LSstepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(LSstepPin, LOW);
    delayMicroseconds(15000);
  }
  delay(15000); //milk dispensing time

  //move back to the beginning
  for (int i = 0; i < LSstepsPerQuarterRevolution; i++) {
    
    digitalWrite(LSstepPin, HIGH);
    delayMicroseconds(15000);
    digitalWrite(LSstepPin, LOW);
    delayMicroseconds(15000);
  }
  delay(500); //milk dispensing time
}

void loop() {
}