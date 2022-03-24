#include "Arduino.h"
#include "timer_game.h"
#include "pot.h"
unsigned long oldTimePulsing;
unsigned long oldTimeSleeping;
unsigned int speed_blinking;
unsigned long currentTimeSleeping; //forse da togliere, nel senso che deve essere locale

unsigned long oldTimeBlinking;
unsigned int T1;
unsigned long oldTimeWaitingInput; //time when ball is stopped on the led 

void initTimerGame(){
  oldTimePulsing=millis();
  oldTimeSleeping=millis();
  //T1 = random(2000,5000);
  T1 = 5000;
  Serial.print("Random");
  Serial.println(T1);
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
  if (currentTimeBlinking - oldTimeBlinking >= speed_blinking ) { //deve esseree moltiplicato speedblinking per %
    oldTimeBlinking = currentTimeBlinking;
    return true;
  }
  return false;
}

bool canWaitingInput(){
  unsigned long currentTimeWaitingInput = millis();
  if (currentTimeWaitingInput - oldTimeWaitingInput >= T1) {
    oldTimeWaitingInput = currentTimeWaitingInput;
    
    return true;
  }
  return false;
}
