#include "../include/Motor.h"

// Constructor: Motor only (no potentiometer)
Motor::Motor(int pin) : servoPin(pin), currAngle(0), myPot(nullptr), hasPot(false) {  
    myServo.attach(servoPin);
    myServo.write(currAngle);
}

// Constructor: Motor + Potentiometer
Motor::Motor(int pin, int potPin) : servoPin(pin), currAngle(0), hasPot(true) {
    myServo.attach(servoPin);
    myServo.write(currAngle);
    myPot = new Pot(potPin); // Dynamically allocate Pot instance
}

// Move function: Reads potentiometer and adjusts servo angle
void Motor::Move() {
    if (hasPot && myPot) {
        servoAngle = map(myPot->readValue(), 0, 1023, MIN_ANGLE, MAX_ANGLE);
    } else {
        servoAngle = MIN_ANGLE; // Default position if no potentiometer
    }
    myServo.write(servoAngle);
}

// Destructor (to avoid memory leak)
Motor::~Motor() {
    if (hasPot && myPot) {
        delete myPot;
    }
}
