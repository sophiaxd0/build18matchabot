#include <Wire.h>
#include <Servo.h>

Servo whisk_servo;  // create servo object to control a servo 
Servo dispense_servo; 
Servo water_servo; 
Servo milk_servo; 
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
  water_servo.attach(11); 
  water_servo.write(110); 
  milk_servo.attach(10); 
  milk_servo.write(130); 


  
  while (!x); //wait for x to be 1 
  Serial.println("starting"); 



  //matcha powder
  Serial.println("matcha powder"); 
  for(int pos = 180; pos>130; pos-=5){
    dispense_servo.write(pos);
    delay(100); 
  }
  delay(200); 
  for(int pos = 130; pos<180; pos++){
    dispense_servo.write(pos);
    delay(5); 
  } 
  delay(5000); 


  //water
  Serial.println("water"); 
  for(int pos = 110; pos>35; pos--){
    water_servo.write(pos);
    delay(10); 
  }
  delay(15000);
  for(int pos = 35; pos<110; pos++){
    water_servo.write(pos);
    delay(10); 
  } 
  delay(5000);



  //up down motor not here
  delay(5000); 



  //whisk 
  Serial.println("whisk"); 
  for(int i = 0; i<20; i++){ //whisk 100 times? 
    for (whisk_pos = 0; whisk_pos <= whisk_hold; whisk_pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      whisk_servo.write(whisk_pos);              // tell servo to go to position in variable 'pos'
      delay(2);                       // waits 15 ms for the servo to reach the position
    } 
    delay(200);
    for (whisk_pos = whisk_hold; whisk_pos >= 0; whisk_pos -= 1) { // goes from 180 degrees to 0 degrees
      whisk_servo.write(whisk_pos);              // tell servo to go to position in variable 'pos'
      delay(2);                       // waits 15 ms for the servo to reach the position
    } 
    delay(200); 
  } 
  delay(5000); 



  //milk 
  Serial.println("milk"); 
  for(int pos = 130; pos>25; pos--){
    milk_servo.write(pos);
    delay(10); 
  }
  delay(15000);
  for(int pos = 25; pos<130; pos++){
    milk_servo.write(pos);
    delay(10); 
  }
  delay(5000);  

  Serial.println("finished!"); 
} 

void loop() { 
  

}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
