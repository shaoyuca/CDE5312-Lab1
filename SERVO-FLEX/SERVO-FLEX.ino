/*
 * This example of using Flex/FSR sesnor to control Servo. 
 * Users can bend Flex to control the movemment of Servo (Pin 6).
 * By Shaoyu Cai
 *
 */

#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 6; 
// Create a servo object 

const int INPUT_FSR_PIN = A1;
const int MAX_ANALOG_VAL = 1023;

Servo myServo; 
void setup() { 
   Serial.begin(9600);
   pinMode(INPUT_FSR_PIN, INPUT);
   // We need to attach the servo to the used pin number 
   myServo.attach(servoPin); 
   myServo.write(0); // initialize the degree
}

void loop(){ 
  int fsrVal = analogRead(INPUT_FSR_PIN);

  // Remap the value for output. 
  int degree_value = map(fsrVal, 0, MAX_ANALOG_VAL, 0, 180);
  myServo.write(degree_value);

}
