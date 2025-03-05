#include <Arduino.h>
#include "../include/Motor.h"
#include "../include/Pot.h"


#define servoPin 10
#define potPin A0

Motor motor1(servoPin, potPin);

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  motor1.Move();

  // Debugging: Print potentiometer value and corresponding servo angle
  Serial.print("Potentiometer Value: ");
  Serial.print(analogRead(potPin));
  Serial.print(" | Servo Angle: ");
  Serial.println(map(analogRead(potPin), 0, 1023, 0, 180));

  delay(100);  // Small delay to avoid excessive updates
}