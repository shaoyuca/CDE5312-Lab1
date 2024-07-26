/*
 * This example of using PWM to control pump/TEC. 
 * Users can input 0-255 through serial input to control pump/TEC (Pin 4/5, pwm pin 9).
 * By Shaoyu Cai
 *
 */

#define enA 9 // pwm pin
#define in1 4
#define in2 5

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // initialize motor 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  Serial.println("Please input a strength value within 0-255: ");
  while(Serial.available() == 0){};
  int pwm_value = Serial.readString().toInt();
  if (pwm_value >= 0 && pwm_value <= 255){
    analogWrite(enA, pwm_value);
    Serial.print("Strength: ");
    Serial.println(pwm_value);

    // drive the pump/peltier
    // If peliter, in1-HIGH, in2-LOW -> Hot, in1-LOW, in2-HIGH -> Cold
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(20);
  }
  else {
    Serial.println("Invalid input!");
  }
}
