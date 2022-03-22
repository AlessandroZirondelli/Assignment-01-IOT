#include "leds.h"
#include "setup.h"
#include "Arduino.h"
#include "timer_game.h"

//unsigned long oldTimePulsing;

int fadeAmount=5;
int currIntensity;
int leds[]={L1,L2,L3,L4};

void setupLed(){
  pinMode(L1,OUTPUT); 
  pinMode(L2,OUTPUT); 
  pinMode(L3,OUTPUT); 
  pinMode(L4,OUTPUT);  
  pinMode(LS,OUTPUT); 
}
void initLed(){
  for(int cont = 0; cont < NUM_LED; cont++){
    digitalWrite(leds[cont],LOW);
  }
  analogWrite(LS,0);
  currIntensity=0;
}


void pulsingLed(){
  if (canPulsing()) {//gestisce ogni quanto incrementare/decrementare il fading
    analogWrite(LS, currIntensity);
    currIntensity = currIntensity + fadeAmount;
    if (currIntensity == 0 || currIntensity == 255) {
      fadeAmount = -fadeAmount ;
    }
  }
}
