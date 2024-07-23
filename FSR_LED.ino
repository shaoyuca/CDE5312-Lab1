/*
 * This example reads in a force-sensitive resistor (FSR) value from A1 and sets the brightness of an LED (Pin 2). 
 * It will print raw sensor value (0-1023) and LED brightness level (0-255)
 * By Shaoyu Cai
 *
 */

const int OUTPUT_LED_PIN = 2;
const int INPUT_FSR_PIN = A1;
const int DELAY_MS = 200; // how often to read from the sensor input

const int MIN_ANALOG_IN = 0; 
const int MAX_ANALOG_IN = 1023; 
const int MAX_ANALOG_OUT = 255;

void setup() {
  pinMode(OUTPUT_LED_PIN, OUTPUT); // LED setup
  pinMode(INPUT_FSR_PIN, INPUT); // FSR setup
  Serial.begin(9600);
}

void loop() {

  // Read the force-sensitive resistor value
  int fsrVal = analogRead(INPUT_FSR_PIN);

  // Remap the value for output: 0-1023 TO 0-255
  int ledVal = map(fsrVal, 0, MAX_ANALOG_IN, 0, MAX_ANALOG_OUT);

  // Print the raw sensor value and the converted led value (e,g., for Serial Plotter)
  Serial.print(fsrVal);
  Serial.print(",");
  Serial.println(ledVal);

  // Write out the LED value. 
  analogWrite(OUTPUT_LED_PIN, ledVal);
  // sesnor input frequency
  delay(DELAY_MS);
}