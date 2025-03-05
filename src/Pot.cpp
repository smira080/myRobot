#include "../include/Pot.h"

Pot::Pot(int pin) {
    potPin = pin;
    pinMode(potPin, INPUT);
}

int Pot::readValue() {
    potValue = analogRead(potPin);
    delay(20);  // Debounce delay (optional)
    return potValue;  // Ensure it returns the value
}

void Pot::attach(int pin) {
    potPin = pin;
    pinMode(potPin, INPUT);  // Reinitialize the pin
}
