#include <EnableInterrupt.h>

#include "buttons.h"
#include "setup.h"
#include "Arduino.h"

int buttons[]={BT1,BT2,BT3,BT4};
int pressedBtnPos; //se non preme nulla

void setupButtons(){
  for(int cont=0;cont<4;cont++){
    pinMode(buttons[cont],INPUT);
    enableInterrupt(buttons[cont],pressedButton,CHANGE); 
  }
}

void pressedButton(){ //ISR
  pressedBtnPos=getPressedButtonPosition(); // set pressed button
  
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
 // pressedBtnPos=-1; 
}
