//for matcha dispenser 
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  //myservo.write(0); 
  for(pos = 0; pos<90; pos+=5){
    myservo.write(pos);
    delay(100); 
  }
  delay(2000); 
  for(pos = 90; pos>0; pos--){
    myservo.write(pos);
    delay(5); 
  }
  delay(5000); 
  
}
