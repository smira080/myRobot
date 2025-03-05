#include <Arduino.h>
#include "../include/Motor.h"
#include "../include/Pot.h"

#define SERVO_PIN 10
#define POT_PIN A0

Motor motor1(SERVO_PIN, POT_PIN);

void setup() {
    Serial.begin(9600);
    delay(1000);  // Allow time for Serial Monitor to start
}

void loop() {
    motor1.Move();
    delay(500);  // Delay to slow down updates
}


// #include <Arduino.h>
// #include <Servo.h>

// Servo myServo;
// #define SERVO_PIN 10

// void setup() {
//     Serial.begin(9600);
//     myServo.attach(SERVO_PIN);
// }

// void loop() {
//     Serial.println("Moving to 0°");
//     myServo.write(0);
//     delay(1000);

//     Serial.println("Moving to 90°");
//     myServo.write(90);
//     delay(1000);

//     Serial.println("Moving to 180°");
//     myServo.write(180);
//     delay(1000);
// }
