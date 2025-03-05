#ifndef MOTOR_CLASS
#define MOTOR_CLASS

#include <Arduino.h>
#include <Servo.h>
#include "Pot.h"  // Ensure filename matches case

#define MIN_ANGLE 0
#define MAX_ANGLE 180

class Motor {
private:
    int servoPin;
    Servo myServo;
    int currAngle;
    int servoAngle;
    Pot myPot;

public:
    // Constructor for motor only (no potentiometer)
    Motor(int pin);

    // Constructor for motor with potentiometer
    Motor(int servoPin, int potPin);

    void Move();
};

#endif

