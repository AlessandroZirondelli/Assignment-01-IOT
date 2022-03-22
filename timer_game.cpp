#include "Arduino.h"
#include "timer_game.h"
//unsigned long oldTimePulsing;
//unsigned long oldTimeSleeping;



void initTimerGame(){
//  oldTimePulsing=0;
  //oldTimeSleeping=0;
}

bool canPulsing(){
 /* 
  unsigned long currentTimePulsing = millis();
  Serial.print("currentPulsing");
  Serial.println(currentTimePulsing);
  Serial.print("oldPulsing");
  Serial.println(oldTimePulsing);
  if (currentTimePulsing - oldTimePulsing >= SPEED_PULSING) {//gestisce ogni quanto incrementare/decrementare il fading
    oldTimePulsing = currentTimePulsing;
    return true;
  }
  return false;*/
}
/*
bool canSleeping(){
  unsigned long currentTimeSleeping = millis();
  Serial.print("currentSleeping");
  Serial.println(currentTimeSleeping);
  Serial.print("oldSleeping");
  Serial.println(oldTimeSleeping);
  if (currentTimeSleeping - oldTimeSleeping >= 500000) {
    oldTimeSleeping = currentTimeSleeping;
    return true;
  }
  return false;
}*/
