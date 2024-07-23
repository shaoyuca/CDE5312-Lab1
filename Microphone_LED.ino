/*
 * This example reads in a Microphone value from A1 and light an LED (Pin 2). 
 * To filter some noise
 * We only look at half of the amplitude from MAX_ANALOG_IN/2 to MAX_ANALOG_IN (512-1024) 
 * By Shaoyu Cai
 *
 */

const int LED_OUTPUT_PIN = 2;
const int MIC_INPUT_PIN = A1;

const int MAX_ANALOG_IN = 1023; 
const int MAX_ANALOG_OUT = 255;



void setup() {
  pinMode(LED_OUTPUT_PIN, OUTPUT);
  pinMode(MIC_INPUT_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {  

  // Read in current sound level from microphone
  int soundLevel = analogRead(MIC_INPUT_PIN);

  int ledVal = map(soundLevel, MAX_ANALOG_IN/2, MAX_ANALOG_IN, 0, MAX_ANALOG_OUT);
  Serial.println(ledVal);
  // keep ledVal as positive
  ledVal = constrain(ledVal, 0, MAX_ANALOG_OUT);

  // Set the LED brightness to current waveform amplitude (+100 for easy trigger LED)
  analogWrite(LED_OUTPUT_PIN, ledVal+100);
  //delay(DELAY_MS);


}