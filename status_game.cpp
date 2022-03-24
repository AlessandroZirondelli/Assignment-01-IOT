#include "status_game.h"
#include "leds.h"
#include "Arduino.h"
#include "timer_game.h"
#include "buttons.h"
#include "setup.h"
#include <avr/sleep.h>
#include <avr/power.h>

int game_status;

void statusInit(){
  initLed();
  initButtons();
  initTimerGame();
  Serial.print("oldTimeSleeping");
  Serial.println(oldTimeSleeping);
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
      game_status=STATUS_INIT;      
  }
}

void statusPreStart(){
  pulsingLed();
  sleeping();
}
