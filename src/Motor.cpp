#include "../include/Motor.h"

#define DEAD_ZONE 3



Motor::Motor(int pin, int potPin) : servoPin(pin), servoAngle(0), hasPot(true) {
    Serial.println("Initializing Motor...");
    
    myServo = new Servo(); // Allocate memory for Servo object
    myServo->attach(servoPin);
    Serial.println("Servo Attached!");

    myServo->write(servoAngle);
    myPot = new Pot(potPin);
}

// void Motor::Move() {
//     if (!myServo) return;

//     myServo->detach();  // Detach first
//     delay(10);          // Small delay to stabilize
//     myServo->attach(servoPin);  // Reattach every loop

//     if (hasPot && myPot) {
//         servoAngle = map(myPot->readValue(), 0, 1023, MIN_ANGLE, MAX_ANGLE);
//     } else {
//         servoAngle = MIN_ANGLE;
//     }

//     Serial.print("Moving Servo to: ");
//     Serial.println(servoAngle);

//     myServo->write(servoAngle);
//     delay(100);
// },

void Motor::Move() {
    if (!myServo) return;

    if (!myServo->attached()) {
        Serial.println("Reattaching Servo...");
        myServo->attach(servoPin);
        delay(10);
    }

    int newAngle = map(myPot->readValue(), 0, 1023, MIN_ANGLE, MAX_ANGLE);

    if (abs(newAngle - servoAngle) > DEAD_ZONE) {
        servoAngle = newAngle;
        Serial.print("Moving Servo to: ");
        Serial.println(servoAngle);
        myServo->write(servoAngle);
    }

    delay(50);
}

// Destructor (to avoid memory leak)
Motor::~Motor() {
    if (myServo) {
        delete myServo;
        myServo = nullptr;
    }
    if (myPot) {
        delete myPot;
        myPot = nullptr;
    }
}

