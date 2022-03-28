#ifndef LEDS
#define LEDS 

#define NUM_LED 4
#include "Arduino.h"

extern byte actualPos;
void initLed();
void setupLed();

void pulsingLed();
void blinkingLeds();
void initBlinking();


#endif
