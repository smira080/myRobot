#include "../include/led.h"

Led::Led(int pin, int potPin) : ledPin(pin), brightness(MIN_BRIGHTNESS), hasPot(true){
    myPot= new Pot(potPin);
    pinMode(ledPin, OUTPUT);
    analogWrite(ledPin, brightness);
}

void Led::changeBrigtness(){
    brightness = map(myPot->readValue(), 0, 1023, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
    analogWrite(ledPin, brightness);
}

Led::~Led(){
    if (myPot) delete myPot;
}
