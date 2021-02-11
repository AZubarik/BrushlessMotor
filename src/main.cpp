#include <Arduino.h>
#include <Servo.h>

Servo motor;

const int EngineTumbler = 8;
int SmoothStart;

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(7, LOW);         // GND ADC
  digitalWrite(11, HIGH);       // VCC ADC
  digitalWrite(12, LOW);        // GND EngineTumbler
  
  pinMode(13, OUTPUT);
  pinMode(EngineTumbler, INPUT_PULLUP);

  motor.attach(2, 800, 2300);
  /*motor.writeMicroseconds(2300);
  delay(2000);
  motor.writeMicroseconds(800);
  delay(5000);*/
}

void loop() {
  int buttonState = digitalRead(EngineTumbler);
    if (buttonState) {

      int val = map(analogRead(0), 0, 1023, 1150, 1250);
      val = constrain (val, 1150, 1220);

      motor.attached();
      motor.writeMicroseconds(val);
      Serial.println(val);
      delay(200);
      }

    else {
      SmoothStart = 25;
      motor.writeMicroseconds(800);
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
      } 
  }