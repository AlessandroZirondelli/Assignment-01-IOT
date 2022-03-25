#include "Arduino.h"
#include "timer_game.h"
#include "pot.h"
unsigned long oldTimePulsing;
unsigned long oldTimeSleeping;
unsigned int speed_blinking;
unsigned long currentTimeSleeping; //forse da togliere, nel senso che deve essere locale

unsigned long oldTimeBlinking;
unsigned long T1;
unsigned long T2;
unsigned long oldTimeWaitingInput; //time when ball is stopped on the led 
unsigned long oldTimeLastPos; 

void initTimerGame(){
  oldTimePulsing=millis();
  oldTimeSleeping=millis();
  unsigned long  seed = millis();
  randomSeed(seed);
  T1 = random(2000,10000);
  T2 = 10000; //user has 10 seconds to press the button
  //Serial.println(analogRead(3));
  //Serial.println(T1);
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

bool canWaitingInput(){ // se possiamo passare dalla fase di blinking alla fase di LED fermo
  unsigned long currentTimeWaitingInput = millis();
  if (currentTimeWaitingInput - oldTimeWaitingInput >= T1) {
    oldTimeWaitingInput = currentTimeWaitingInput;
    
    return true;
  }
  return false;
}

bool timeOut(){ // tempo T2
  unsigned long currentTimeLastPos= millis(); 
  if(currentTimeLastPos - oldTimeLastPos > T2){
    Serial.print("diff:");
    Serial.println(currentTimeLastPos - oldTimeLastPos);

    Serial.print("curremt :");
    Serial.println(currentTimeLastPos);

    
    Serial.print("oldTimeLastPos:");
    Serial.println(oldTimeLastPos);

    Serial.print("T2:");
    Serial.println(T2);
    
    Serial.print("T1:");
    Serial.println(T1);

    Serial.print("Speed:");
    Serial.println(speed_blinking);
    return true;
  }
  return false;
}
