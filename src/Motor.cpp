#include "../include/Motor.h"

// Constructor: Motor only (no potentiometer)
Motor::Motor(int pin) : servoPin(pin), currAngle(0), myPot(0) {  
    myServo.attach(servoPin);
    myServo.write(currAngle);
}

// Constructor: Motor + Potentiometer
Motor::Motor(int pin, int potPin) : servoPin(pin), currAngle(0), myPot(potPin) {
    myServo.attach(servoPin);
    myServo.write(currAngle);
}

// Move function: Reads potentiometergit  and adjusts servo angle
void Motor::Move() {
    servoAngle = map(myPot.readValue(), 0, 1023, MIN_ANGLE, MAX_ANGLE); 
    myServo.write(servoAngle);
    delay(20);
}
