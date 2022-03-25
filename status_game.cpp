#include "status_game.h"
#include "leds.h"
#include "Arduino.h"
#include "timer_game.h"
#include "buttons.h"
#include "setup.h"
#include <avr/sleep.h>
#include <avr/power.h>
#include "pot.h"
#include "leds.h"
int game_status;
int score;

void statusInit(){
  initLed();
  initButtons();
  initTimerGame();
  initBlinking();
  score=0;
  Serial.println("Welcome to the Catch the Bouncing Led Ball Game. Press Key T1 to Start");
  Serial.flush();
  game_status=STATUS_PRESTART;
}

void sleeping(){
 if(canSleeping()){
      analogWrite(LS,0);
      set_sleep_mode(SLEEP_MODE_PWR_DOWN);
      sleep_enable();
      sleep_mode();
      sleep_disable();
      game_status=STATUS_INIT;      
  }
}
void startGame(){
  noInterrupts();
  int currentBtnPos = pressedBtnPos;
  interrupts();
  if(currentBtnPos==0 && game_status==STATUS_PRESTART){ // if BTN1 is pressed
     calculateFactorF();
     game_status=STATUS_GAMING_SET;
     analogWrite(LS,0);
  }
}
void statusPreStart(){
  pulsingLed();
 
  sleeping();
  startGame();
  
}
void statusGaming(){
  blinkingLeds();
}

void statusGamingSet(){
  speed_blinking = speed_blinking - (speed_blinking * (factor_F/100));
  T2 = T2 - (T2 * (factor_F/100));
  oldTimeWaitingInput = millis();
  noInterrupts();
  pressedBtnPos = -1;
  interrupts();
  game_status=STATUS_BLINKING;
}

bool isCorrectButton(){
  
  noInterrupts();
  int currentPressedButton =  pressedBtnPos ; 
  interrupts();
  return  actualPos == currentPressedButton; 
  
  
}

void statusWaitingInput(){
  if(!timeOut() && isCorrectButton()){ // se il tempo non è scaduto
    score++;
    Serial.print("New point! Score: ");
    Serial.println(score);
    Serial.flush();
    game_status=STATUS_GAMING_SET;
  }
  else if(timeOut()){
    oldTimeRestart = millis();
    game_status=STATUS_GAMEOVER;  
    Serial.print("Game Over. Final Score:");  
    Serial.println(score);
    Serial.flush();
    initLed();
  }
}

void statusGameOver(){
  
  if(canRestart()){
    game_status=STATUS_INIT;
  }
  
}
