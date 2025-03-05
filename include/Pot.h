#ifndef POTENTIOMETER_CLASS
#define POTENTIOMETER_CLASS

#include <Arduino.h>

class Pot {
    private:
        int potPin;
        int potValue;
    
    public:
        Pot(int pin);  // Constructor (no empty constructor needed)
        int readValue();
        void attach(int pin);
};

#endif
