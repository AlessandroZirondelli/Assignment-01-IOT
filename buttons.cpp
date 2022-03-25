#include <EnableInterrupt.h>

#include "buttons.h"
#include "setup.h"
#include "Arduino.h"
#include "status_game.h"
#include "timer_game.h"

int buttons[]={BT1,BT2,BT3,BT4};
int pressedBtnPos; //se non preme nulla
int status_game;

void setupButtons(){
  for(int cont=0;cont<4;cont++){
    pinMode(buttons[cont],INPUT);
    enableInterrupt(buttons[cont],pressedButton,CHANGE); 
  }
}

void pressedButton(){ //ISR
  
  if(notBouncing()){
    if(game_status==STATUS_WAITINGINPUT || game_status==STATUS_PRESTART ){
      pressedBtnPos=getPressedButtonPosition(); // set pressed button
    }
  }
  
  
}

int getPressedButtonPosition(){ 
  for(int cont=0;cont<4;cont++){
    if(digitalRead(buttons[cont])==HIGH){
      return cont;
    }
  }
  return -1;
}


void initButtons(){
  noInterrupts();
 pressedBtnPos=-1; 
 interrupts();
}
