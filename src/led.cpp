#include "../include/led.h"

Led::Led(int potPin) {
    
}

Led::~Led(){
    if (myPot) delete myPot;
}

