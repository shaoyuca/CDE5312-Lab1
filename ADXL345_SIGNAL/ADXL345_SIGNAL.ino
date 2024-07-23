#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

float X_out, Y_out, Z_out;  // Outputs

void setup() 
{
   Serial.begin(9600);  

   if(!accel.begin())
   {
      Serial.println("No ADXL345 sensor detected.");
      while(1);
   }
}

void loop() 
{
   sensors_event_t event; 
   accel.getEvent(&event);
   X_out = event.acceleration.x;
   Y_out = event.acceleration.y;
   Z_out = event.acceleration.z;

   // print acceleration data
   Serial.print("X:"); 
   Serial.print(X_out); 
   Serial.print(" Y:"); 
   Serial.print(Y_out); 
   Serial.print(" Z:"); 
   Serial.println(Z_out); 
 
   delay(200);
}