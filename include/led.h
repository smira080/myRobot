#ifndef _LED_CLASS
#define _LED_CLASS

#include "Pot.h"


#define MIN_BRIGHTNESS 0
#define MAX_BRIGHTNESS 255

class Led{
    private:
        int ledPin;
        int brightness;
        Pot* myPot;
    public:
        Led (int, int);
        ~Led();

        void changeBrigtness();

};


#endif