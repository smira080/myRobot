#ifndef MOTOR_CLASS
#define MOTOR_CLASS

#include <Arduino.h>
#include <Servo.h>
#include "Pot.h"

#define MIN_ANGLE 0
#define MAX_ANGLE 180

// On boards other than the Mega, use of the library disables 
// analogWrite() (PWM) functionality on pins 9 and 10, whether
// or not there is a Servo on  those pins. On the Mega, up to 
// 12 servos can be used without interfering with PWM 
// functionality; use of 12 to 23 motors will disable PWM on pins
//  11 and 12.

class Motor {
private:
    int servoPin;
    Servo *myServo;
    int servoAngle;
    Pot* myPot;  // Use pointer to handle optional potentiometer
    bool hasPot; // Flag to track if potentiometer is present
    //bool hasSenor; // Checks to see if sensor is present

public:
    ~Motor();

    // Constructor for motor with potentiometer
    Motor(int servoPin, int potPin);

    void Move();
    
};

#endif
