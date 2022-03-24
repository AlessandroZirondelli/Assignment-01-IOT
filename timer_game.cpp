#include "Arduino.h"
#include "timer_game.h"
unsigned long oldTimePulsing;
unsigned long oldTimeSleeping;

unsigned long currentTimeSleeping;

void initTimerGame(){
  oldTimePulsing=millis();
  oldTimeSleeping=millis();
}

bool canPulsing(){
  unsigned long currentTimePulsing = millis();
  if ((currentTimePulsing - oldTimePulsing) >= SPEED_PULSING) {//gestisce ogni quanto incrementare/decrementare il fading
    oldTimePulsing = currentTimePulsing;
    return true;
  }
  return false;

}

bool canSleeping(){
  unsigned long currentTimeSleeping = millis();
  if (currentTimeSleeping - oldTimeSleeping >= T0) {
    oldTimeSleeping = currentTimeSleeping;
    
    return true;
  }
  return false;
}
