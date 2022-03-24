#include "status_game.h"
#include "leds.h"
#include "Arduino.h"
#include "timer_game.h"
#include "buttons.h"
#include "setup.h"
#include <avr/sleep.h>
#include <avr/power.h>
#include "pot.h"

int game_status;

void statusInit(){
  initLed();
  initButtons();
  initTimerGame();
  
  Serial.print("buttonPressed");
  Serial.println(pressedBtnPos);
  Serial.println("Welcome to the Catch the Bouncing Led Ball Game. Press Key T1 to Start");
  game_status=STATUS_PRESTART;
}

void sleeping(){
 if(canSleeping()){
      analogWrite(LS,0);
      set_sleep_mode(SLEEP_MODE_PWR_DOWN);
      sleep_enable();
      sleep_mode();
      /** The program will continue from here. **/
      Serial.println("WAKE UP");
      /* First thing to do is disable sleep. */
      sleep_disable();
      //pressedBtnPos=-1;
      game_status=STATUS_INIT;      
  }
}
void startGame(){
  if(pressedBtnPos==0 && game_status==STATUS_PRESTART){ // if BTN1 is pressed
     calculateFactorF();
     game_status=STATUS_GAMING;
     analogWrite(LS,0);
  }
}
void statusPreStart(){
  pulsingLed();
 
  sleeping();
   startGame();
  
}
void statusGaming(){
  
}
