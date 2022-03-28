/* 
#Assignment 01

Authors:
Arianna Pagano
Lorenzo Sansone
Alessandro Zirondelli

Date:
30/03/2022

*/
#include <avr/sleep.h>
#include "TimerOne.h"

#include "setup.h"
#include "leds.h"
#include "buttons.h"
#include "status_game.h"


void setup() {
  Serial.begin(9600);
  setupButtons();
  setupLed();
  game_status = STATUS_INIT; 
}

void loop() {
  switch(game_status){
    case STATUS_INIT:
      statusInit();
      break;
      
    case STATUS_PRESTART:
      statusPreStart();
      break;

    case STATUS_GAMING_SET:
      statusGamingSet();
      break;
      
    case STATUS_BLINKING:
      statusGaming();
      break;
      
    case STATUS_WAITINGINPUT:
      statusWaitingInput();
      break;
      
    case STATUS_GAMEOVER:
      statusGameOver();
      break;
  }
  
}
