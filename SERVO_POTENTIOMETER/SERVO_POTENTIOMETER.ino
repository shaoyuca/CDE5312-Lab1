/*
 * This example of using potentiometer to control Servo. 
 * Users can rotate the potentiometer to control Servo (Pin 6).
 * By Shaoyu Cai
 *
 */

#include <Servo.h> 

const int POTENTIOMETER_INPUT_PIN = A0;  
const int SERVO_OUTPUT_PIN = 6;
const int MAX_ANALOG_VAL = 1023;

Servo myServo; 
 
void setup() 
{ 
  myServo.attach(SERVO_OUTPUT_PIN);  
} 
 
void loop() 
{ 

  int potVal = analogRead(POTENTIOMETER_INPUT_PIN); 

  int servoAngle = map(potVal, 0, MAX_ANALOG_VAL, 0, 180);


  myServo.write(servoAngle);  
} 