#ifndef POT_CLASS
#define POT_CLASS

#include <Arduino.h>

class Pot {
private:
    int potPin;

public:
    Pot(int pin);  // Constructor
    int readValue();
};

#endif
