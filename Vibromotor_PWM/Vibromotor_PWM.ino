/*
 * This example of using PWM to control vibromotor. 
 * Users can input 0-255 through serial input to control vibromotor (Pin 3).
 * By Shaoyu Cai
 *
 */

int viboPin = 3; 
int pwm_value = 0;

void setup() { 
   Serial.begin(9600);
   pinMode(viboPin, OUTPUT);
}

void loop(){
  Serial.println("Please input a strength value within 0-255: ");

  // detect serial input
  while(Serial.available() == 0){};
  // string to int for PWM 
  pwm_value = Serial.readString().toInt();

  if (pwm_value >= 0 && pwm_value <= 255){
    analogWrite(viboPin, pwm_value);
    Serial.print("Strength: ");
    Serial.println(pwm_value);
  }
  else {
    Serial.println("Invalid input!");
  }
}
