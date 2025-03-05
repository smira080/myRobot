#include "../include/led.h"

Led::Led(int pin, int potPin) : ledPin(pin){
    Pot* temp = new Pot(ledPin);
    myPot = temp;
    delete temp;
    pinMode(ledPin, OUTPUT);
    brightness = MIN_BRIGHTNESS;
}

void Led::changeBrigtness(){
    brightness = map(myPot->readValue(), 0, 1023, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
    analogWrite(ledPin, brightness);
    delay (20);
}

Led::~Led(){
    if (myPot) delete myPot;
}

