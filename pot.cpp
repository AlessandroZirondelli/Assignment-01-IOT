#include "pot.h"
#include "Arduino.h" 
#include "setup.h"
int getDifficult(){
  int  readedPot =  analogRead(POTPIN);
  return map(readedPot,0,1024,1,9);
}
