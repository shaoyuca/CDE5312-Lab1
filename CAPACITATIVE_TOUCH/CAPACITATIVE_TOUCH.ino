// A simple example for capacitative touch sensing
// Conneted pins: 9 & 8, pin 8 is sensor pin (touch surface connected)
// A 1M resistor should be prepared

#include <CapacitiveSensor.h>

// Define the pins
CapacitiveSensor sensor = CapacitiveSensor(9,8);  // 1M resistor between pins 9 & 8, pin 8 is sensor pin

void setup() {
  Serial.begin(9600);
}

void loop() {
  long measurement =  sensor.capacitiveSensor(30);
  
  Serial.println(measurement);
  delay(10);
}
