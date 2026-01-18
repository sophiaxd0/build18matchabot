//for matcha dispenser 
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(110);
  delay(2000);
}

void loop() {
  //myservo.write(0); 
  for(pos = 110; pos>35; pos--){
    myservo.write(pos);
    delay(10); 
  }
  delay(15000);
  for(pos = 35; pos<110; pos++){
    myservo.write(pos);
    delay(10); 
  }
  delay(2000); 
}
