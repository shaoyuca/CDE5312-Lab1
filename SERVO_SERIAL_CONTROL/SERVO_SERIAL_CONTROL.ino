/*
 * This example of using PWM to control Servo. 
 * Users can input 0-255 through serial input to control Servo (Pin 6).
 * By Shaoyu Cai
 *
 */

 #include <Servo.h> 
// Declare the Servo pin 
int servoPin = 6; 
int degree_value = 0;
// Create a servo object: name - myServo
Servo myServo; 

void setup() { 
   Serial.begin(9600);
   // attch servo
   myServo.attach(servoPin); 
   myServo.write(0); // initialize the degree
}

void loop(){ 
  Serial.println("Please input a strength value within 0-255: ");

  // detect serial input
  while(Serial.available() == 0){};
  // string to int for PWM 
  degree_value = Serial.readString().toInt();

  if (degree_value >= 0 && degree_value <= 180){ //degree limits: 0-180
    myServo.write(degree_value);
    Serial.print("Turn degree to: ");
    Serial.println(degree_value);
  }
  else {
    Serial.println("Invalid degree!");
  }
}