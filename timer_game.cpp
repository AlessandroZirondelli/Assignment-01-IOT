#include "Arduino.h"
#include "timer_game.h"
unsigned long oldTimePulsing;
unsigned long oldTimeSleeping;

unsigned long currentTimeSleeping; //forse da togliere, nel senso che deve essere locale

unsigned long oldTimeBlinking;

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

bool canBlinking(){
  unsigned long currentTimeBlinking = millis();
  
  if (currentTimeBlinking - oldTimeBlinking >= speed_blinking * (factor_F/100)) { //deve esseree moltiplicato speedblinking per %
    oldTimeBlinking = currentTimeBlinking;
    return true;
  }
  return false;
}
