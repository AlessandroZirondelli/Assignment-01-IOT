#include "Arduino.h"
#include "timer_game.h"
#include "pot.h"
unsigned long oldTimePulsing;
unsigned long oldTimeSleeping;
unsigned int speed_blinking;

unsigned long oldTimeBlinking;
unsigned long T1;
unsigned long T2;
unsigned long oldTimeWaitingInput; //time when ball is stopped on the led 
unsigned long oldTimeLastPos; 

unsigned long oldTimeNotBouncing;
unsigned long oldTimeRestart;


void initTimerGame(){
  oldTimePulsing=millis();
  oldTimeSleeping=millis();
  oldTimeNotBouncing = millis();
  unsigned long  seed = millis();
  randomSeed(seed);
  T1 = random(2000,10000);
  T2 = 10000; //user has 10 seconds to press the button
}

bool can(unsigned long *oldTime, unsigned long comparator){
  unsigned long currentTime=millis();
  if((currentTime-(*oldTime)) >= comparator){
    *oldTime = currentTime;
    return true;
  }
  return false;
}

bool canPulsing(){
  return can(&oldTimePulsing,SPEED_PULSING);

}

bool canSleeping(){
  return can(&oldTimeSleeping,T0);
}

bool canBlinking(){
  return can(&oldTimeBlinking,speed_blinking );
}

bool canWaitingInput(){ // if we can switch to wainting input phase, where led is stopped
  return can(&oldTimeWaitingInput, T1);
}

bool timeOut(){ // checks T2
  unsigned long currentTimeLastPos= millis(); 
  if(currentTimeLastPos - oldTimeLastPos > T2){
    return true;
  }
  return false;
}

bool notBouncing(){
  return can(&oldTimeNotBouncing, BOUNCING_TIME);
}
bool canRestart(){
  return can(&oldTimeRestart, WAIT_END_TIME);
  
}
