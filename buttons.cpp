#include <EnableInterrupt.h>

#include "buttons.h"
#include "setup.h"
#include "Arduino.h"

int buttons[]={BT1,BT2,BT3,BT4};

void setupButtons(){
  for(int cont=0;cont<4;cont++){
    pinMode(buttons[cont],INPUT);
    enableInterrupt(buttons[cont],pressedButton,CHANGE); 
  }
}

void pressedButton(){
  
}
