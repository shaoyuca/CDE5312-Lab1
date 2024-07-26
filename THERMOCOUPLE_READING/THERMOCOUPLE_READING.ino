/*
 * This example of ureading temperature from Thermocouple through max6675. 
 *
 */

#include "max6675.h"

// Define the Arduino pins, the MAX6675 module is connected to
int SO_PIN = 10;  // Serail Out (SO) pin
int CS_PIN = 11;  // Chip Select (CS) pin
int SCK_PIN = 12; // Clock (SCK) pin

// Create an instance of the MAX6675 class with the specified pins
MAX6675 thermocouple(SCK_PIN, CS_PIN, SO_PIN);

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  // Read the current temperature and print it to the serial monitor

  // Read the temperature in Celsius
  Serial.print("Temperature:");
  // the reading output number
  Serial.print(thermocouple.readCelsius());
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.println("C  |  ");
  // reading frequency >= 200 ms
  delay(200);
}
