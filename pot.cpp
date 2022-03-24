#include "pot.h"
#include "Arduino.h" 
#include "setup.h"

float  factor_F;
int getDifficult(){
  int  readedPot =  analogRead(POTPIN);
  return map(readedPot,0,1024,1,9);
}

void calculateFactorF(){ // choice diffult: max diffucult = calculatedPercentage : 50(max percentage)
  float difficult = getDifficult();
  factor_F = (difficult * 50)/8;
  
}
