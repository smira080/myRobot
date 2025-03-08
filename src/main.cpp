#include <Arduino.h>
#include <Servo.h>
#include "../include/Motor.h"
#include "../include/Pot.h"
#include "../include/led.h"

#define SERVO_PIN 10
#define SERVO_PIN2 4
// #define LED_PIN 12
#define POT_PIN A1

Motor myMotor(SERVO_PIN, POT_PIN);
//Motor myMotor2(SERVO_PIN2, POT_PIN);
// Led myLed(LED_PIN, POT_PIN);
// int brightness;

void setup() {
    Serial.begin(9600);
}

void loop() {
    myMotor.Move();
    //myMotor2.Move();
   // myLed.changeBrigtness();
}
