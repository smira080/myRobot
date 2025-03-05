#include "../include/Pot.h"

Pot::Pot(int pin) : potPin(pin) {
    pinMode(potPin, INPUT);
}

int Pot::readValue() {
    return analogRead(potPin);
}
