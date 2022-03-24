#include "leds.h"
#include "setup.h"
#include "Arduino.h"
#include "timer_game.h"
#include "status_game.h"

//unsigned long oldTimePulsing;

int fadeAmount=5;
int currIntensity;
int leds[]={L1,L2,L3,L4};
int dirBlinking = 1;
int nextPos = 0;
int actualPos = 0;
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
  fadeAmount = 5;
  
}


void pulsingLed(){
  
  if (canPulsing()) {//gestisce ogni quanto incrementare/decrementare il fading
    analogWrite(LS, currIntensity);
    currIntensity = currIntensity + fadeAmount;
    if (currIntensity <= 0 || currIntensity >= 255) {
      fadeAmount = -fadeAmount ;
    }
  }
}
void initBlinking(){
  speed_blinking = 500;
  nextPos = 0;
  dirBlinking = 1;
}
void blinkingLeds(){

  if(!canWaitingInput()){
    if(canBlinking()){
      actualPos = nextPos;
      digitalWrite(leds[nextPos],HIGH);
      if(dirBlinking == 1 && nextPos == 0){ //
        digitalWrite(leds[1],LOW);
      }
      else if(dirBlinking == -1 && nextPos == 3){
        digitalWrite(leds[2],LOW);
      }
      else{
        digitalWrite(leds[nextPos-dirBlinking],LOW);
      }
        nextPos += dirBlinking;
      if (nextPos <= 0 || nextPos >= 3){
        dirBlinking =- dirBlinking; 
      }
    } 
  } else{ 
    game_status = STATUS_WAITINGINPUT;
    Serial.print("Last pos led");
    Serial.println(actualPos);
  }
  
}
