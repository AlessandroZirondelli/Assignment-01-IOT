#include <avr/sleep.h>
#include "Arduino.h"
void sleepGame(){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
}

float randomT1(){
  randomSeed(111);
  return random(5,10);
}
