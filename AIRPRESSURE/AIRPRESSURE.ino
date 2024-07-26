/*
 * This example of using XGZP6847A (100KPa) to obtain the air pressure value. 
 * Using A1 pin.
 * By Shaoyu Cai
 *
 */

int sensorValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT);
}

void loop() {
  sensorValue = analogRead(A1);
  
  // obtain the voltage of the sensor analog input
  float voltage = sensorValue * (5.0 / 1023.0);

  // convert the voltage value to prerssure value (based on the datasheet for 0-100kpa sensor)
  float pressure = (voltage - 0.5) * 25; 
  Serial.print("Presure_value (KPa) = ");  
  Serial.println(pressure);

  // reading frequency 10 Hz, can be changed
  delay(100);
}
