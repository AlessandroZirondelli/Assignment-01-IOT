#include "status_game.h"
#include "leds.h"
#include "Arduino.h"

int game_status;


void statusInit(){
  initLed();
  Serial.println("Welcome to the Catch the Bouncing Led Ball Game. Press Key T1 to Start");
  game_status=STATUS_PRESTART;
}

void statusPreStart(){
  pulsingLed();
}
