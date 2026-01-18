#include <Wire.h>
#include <Servo.h>

Servo whisk_servo;  // create servo object to control a servo 
Servo dispense_servo; 
int x = 0;

int whisk_pos = 0;    // variable to store the servo position
int whisk_hold = 90; 


void setup() { 
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600); 
  whisk_servo.attach(9); 
  dispense_servo.attach(3); 
  while (!x); //wait for x to be 1 
}

void loop() { 
  //matcha powder
  for(int pos = 180; pos>150; pos-=5){
    dispense_servo.write(pos);
    delay(100); 
  }
  delay(200); 
  for(int pos = 150; pos<180; pos++){
    dispense_servo.write(pos);
    delay(5); 
  } 
  delay(5000); 


  //water
  delay(5000);



  //whisk 
  for(int i = 0; i<100; i++){ //whisk 100 times? 
    for (whisk_pos = 0; whisk_pos <= hold; whisk_pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      whisk_servo.write(whisk_pos);              // tell servo to go to position in variable 'pos'
      delay(2);                       // waits 15 ms for the servo to reach the position
    } 
    delay(200);
    for (whisk_pos = hold; whisk_pos >= 0; whisk_pos -= 1) { // goes from 180 degrees to 0 degrees
      whisk_servo.write(whisk_pos);              // tell servo to go to position in variable 'pos'
      delay(2);                       // waits 15 ms for the servo to reach the position
    } 
    delay(200); 
  } 
  delay(5000); 



  //milk 
  delay(5000);  



}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
