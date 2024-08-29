/*
 * This example demonstrates PID control for Peliters (cooling)
 * input - Themocouple reading temperature
 * SetPoint - 30 
 * output - PWM for Peliter output
 * Usage: Serial input A, work; Serial input S, stop;
 * By Shaoyu Cai
 *
 */

#include <PID_v2.h>
#include <max6675.h>

// for thermocouple control
int SO_PIN = 10;  // Serail Out (SO) pin
int CS_PIN = 11;  // Chip Select (CS) pin
int SCK_PIN = 12; // Clock (SCK) pin

MAX6675 thermocouple(SCK_PIN, CS_PIN, SO_PIN);

#define PIN_INPUT 0
#define PIN_OUTPUT 3

// for tec control
#define enA 9 //pwm pin
#define in1 4
#define in2 5
int pwmOutput;


float incomingByte = 0; // 
int wsg = 0; // 

double Setpoint, Input, Output;

// Define Initial PID Terms
double Kp_1 = 10;
double Ki_1 = 6;
double Kd_1 = 1;

//Specify the initial tuning parameters
//PID_v2 myPID(Kp_1, Ki_1, Kd_1, PID::Direct); // for heating
PID_v2 myPID(Kp_1, Ki_1, Kd_1, PID::Reverse); // for cooling
// open serial input
String received;

void setup()
{
  Serial.begin(9600); 
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  Setpoint = 30;         // set the setpoint tem as 30 degree
  float temperature_reading = thermocouple.readCelsius();
  Input = temperature_reading;
  myPID.Start(Input, 0, Setpoint); //setpoint
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) { 
    received = Serial.read();
    incomingByte = received.toInt();

    if (incomingByte == 'A')
    {
      while(1){   
      //float pressure = (voltage - 2.75) * 50; // -100~100 kpa
      //float pressure = voltage * 107.0/4.0 - 40 - 107.0/8.0; // -40~67 kpa
      //delay(200);
      //Serial.print("Presure_value = ");  
      //Serial.println(pressure);

      float temperature_reading = thermocouple.readCelsius();
      Serial.println(temperature_reading);
      delay(200);
      
      Input = temperature_reading;

      const double output = myPID.Run(Input);

      Serial.print("PWM_OUT = ");                         
      Serial.println(output);

      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);

      //digitalWrite(in1, LOW);
      //digitalWrite(in2, HIGH);
      analogWrite(enA, output);

      // stop
      wsg = Serial.read();             
      if (wsg == 'S')
        break;     
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

}

float temperature_reading = thermocouple.readCelsius();
Serial.println(temperature_reading);
delay(200);

if (incomingByte == 'S'){
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
  } 
}


